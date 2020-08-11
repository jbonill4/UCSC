// This will be the object that will contain the Vue attributes
// and be used to initialize it.
let app = {};

// Given an empty app object, initializes it filling its attributes,
// creates a Vue instance, and then initializes the Vue instance.
let init = (app) => {

    // This is the Vue data.
    app.data = {
        user_email: user_email,
        posts: [], // Suggested.
        currentpost: "",
        page: "",
    };

    // Add here the various functions you need.


    // Use this function to reindex the posts, when you get them, and when
    // you add / delete one of them.
    app.reindex = (a) => {
        let idx = 0;
        for (p of a) {
            p._idx = idx++;
            // Add here whatever other attributes should be part of a post.
        }
        return a;
    };

    app.complete = (posts) => {
        posts.map((p) => {
            p.rating = 0; // 0 is neutral, 1 means down, 2 means up
            p.likers = "";
            p.dislikers = "";
            p.likerflag = 0;
            p.dislikerflag = 0;
            p.knownlikers = 0;
        })
    };
    // app.reversePosts = (posts) => {ƒ
    //     posts.reverse();
    // };

    app.add_post = () => {
        //this function is here in case I'd like to add some custom error handling 
        if (app.vue.currentpost.trim().length != 0){
            app.insert_post();
        }
    };

    app.insert_post = () => {
        axios.post(add_post_url, {
            post_text: app.vue.currentpost
        }).then(function (response) {
            app.vue.posts.unshift({
                id: response.data.id,
                post_text: app.vue.currentpost,
                post_author: username,
                user_email: user_email,
                rating: 0,
                likers: "",
                // dislikers: "", 
                likerflag: 0,
                dislikerflag: 0,
                knownlikers: 0,
            });
            app.reindex(app.vue.posts);
            app.unset_theposts();
        });
    };

    app.set_theposts = () => {
        app.vue.page = 'post';
    };

    app.unset_theposts = () => {
        app.vue.page = '';
        app.vue.currentpost = '';
    };

    app.thumbs_up_over = (post_idx) => {
        let p = app.vue.posts[post_idx];
        app.vue.posts[post_idx].likerflag = 1; 
        if(p.knownlikers == 0){ //this caches the likers string, so we dont have to compute it every time
            axios.get(get_likers_url, {params: {"post_id": p.id, "rating": 2}}).then((result) => {
                app.vue.posts[post_idx].likers = result.data.theString;
                app.vue.posts[post_idx].knownlikers = 1;
            });
        } 
    };

    app.thumbs_down_over = (post_idx) => {
        let p = app.vue.posts[post_idx];
        app.vue.posts[post_idx].dislikerflag = 1;
        if(p.knownlikers == 0){ //this caches the likers string, so we dont have to compute it every time
            axios.get(get_likers_url, {params: {"post_id": p.id, "rating": 1}}).then((result) => {
                app.vue.posts[post_idx].likers = result.data.theString;
                app.vue.posts[post_idx].knownlikers = 1;
            });
        }
    };

    app.toggle_thumbs_up = (post_idx) => {
        let p = app.vue.posts[post_idx];
        rating = p.rating;
        if(rating == 2){ //means it's already thumbs up, so it should be set to neutral
            axios.post(set_rating_url, {post_id: p.id, rating: 0}).then(() => {
                app.vue.posts[post_idx].rating = 0;
                app.vue.posts[post_idx].knownlikers = 0;
                app.thumbs_up_over(post_idx);
            });
        }
        else { //means it was either thumbs down or neutral, so we should set it to up 
            axios.post(set_rating_url, {post_id: p.id, rating: 2}).then(() => {
                app.vue.posts[post_idx].rating = 2;
                app.vue.posts[post_idx].knownlikers = 0;
                app.thumbs_up_over(post_idx);
            });
        }
        // app.thumbs_up_over(post_idx);
    };

    app.toggle_thumbs_down = (post_idx) => {
        let p = app.vue.posts[post_idx];
        rating = p.rating;
        if(rating == 1){ //already thumbs down, so should be set to neutral
            axios.post(set_rating_url, {post_id: p.id, rating: 0}).then(() => {
                app.vue.posts[post_idx].rating = 0;
                app.vue.posts[post_idx].knownlikers = 0;
                app.thumbs_down_over(post_idx);
            });
        }
        else {  //either thumbs up or neutral, so we set it to down 
            axios.post(set_rating_url, {post_id: p.id, rating: 1}).then(() => {
                app.vue.posts[post_idx].rating = 1;
                app.vue.posts[post_idx].knownlikers = 0;
                app.thumbs_down_over(post_idx);
            });
        }
    };
    
    app.thumbsup_stop = (post_idx) => {
        app.vue.posts[post_idx].likerflag = 0;
    };

    app.thumbsdown_stop = (post_idx) => {
        app.vue.posts[post_idx].dislikerflag = 0;
    }

    app.delete_post = (post_idx) => {
        let p = app.vue.posts[post_idx];
        axios.post(delete_post_url, {id: p.id}).then(() => {
            app.vue.posts.splice(post_idx, 1);
            app.reindex(app.vue.posts);
        });
    };
    // We form the dictionary of all methods, so we can assign them
    // to the Vue app in a single blow.
    app.methods = {
        add_post: app.add_post,
        set_theposts: app.set_theposts,
        unset_theposts: app.unset_theposts,
        thumbs_up_over: app.thumbs_up_over,
        thumbs_down_over: app.thumbs_down_over,
        toggle_thumbs_up: app.toggle_thumbs_up,
        toggle_thumbs_down: app.toggle_thumbs_down,
        delete_post: app.delete_post,
        thumbsup_stop: app.thumbsup_stop,
        thumbsdown_stop: app.thumbsdown_stop,
    };

    // This creates the Vue instance.
    app.vue = new Vue({
        el: "#vue-target",
        data: app.data,
        methods: app.methods
    });

    // And this initializes it.
    app.init = () => {
        axios.get(get_posts_url).then((result) => {
            let posts = result.data.posts;
            app.reindex(posts);
            app.complete(posts);
            app.vue.posts = posts;
        })
        .then(() => {
            for (let p of app.vue.posts) {
                axios.get(get_rating_url, {params: {"post_id": p.id}})
                    .then((result) => {
                        p.rating = result.data.rating;
                    });
            }
        });
    };

    // Call to the initializer.
    app.init();
};

// This takes the (empty) app object, and initializes it,
// putting all the code i
init(app);
