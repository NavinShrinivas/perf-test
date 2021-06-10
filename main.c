#include<stdio.h>
#include<string.h>
#include "FLOPanalyzer.h"
int main(int argc, char* argv[]){
    if(argc>=2)
    {
        printf("Argument entered :%s \n",argv[1]);
        if(strcmp(argv[1],"help")==0)
        {
            printf("List of available module:\n");
            printf("1.floptest\n");
        }
        else if(strcmp(argv[1],"floptest")==0)
            initfloptest();
        else{
            printf("Please enter a valid argument!\n");
            printf("append help to execution command to see all possible arguments.\n");
            return 0;
        }
        
    }
    else
    {
        printf("Please enter a argument!\n");
        printf("append help to execution command to see all possible arguments.\n");
        return 0;
    } 
}