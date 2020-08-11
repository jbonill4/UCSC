// This will be the object that will contain the Vue attributes
// and be used to initialize it.
let app = {};

// Given an empty app object, initializes it filling its attributes,
// creates a Vue instance, and then initializes the Vue instance.
let init = (app) => {

    // This is the Vue data.
    app.data = {
        posts: [], // See initialization.
        user_email: user_email
    };

    app.index = (a) => {
        // Adds to the posts all the fields on which the UI relies.
        let i = 0;
        for (let p of a) {
            p._idx = i++;
            // TODO: Only make the user's own posts editable.
            p.editable = (p.email === user_email);                                                  //CHANGED
            p.edit = false;
            p.is_pending = false;
            p.error = false;
            p.original_content = p.content; // Content before an edit.
            p.server_content = p.content; // Content on the server.
        }
        return a;
    };

    app.reindex = () => {
        // Adds to the posts all the fields on which the UI relies.
        let i = 0;
        for (let p of app.vue.posts) {
            p._idx = i++;
        }
    };

    app.do_edit = (post_idx) => {
        // Handler for button that starts the edit.
        // TODO: make sure that no OTHER post is being edited.
        // If so, do nothing.  Otherwise, proceed as below.
        let p = app.vue.posts[post_idx];
        p.edit = (p.email === user_email);
        //app.reindex(app.vue.posts)
        p.is_pending = false;
        
    };

    app.do_cancel = (post_idx) => {
        // Handler for button that cancels the edit.
        let p = app.vue.posts[post_idx];
        if (p.id === null) {
            // If the post has not been saved yet, we delete it.
            app.vue.posts.splice(post_idx, 1);                                            //ADDED
            //app.reindex();                                                                //ADDED
        } else {
            // We go back to before the edit.
            p.edit = false;
            p.is_pending = false;
            p.content = p.original_content;
        }
    }

    app.do_save = (post_idx) => {
        // Handler for "Save edit" button.
        let p = app.vue.posts[post_idx];
        console.log(p.content)
        if (p.content !== p.server_content) {
            p.is_pending = true;
            axios.post(posts_url, {
                content: p.content,
                id: p.id,
                is_reply: p.is_reply,
            }).then((result) => {
                console.log("Received:", result.data);
                // TODO: You are receiving the post id (in case it was inserted),
                // and the content.  You need to set both, and to say that
                // the editing has terminated.

                is_reply = p.is_reply
                //server_content = p.server_content
                //original_content = p.original_content

                if(is_reply === null)
                {
                                                      //ADDED everything below
                    //app.reindex(); //might not needed

                    // if(p.id !== post_idx)
                    // {
                         app.vue.posts.splice(post_idx, 1);
                    // }  
                     

                    let q = 
                    { 
                        id: result.data.id,
                        edit: false,
                        editable: (p.email === user_email),
                        content: result.data.content,
                        server_content: result.data.content,
                        original_content: "",
                        author: author_name,
                        email: user_email,
                        is_reply: null

                    };
                    app.data.posts.splice(post_idx, 0, q)
                    app.reindex(app.vue.posts)
                }
                else{ //reply

                    app.vue.posts.splice(post_idx, 1);

                    let q = 
                    {                                           //ADDED
                        id: result.data.id,
                        edit: false,                                                                   //CHANGED
                        editable: (p.email === user_email),                                                               //CHANGED
                        content: result.data.content,
                        server_content: null,
                        original_content: "",
                        author: author_name,
                        email: user_email,
                        is_reply: p.is_reply,
                    };

                    app.data.posts.splice(post_idx, 0, q)
                    app.reindex(app.vue.posts)

                }

                

            }).catch((error) => {
                //p.is_pending = false;
                console.log("Caught error");
                console.log(error);
                // We stay in edit mode.
            });
        } else {
            // No need to save.
            p.edit = false;
            p.original_content = p.content;
        }
    }

    app.add_post = () => {
        // TODO: this is the new post we are inserting.
        // You need to initialize it properly, completing below, and ...
        let q = {                                           //ADDED
            id: null,
            edit: true,                                                                   //CHANGED
            editable: true,                                                               //CHANGED
            content: "",
            server_content: null,
            original_content: "",
            author: null,
            email: null,
            is_reply: null,
            //is_pending: false,
        };
        // TODO:
        // ... you need to insert it at the top of the post list.
        console.log("Added Post")
        app.data.posts.unshift(q) //adds post to the top of list
        app.reindex(app.data.posts);
    };

    app.reply = (post_idx) => {
        //console.log("Replying") //It's working c:
        let p = app.vue.posts[post_idx];
        if (p.id !== null) {
            // TODO: this is the new reply.  You need to initialize it properly...
            let q = {
                id: null,
                edit: true,
                editable: (p.email === user_email),
                content: "",
                server_content: null,
                original_content: "",
                author: null,
                email: null,
                is_reply: p.id,
            };
            // TODO: and you need to insert it in the right place, and reindex
            // the posts.  Look at the code for app.add_post; it is similar.
            app.data.posts.splice(post_idx + 1, 0, q)
            app.reindex(app.data.posts)
        }

    };

    app.do_delete = (post_idx) => {
        let p = app.vue.posts[post_idx];
        // if (p.id === null) {
        //     // TODO:
        //     // If the post has never been added to the server,
        //     // simply deletes it from the list of posts.
        //     app.data.post.splice(p, 1)
        //     app.data.post = app.reindex(app.data.post)
        //     app.reindex(app.data.posts)
        // } else {
        //     // TODO: Deletes it on the server.
        //     app.data.post.splice(p, 1)
        //     app.data.post = app.reindex(app.data.post)
        //     app.reindex(app.data.posts)
        // }
        if (p.id == null) {
            app.do_cancel(post_idx)

        } else {

        axios.post(delete_url, {id: p.id}).then(() => {

            app.vue.posts.splice(post_idx, 1);
            app.reindex(app.vue.posts);
        })

        }
    };

    // We form the dictionary of all methods, so we can assign them
    // to the Vue app in a single blow.
    app.methods = {
        do_edit: app.do_edit,
        do_cancel: app.do_cancel,
        do_save: app.do_save,
        add_post: app.add_post,
        reply: app.reply,
        do_delete: app.do_delete,
    };

    // This creates the Vue instance.
    app.vue = new Vue({
        el: "#vue-target",
        data: app.data,
        methods: app.methods
    });

    // And this initializes it.
    app.init = () => {
        // You should load the posts from the server.
        // This is purely debugging code.
        // posts = [
            // This is a post.
            // {
            //     id: 1,
            //     content: "I love apples",
            //     author: "Joe Smith",
            //     email: "joe@ucsc.edu",
            //     is_reply: null, // Main post.  Followed by its replies if any.
            // },
            // {
            //     id: 2,
            //     content: "I prefer bananas",
            //     author: "Elena Degiorgi",
            //     email: "elena@ucsc.edu",
            //     is_reply: 1, // This is a reply.
            // },
            // {
            //     id: 3,
            //     content: "I prefer bananas",
            //     author: "Elena Degiorgi",
            //     email: "elena@ucsc.edu",
            //     is_reply: 1, // This is a reply.
            // },
        // ];
        // TODO: Load the posts from the server instead.
        // We set the posts.

        // look on hw5
        axios.get(posts_url).then((result) => {
            console.log("Received:", result.data);
            //posts = result.data.posts.reverse()
            posts = result.data.posts
            posts = app.index(posts)
            console.log(posts)
            app.vue.posts = app.index(posts);
            }).catch((error) => {
                //p.is_pending = false;
                console.log("Printing error");
                console.log(error)
            });
    };

    // Call to the initializer.
    app.init();
};

// This takes the (empty) app object, and initializes it,
// putting all the code i
init(app);
