#include<stdio.h>
#include<pthread.h>
#include<unistd.h>
#include<stdbool.h>
typedef unsigned long long ll;

const double v1=0.3452345543e-2;
const double v2=0.2342342344e-5;
const double v3=0.2534534523e-4;
const double v4=0.6575676788e-5;
const double v5=0.2345564656e-2;
const double v6=0.3456573453e-3;
const double v7=0.9786575454e-5;
const double v8=0.6754645345e-6;
const double v9=0.2345435677e-2;
const double v10=0.6876798956e-4;
struct opscount{
    ll faddpthread;
    ll fsubpthread;
    ll fmulpthrea;
    ll fdivpthread;
};
void *faddtf(void *oppthread)
{
    double c=0.75665;
    while(true)
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
    }
}
int main(){
    int total_thread,t;
    printf("Enter total number of threads : ");
    scanf("%i",&total_thread);
    printf("Time to run the test : ");
    scanf("%i",&t);
    struct opscount opcount[total_thread];
    pthread_t thread[total_thread];
    //---------------------start of fadd test----------------------------------
    ll addarr[total_thread];
    for(int i=0;i<total_thread;i++)
    {
        pthread_create(&thread[i],NULL,faddtf,&addarr[i]);
    }
    int optime=t/4;
    sleep(optime);
    for(int i=0;i<total_thread;i++)
	{
        opcount[i].faddpthread=addarr[i];
		pthread_cancel(thread[i]);// kills the threads
	}
    ll totalfadd;
    for(int i=0;i<total_thread;i++)
    {
        totalfadd+=opcount[i].faddpthread;
    }
    double totalfaddpsec=totalfadd/optime;
    double faddgflop=totalfaddpsec/1000000000;
    printf("FADD : %lf GFlops",faddgflop);
    fflush(stdout);

}