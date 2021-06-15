#include<stdio.h>
#include<pthread.h>
#include<unistd.h>
#include<stdbool.h>
#include<time.h>
#include"fadd.h"
#include"fmul.h"

typedef unsigned long long ll;

struct opscount{ //struct to store number of operations per thread per function
    ll faddpthread;
    ll fsubpthread;
    ll fmulpthread;
    ll fdivpthread;
};
/*keeping these two as global variables as thread funtions need these parameters
during mutithreading control is transffered from the main function hence at luck
rendering these addresses unacessible by the function leading to seg faults*/ 
int t;//stores the total time for testing
ll addarr[256];//a temp array to stroe values in the thread function , assumin max threads 256
ll mularr[256];
int total_thread;

int initfloptest(){
    if(total_thread==0) //for optional menu options!
    {
        printf("Enter total number of threads : ");
        scanf("%i",&total_thread);
    }
    if(t==0) //optional menu options!
    {
        printf("Time to run the test [Seconds] : ");
        scanf("%i",&t);
    }
    printf("Running test for %i seconds!\n",t);
    fflush(stdout);
    struct opscount opcount[total_thread];
    pthread_t thread[total_thread];
    //---------------------start of fadd test----------------------------------
    for(int i=0;i<total_thread;i++)
    {
        addarr[i]=0;
        pthread_create(&thread[i],NULL,faddtf,&addarr[i]); //creates the thread
    }
    int optime=t/4;//time per function
    for(int i=0;i<total_thread;i++)
	{
		pthread_join(thread[i],NULL);// waits for the thread fo finish , finish condition being NULL
	}
    for(int i=0;i<total_thread;i++)
	{
        opcount[i].faddpthread=addarr[i];//transffers values from temp array to struct
    }
    ll totalfadd=0;
    ll maxfadd=0;
    for(int i=0;i<total_thread;i++)
    {
        if(maxfadd<opcount[i].faddpthread)
            maxfadd=opcount[i].faddpthread;
        totalfadd+=opcount[i].faddpthread;
    }
    double totalfaddpsec=totalfadd/optime;
    double maxfaddpsec=maxfadd/optime;
    double maxfaddgflop=maxfaddpsec/1000000000;
    double faddgflop=totalfaddpsec/1000000000;
    printf("FADD : %lf GFlops [Maximum throughput]\n",faddgflop);
    printf("FADD : %lf GFlops [Maximim single thread throughput]\n",maxfaddgflop);
    //---------------------start of fmul test----------------------------------
    for(int i=0;i<total_thread;i++)
    {
        mularr[i]=0;
        pthread_create(&thread[i],NULL,fmultf,&mularr[i]); //creates the thread
    }
    for(int i=0;i<total_thread;i++)
	{
		pthread_join(thread[i],NULL);// waits for the thread fo finish , finish condition being NULL
	}
    for(int i=0;i<total_thread;i++)
	{
        opcount[i].fmulpthread=mularr[i];//transffers values from temp array to struct
    }
    ll totalfmul=0;
    ll maxfmul=0;
    for(int i=0;i<total_thread;i++)
    {
        if(maxfmul<opcount[i].fmulpthread)
            maxfmul=opcount[i].fmulpthread;
        totalfmul+=opcount[i].fmulpthread;
    }
    double totalfmulpsec=totalfmul/optime;
    double maxfmulpsec=maxfmul/optime;
    double maxfmulgflop=maxfmulpsec/1000000000;
    double fmulgflop=totalfmulpsec/1000000000;
    printf("FMUL : %lf GFlops [Maximum throughput]\n",fmulgflop);
    printf("FMUL : %lf GFlops [Maximim single thread throughput]\n",maxfmulgflop);
    fflush(stdout);
    fflush(stdin);
    printf("Press Enter to go back to return.");
    char garbage;
    scanf("%c",&garbage);
    scanf("%c",&garbage);
    return 0;
}
