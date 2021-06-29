#include<stdio.h>
#include<string.h>
#include "FLOPanalyzer.h"
#ifdef _WIN32 || WIN32 //trying porable clrscr() and NPROESSORS_ONLN macro
#define clrscr() system("cls")
#include<windows.h>
SYSTEM_INFO sysinfo;
GetSystemInfo(&sysinfo);
#else
#define clrscr() system("clear")
#include<unistd.h>
#endif
char garbage;
int main(int argc, char* argv[]){
    #if _WIN32 || WIN32
    #define cores sysinfo.dwNumberOfProcessors
    #else
    #define cores sysconf(_SC_NPROCESSORS_ONLN)
    #endif
    if(argc>=2)
    {
        printf("Argument entered :%s \n",argv[1]);
        if(strcmp(argv[1],"help")==0)
        {
            printf("Usage : ./tester.o [option_name] [Arg1] [Arg2] [Arg3] ... [ArgN]\n");
            printf("List of available options:\n");
            printf("1.floptest\n");
            printf("   Arguments :\n");
            printf("   option_name : floptest \n");
            printf("   Arg1 : Total number of threads\n");
            printf("   Arg2 : Total time for testing\n");
            printf("2.menu\n");
            printf("   option_name : menu \n");
            printf("   Arguments : NO ARGUMENTS\n");
            printf("3.stdtest\n");
            printf("   option_name : stdtest \n");
            printf("   Arguments : NO ARGUMENTS\n");
            printf("4.research\n");
            printf("   option_name : research \n");
            printf("   Arguments : NO ARGUMENTS\n");
        }
        else if(strcmp(argv[1],"floptest")==0)
        {
            if(argc<4)
            {
                printf("\t Usage : ./tester.o floptest [Number of threads] [time in seconds]\n");
            }
            else{
                total_thread=atoi(argv[2]); //extern vars, I am sick of passing varibles around.
                t=atoi(argv[3]); //extern vars, I am sick of passing varibles around.
                initfloptest();
            }
        }
        else if(strcmp(argv[1],"menu")==0) //optional menu driven program!
        {
            int choice;
            while(1)
            {
                clrscr();
                //menu
                printf("---------------HARDWARE TESTER---------------\n");
                printf("1.Custom Floating point operation test\n");
                printf("2.Standard test [60 seconds] for ranking \n");
                printf("3.Research based test\n");
                printf("4.Exit\n");
                printf("Enter your choice :");
                scanf("%i",&choice);
                if(choice==1)
                {
                    stdflag=0;
                    t=0;
                    total_thread=0;
                    clrscr();
                    initfloptest();
                    clrscr();
                }
                else if(choice==2)
                {
                    stdflag=1
                    total_thread=cores;
                    t=60;
                    stdflag=1;
                    clrscr();
                    initfloptest();
                    clrscr();
                }
                else if(choice==3)
                {
                    stdflag=0;
                    total_thread=cores;
                    t=60;
                    clrscr();
                    research();
                    clrscr();
                }
                else if(choice==4)
                    return 0;
                else
                {
                    printf("Plese enter a correct option.Press enter to continue!");
                    fflush(stdout);
                    fflush(stdin);  
                    scanf("%c",&garbage);
                }
            }
        }
        else if(strcmp(argv[1],"stdtest")==0)
        {
            stdflag=1;
            total_thread=cores; //extern vars, I am sick of passing varibles around.
            t=60; //extern vars, I am sick of passing varibles around.
            stdflag=1;
            initfloptest();
        }
        else if(strcmp(argv[1],"research")==0)
        {
            stdflag=0;
            t=60;
            total_thread=cores;
            research();
        }
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
