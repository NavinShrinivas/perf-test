#include <mongoc/mongoc.h>
#include <stdio.h>
#include <stdlib.h>
// #include "FLOPanalyzer.h"
#include "jsmn.h"
#if _WIN32 || WIN32
int a[100]
__asm__("mov $0x80000002 , %eax\n\t"); //serious amount of inline assemmbly
__asm__("mov $0x80000003 , %eax\n\t"); //this now in theory whould work in windows machines too
__asm__("mov $0x80000004 , %eax\n\t"); //imma test soon
__asm__("cpuid\n\t"); //learning that assembly did come in handy :)
__asm__("mov %%eax, %0\n\t":"=r" (a[0]));
__asm__("mov %%ebx, %0\n\t":"=r" (a[1]));
__asm__("mov %%ecx, %0\n\t":"=r" (a[2]));
__asm__("mov %%edx, %0\n\t":"=r" (a[3]));
#define cpuname a
#else
#define cpuname system("cat /proc/cpuinfo | grep -m 2 'model name' | head -1 | grep -o -E ' ([A-Z][a-z]).{0,100}' ")
#endif

mongoc_database_t *database;
mongoc_collection_t *collection;
mongoc_client_t *client;

bson_error_t error; //to collect any returned error value
bson_oid_t oid; //for object id , its automatically handle by libmongoc
bson_t *doc; //going to store our results in bson format
jsmn_parser jp;
jsmntok_t data[150];

int main(){
    client = mongoc_client_new ("mongodb+srv://commontester:atlaspass@rankings.csa2g.mongodb.net/myFirstDatabase?retryWrites=true&w=majority");
    /*inside the brackets of the above line must lie your mongodb atlas uri*/
    database = mongoc_client_get_database (client, "std_test");
    collection = mongoc_client_get_collection (client, "std_test", "std_test");

    doc=bson_new();
    bson_oid_init(&oid,NULL);
    BSON_APPEND_OID(doc,"_id",&oid);
    BSON_APPEND_INT64(doc,"TestID",rand());
    // BSON_APPEND_DOUBLE(doc,"TestScores",testscore);
    // BSON_APPEND_INT64(doc,"Threads",total_thread); 
    // char* cpuname=
    printf("%s",cpuname);
    // mongoc_collection_insert_one (collection, doc, NULL, NULL, &error);
    bson_destroy (doc);
    mongoc_collection_destroy (collection);
    mongoc_client_destroy (client);
    mongoc_cleanup ();

    return 0;
   

}