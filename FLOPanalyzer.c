#include<stdio.h>
#include<pthread.h>
#include<unistd.h>
#include<stdbool.h>
#include<time.h>
typedef unsigned long long ll;

struct opscount{ //struct to store number of operations per thread per function
    ll faddpthread;
    ll fsubpthread;
    ll fmulpthrea;
    ll fdivpthread;
};
/*keeping these two as global variables as thread funtions need these parameters
during mutithreading control is transffered from the main function hence at luck
rendering these addresses unacessible by the function leading to seg faults*/ 
int t;//stores the total time for testing
ll addarr[256];//a temp array to stroe values in the thread function , assumin max threads 256
void* faddtf(void *oppthread) //our thread function
{
    /*registers to avoid caching and to save the time taken to fetch data from
    memory*/
    register double c=0.75665;
    register double v1=0.3452345543e-2,v2=0.2342342344e-5,v3=0.2534534523e-4;
    register double v4=0.6575676788e-5,v5=0.2345564656e-2,v6=0.3456573453e-3;
    register double v7=0.9786575454e-5,v8=0.6754645345e-6;
    register double v9=0.2345435677e-2,v10=0.6876798956e-4;
    clock_t start;
    start=time(NULL);
    bool flag=true;
    while(flag)
    {
        c+=v1+v2+v3+v4+v5;c+=v6+v7+v8+v9+v10;c+=v1+v2+v3+v4+v5;c+=v6+v7+v8+v9+v10;
        c+=v1+v2+v3+v4+v5;c+=v6+v7+v8+v9+v10;c+=v1+v2+v3+v4+v5;c+=v6+v7+v8+v9+v10;
        c+=v1+v2+v3+v4+v5;c+=v6+v7+v8+v9+v10;c+=v1+v2+v3+v4+v5;c+=v6+v7+v8+v9+v10;
        c+=v1+v2+v3+v4+v5;c+=v6+v7+v8+v9+v10;c+=v1+v2+v3+v4+v5;c+=v6+v7+v8+v9+v10;
        c+=v1+v2+v3+v4+v5;c+=v6+v7+v8+v9+v10;c+=v1+v2+v3+v4+v5;c+=v6+v7+v8+v9+v10;
        c+=v1+v2+v3+v4+v5;c+=v6+v7+v8+v9+v10;c+=v1+v2+v3+v4+v5;c+=v6+v7+v8+v9+v10;
        c+=v1+v2+v3+v4+v5;c+=v6+v7+v8+v9+v10;c+=v1+v2+v3+v4+v5;c+=v6+v7+v8+v9+v10;
        c+=v1+v2+v3+v4+v5;c+=v6+v7+v8+v9+v10;c+=v1+v2+v3+v4+v5;c+=v6+v7+v8+v9+v10;
        c+=v1+v2+v3+v4+v5;c+=v6+v7+v8+v9+v10;c+=v1+v2+v3+v4+v5;c+=v6+v7+v8+v9+v10;
        c+=v1+v2+v3+v4+v5;c+=v6+v7+v8+v9+v10;c+=v1+v2+v3+v4+v5;c+=v6+v7+v8+v9+v10;
        c+=v1+v2+v3+v4+v5;c+=v6+v7+v8+v9+v10;c+=v1+v2+v3+v4+v5;c+=v6+v7+v8+v9+v10;
        c+=v1+v2+v3+v4+v5;c+=v6+v7+v8+v9+v10;c+=v1+v2+v3+v4+v5;c+=v6+v7+v8+v9+v10;
        c+=v1+v2+v3+v4+v5;c+=v6+v7+v8+v9+v10;c+=v1+v2+v3+v4+v5;c+=v6+v7+v8+v9+v10;
        c+=v1+v2+v3+v4+v5;c+=v6+v7+v8+v9+v10;c+=v1+v2+v3+v4+v5;c+=v6+v7+v8+v9+v10;
        c+=v1+v2+v3+v4+v5;c+=v6+v7+v8+v9+v10;c+=v1+v2+v3+v4+v5;c+=v6+v7+v8+v9+v10;
        c+=v1+v2+v3+v4+v5;c+=v6+v7+v8+v9+v10;c+=v1+v2+v3+v4+v5;c+=v6+v7+v8+v9+v10;
        c+=v1+v2+v3+v4+v5;c+=v6+v7+v8+v9+v10;c+=v1+v2+v3+v4+v5;c+=v6+v7+v8+v9+v10;
        c+=v1+v2+v3+v4+v5;c+=v6+v7+v8+v9+v10;c+=v1+v2+v3+v4+v5;c+=v6+v7+v8+v9+v10;
        c+=v1+v2+v3+v4+v5;c+=v6+v7+v8+v9+v10;c+=v1+v2+v3+v4+v5;c+=v6+v7+v8+v9+v10;
        c+=v1+v2+v3+v4+v5;c+=v6+v7+v8+v9+v10;c+=v1+v2+v3+v4+v5;c+=v6+v7+v8+v9+v10;
        c+=v1+v2+v3+v4+v5;c+=v6+v7+v8+v9+v10;c+=v1+v2+v3+v4+v5;c+=v6+v7+v8+v9+v10;
        c+=v1+v2+v3+v4+v5;c+=v6+v7+v8+v9+v10;c+=v1+v2+v3+v4+v5;c+=v6+v7+v8+v9+v10;
        c+=v1+v2+v3+v4+v5;c+=v6+v7+v8+v9+v10;c+=v1+v2+v3+v4+v5;c+=v6+v7+v8+v9+v10;
        c+=v1+v2+v3+v4+v5;c+=v6+v7+v8+v9+v10;c+=v1+v2+v3+v4+v5;c+=v6+v7+v8+v9+v10;
        c+=v1+v2+v3+v4+v5;c+=v6+v7+v8+v9+v10;c+=v1+v2+v3+v4+v5;c+=v6+v7+v8+v9+v10;
        c+=v1+v2+v3+v4+v5;c+=v6+v7+v8+v9+v10;c+=v1+v2+v3+v4+v5;c+=v6+v7+v8+v9+v10;
        c+=v1+v2+v3+v4+v5;c+=v6+v7+v8+v9+v10;c+=v1+v2+v3+v4+v5;c+=v6+v7+v8+v9+v10;
        c+=v1+v2+v3+v4+v5;c+=v6+v7+v8+v9+v10;c+=v1+v2+v3+v4+v5;c+=v6+v7+v8+v9+v10;
        c+=v1+v2+v3+v4+v5;c+=v6+v7+v8+v9+v10;c+=v1+v2+v3+v4+v5;c+=v6+v7+v8+v9+v10;
        c+=v1+v2+v3+v4+v5;c+=v6+v7+v8+v9+v10;c+=v1+v2+v3+v4+v5;c+=v6+v7+v8+v9+v10;
        c+=v1+v2+v3+v4+v5;c+=v6+v7+v8+v9+v10;c+=v1+v2+v3+v4+v5;c+=v6+v7+v8+v9+v10;
        c+=v1+v2+v3+v4+v5;c+=v6+v7+v8+v9+v10;c+=v1+v2+v3+v4+v5;c+=v6+v7+v8+v9+v10;
        c+=v1+v2+v3+v4+v5;c+=v6+v7+v8+v9+v10;c+=v1+v2+v3+v4+v5;c+=v6+v7+v8+v9+v10;
        c+=v1+v2+v3+v4+v5;c+=v6+v7+v8+v9+v10;c+=v1+v2+v3+v4+v5;c+=v6+v7+v8+v9+v10;
        c+=v1+v2+v3+v4+v5;c+=v6+v7+v8+v9+v10;c+=v1+v2+v3+v4+v5;c+=v6+v7+v8+v9+v10;
        c+=v1+v2+v3+v4+v5;c+=v6+v7+v8+v9+v10;c+=v1+v2+v3+v4+v5;c+=v6+v7+v8+v9+v10;
        c+=v1+v2+v3+v4+v5;c+=v6+v7+v8+v9+v10;c+=v1+v2+v3+v4+v5;c+=v6+v7+v8+v9+v10;
        c+=v1+v2+v3+v4+v5;c+=v6+v7+v8+v9+v10;c+=v1+v2+v3+v4+v5;c+=v6+v7+v8+v9+v10;
        c+=v1+v2+v3+v4+v5;c+=v6+v7+v8+v9+v10;c+=v1+v2+v3+v4+v5;c+=v6+v7+v8+v9+v10;
        c+=v1+v2+v3+v4+v5;c+=v6+v7+v8+v9+v10;c+=v1+v2+v3+v4+v5;c+=v6+v7+v8+v9+v10;
        int op=160*5;
        *((ll *)oppthread)+=op;
        if(time(NULL)-start>=(t/4))
        {
            flag=false;
        }
    }
    return NULL;//void* hence NULL
}
int initfloptest(){
    int total_thread;
    printf("Enter total number of threads : ");
    scanf("%i",&total_thread);
    printf("Time to run the test : ");
    scanf("%i",&t);
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
    ll totalfadd;
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
}








