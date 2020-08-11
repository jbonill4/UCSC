"""
This file defines actions, i.e. functions the URLs are mapped into
The @action(path) decorator exposed the function at URL:

    http://127.0.0.1:8000/{app_name}/{path}

If app_name == '_default' then simply

    http://127.0.0.1:8000/{path}

If path == 'index' it can be omitted:

    http://127.0.0.1:8000/

The path follows the bottlepy syntax.

@action.uses('generic.html')  indicates that the action uses the generic.html template
@action.uses(session)         indicates that the action uses the session
@action.uses(db)              indicates that the action uses the db
@action.uses(T)               indicates that the action uses the i18n & pluralization
@action.uses(auth.user)       indicates that the action requires a logged in user
@action.uses(auth)            indicates that the action requires the auth object

session, db, T, auth, and tempates are examples of Fixtures.
Warning: Fixtures MUST be declared with @action.uses({fixtures}) else your app will result in undefined behavior
"""

import uuid

from py4web import action, request, abort, redirect, URL, Field
from py4web.utils.form import Form, FormStyleBulma
from py4web.utils.url_signer import URLSigner

from yatl.helpers import A
from . common import db, session, T, cache, auth, signed_url
from . models import get_user_email

url_signer = URLSigner(session)

# The auth.user below forces login.
@action('index')
@action.uses('index.html', url_signer, auth.user)
def index():
    user = auth.get_user()
    if user is None:
        redirect(URL('auth/login'))
    if auth.current_user.get('first_name') is not None: 
        username = auth.current_user.get('first_name') + " " + auth.current_user.get("last_name")
    else:
        username = None
        redirect(URL('auth/login'))
    return dict(
        # This is an example of a signed URL for the callback.
        get_posts_url = URL('get_posts', signer=url_signer),
        # Add other callbacks here.
        add_post_url = URL('add_post', signer=url_signer),
        delete_post_url= URL('delete_post', signer=url_signer),
        user=user,
        user_email = get_user_email(),
        username =  username,
        get_rating_url = URL('get_rating'),
        set_rating_url = URL('set_rating', signer=url_signer),
        get_likers_url = URL('get_likers')
    )

@action('get_posts')
@action.uses(url_signer.verify(), auth.user)
def get_posts():
    # Complete.
    posts = db(db.post).select().as_list()
    for post in posts:
        r = db(db.auth_user.email == post['user_email']).select().first()
        name = r.first_name + " " + r.last_name if r is not None else "Unknown"
        post["post_author"] = name
    posts.reverse() 
    return dict(posts=posts)

@action('add_post', method="POST")
@action.uses(url_signer.verify(), auth.user, db)
def add_post():
    # print('Something happened')
    id = db.post.insert(
        post_text = request.json.get('post_text')
    )
    return dict(id=id) # You need to fill this in.

@action('delete_post', method="POST")
@action.uses(url_signer.verify(), db)
def delete_post():
    id = request.json.get('id')
    if id is not None:
        db(db.post.id == id).delete()
    return "yayerz"

@action('get_rating')
@action.uses(db, auth.user)
def get_rating():
    post_id = request.params.get('post_id')
    user_email = get_user_email()
    assert post_id is not None 
    rating_entry = db((db.thumb.post_id == post_id) & (db.thumb.user_email == user_email)).select().first()
    rating = rating_entry.rating if rating_entry is not None else 0
    return dict(rating=rating)

@action('set_rating', method='POST')
@action.uses(url_signer.verify(), db, auth.user)
def set_rating():
    post_id = request.json.get('post_id')
    user_email = get_user_email() 
    rating = request.json.get('rating')
    assert post_id is not None and rating is not None 
    db.thumb.update_or_insert( 
        ((db.thumb.post_id == post_id) &  (db.thumb.user_email == user_email)),
        post_id=post_id,
        user_email=user_email,
        rating=rating
    )
    return "horry shet"

@action('get_likers')
@action.uses(db, auth.user)
def get_likers():
    post_id = request.params.get('post_id')
    assert post_id is not None 
    rating_check = request.params.get('rating')
    rating_check = int(rating_check)
    #get likers first
    likers = db((db.thumb.post_id == post_id) & (db.thumb.rating == 2)).select().as_list()
    if len(likers) == 0: 
        theString = ""
    else:
        theString = "Liked by "
        for liker in likers:
            r = db(db.auth_user.email == liker['user_email']).select().first()
            name = r.first_name + " " + r.last_name if r is not None else "Unknown"
            theString = theString + str(name)
            theString = theString + ", "
        theString = theString[:-2]
        theString = theString + ". "
    dislikers = db((db.thumb.post_id == post_id) & (db.thumb.rating == 1)).select().as_list()
    if len(dislikers) > 0:
        theString = theString + "Disliked by "
        for liker in dislikers:
            r = db(db.auth_user.email == liker['user_email']).select().first()
            name = r.first_name + " " + r.last_name if r is not None else "Unknown"
            theString = theString + str(name)
            theString = theString + ", "
        theString = theString[:-2]
        theString = theString + "."
        # if rating_check == 2:
        #     theString = "Liked by "
        # else:
        #     theString = "Disliked by "
        # for liker in likers:
        #     r = db(db.auth_user.email == liker['user_email']).select().first()
        #     name = r.first_name + " " + r.last_name if r is not None else "Unknown"
        #     theString = theString + str(name)
        #     theString = theString + ", "
        # theString = theString[:-2]
    return dict(theString=theString)
# Complete.