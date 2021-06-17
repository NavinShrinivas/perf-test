#include<stdio.h>
#include<string.h>
#include "FLOPanalyzer.h"
#ifdef defined(_WIN32) || defined(WIN32) //trying porable clrscr()
#include<conio.h>
#else
#define clrscr() system("clear")
#endif
int main(int argc, char* argv[]){
    if(argc>=2)
    {
        printf("Argument entered :%s \n",argv[1]);
        if(strcmp(argv[1],"help")==0)
        {
            printf("List of available module:\n");
            printf("1.floptest\n");
            printf("\t Usage : ./tester.o floptest [Number of threads] [time in seconds]\n");
            printf("2.menu\n");
            printf("\t Usage : ./tester.o menu 'Opens the menu driven part of the program'\n");
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
                printf("1.Floating point operation test [Flops's]\n");
                printf("2.Exit\n");
                printf("Enter your choice :");
                scanf("%i",&choice);
                if(choice==1)
                {
                    clrscr();
                    initfloptest();
                    clrscr();
                }
                else if(choice==2)
                    return 0;
            }
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
