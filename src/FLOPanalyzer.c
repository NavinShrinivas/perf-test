#include<stdio.h>
#include<pthread.h>
#include<unistd.h>
#include<stdbool.h>
#include<time.h>
#include"./floatfuncs/fsub.h"
#include"./floatfuncs/fdiv.h"

typedef unsigned long long ll;

struct opscount{ //struct to store number of operations per thread per function
    ll fsubpthread;
    ll fdivpthread;
};

void dateformat(char* foldername)
{
    printf("HALO1");
    time_t dt=time(NULL);
    struct tm datetime= *localtime(&dt);
    printf("HALO2");
    // printf("now: %d-%02d-%02d %02d:%02d:%02d\n", date.tm_year + 1900, tm.tm_mon + 1, tm.tm_mday, tm.tm_hour, tm.tm_min, tm.tm_sec);
    /* ddmmyyyyhhmm will be the folder name*/
    char day[5],month[5],year[5],hours[5],minutes[5];
    sprintf(day,"%f",datetime.tm_mday);
    sprintf(month,"%f",(datetime.tm_mon+1));
    sprintf(year,"%f",(datetime.tm_year+1900));
    sprintf(hours,"%f",datetime.tm_hour);
    sprintf(minutes,"%f",datetime.tm_mday);
    printf("HALO");
    snprintf(foldername,sizeof(foldername),"%s: %s: %s: %s: %s",day,month,year,hours,minutes);
}


/*keeping these two as global variables as thread funtions need these parameters
during mutithreading control is transffered from the main function hence at luck
rendering these addresses unacessible by the function leading to seg faults*/ 
int t;//stores the total time for testing
ll subarr[256];//a temp array to stroe values in the thread function , assumin max threads 256
ll divarr[256];
ll cfsec[32];
int total_thread;

int initfloptest(){;
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
    //---------------------start of fsub test----------------------------------
    for(int i=0;i<total_thread;i++)
    {
        subarr[i]=0;
        pthread_create(&thread[i],NULL,fsubtf,&subarr[i]); //creates the thread
    }
    int optime=t/4;//time per function
    for(int i=0;i<total_thread;i++)
	{
		pthread_join(thread[i],NULL);// waits for the thread fo finish , finish condition being NULL
	}
    for(int i=0;i<total_thread;i++)
	{
        opcount[i].fsubpthread=subarr[i];//transffers values from temp array to struct
    }
    ll totalfsub=0;
    ll maxfsub=0;
    for(int i=0;i<total_thread;i++)
    {
        if(maxfsub<opcount[i].fsubpthread)
            maxfsub=opcount[i].fsubpthread;
        totalfsub+=opcount[i].fsubpthread;
    }
    double totalfsubpsec=totalfsub/optime;
    double maxfsubpsec=maxfsub/optime;
    double maxfsubgflop=maxfsubpsec/1000000000;
    double fsubgflop=totalfsubpsec/1000000000;
    printf("FSUB : %lf GFlops [Maximum throughput]\n",fsubgflop);
    printf("FSUB : %lf GFlops [Maximim single thread throughput]\n",maxfsubgflop);
    //---------------------start of fdiv test----------------------------------
    for(int i=0;i<total_thread;i++)
    {
        divarr[i]=0;
        pthread_create(&thread[i],NULL,fdivtf,&divarr[i]); //creates the thread
    }
    for(int i=0;i<total_thread;i++)
	{
		pthread_join(thread[i],NULL);// waits for the thread fo finish , finish condition being NULL
	}
    for(int i=0;i<total_thread;i++)
	{
        opcount[i].fdivpthread=divarr[i];//transfers values from temp array to struct
    }
    ll totalfdiv=0;
    ll maxfdiv=0;
    for(int i=0;i<total_thread;i++)
    {
        if(maxfdiv<opcount[i].fdivpthread)
            maxfdiv=opcount[i].fdivpthread;
        totalfdiv+=opcount[i].fdivpthread;
    }
    double totalfdivpsec=totalfdiv/optime;
    double maxfdivpsec=maxfdiv/optime;
    double maxfdivgflop=maxfdivpsec/1000000000;
    double fdivgflop=totalfdivpsec/1000000000;
    printf("FDIV : %lf GFlops [Maximum throughput]\n",fdivgflop);
    printf("FDIV : %lf GFlops [Maximim single thread throughput]\n",maxfdivgflop);
    char foldername[10];
    printf("HALO3");
    dateformat(foldername);
    printf("%s",foldername);
    printf("Press Enter to go back to return.");
    char garbage;
    scanf("%c",&garbage);
    if(garbage=='\n')
        return 0;
    scanf("%c",&garbage);   
}
