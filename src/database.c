#include <mongoc/mongoc.h>

mongoc_database_t *database;
mongoc_collection_t *collection;
mongoc_client_t *client;
bson_t *command,reply,*insert;
bson_error_t error;
mongoc_uri_t *uri;
mongoc_cursor_t *cursor;
const bson_t *doc;
bson_t *query;
bool retval;
char* str;


int main(){
    
    client = mongoc_client_new ("mongodb+srv://commontester:atlaspass@rankings.csa2g.mongodb.net/myFirstDatabase?retryWrites=true&w=majority");
    database = mongoc_client_get_database (client, "std_test");
    collection = mongoc_client_get_collection (client, "std_test", "std_test");
    command = BCON_NEW ("ping", BCON_INT32 (1));
    query=bson_new();
    cursor = mongoc_collection_find_with_opts (collection, query, NULL, NULL);

    while (mongoc_cursor_next (cursor, &doc)) {
        str = bson_as_canonical_extended_json (doc, NULL);
        printf ("%s\n", str);
        bson_free (str);
    }

    mongoc_cursor_destroy (cursor);
    mongoc_collection_destroy (collection);
    mongoc_client_destroy (client);
    mongoc_cleanup ();

}