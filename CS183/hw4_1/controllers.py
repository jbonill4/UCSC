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


url_signer = URLSigner(session)

# Index function
@action('index')
@action.uses('index.html',db, auth.user, session)
def index():
    user_email = auth.current_user.get('email')
    contacts = db(db.contacts.user_email == user_email).select()
    return dict(rows=contacts, s=url_signer)


# Edit a contact
@action('edit_contact/<contactID>', method=['GET', 'POST'])
@action.uses('contact_form.html', session, db)
def edit_contact(contactID=None):
    form = Form(db.contacts,deletable=False,record=contactID, keep_values=True, csrf_session=session, formstyle=FormStyleBulma)
    if form.accepted:
        redirect(URL('index'))
    return dict(form=form)

# Add a contact
@action('add_contact', method=['GET','POST'])
@action.uses('contact_form.html', session)
def add_contact():
	form = Form(db.contacts,csrf_session=session,formstyle=FormStyleBulma)
	if form.accepted:
		redirect(URL('index'))
	return dict(form=form)

# Delete a contact
@action('delete_contact/<contactID>',method=['GET','POST'])
@action.uses('contact_form.html',session,db,url_signer.verify())
def delete_contact(contactID=None):
    db(db.contacts.id == contactID).delete()
    redirect(URL('index'))



