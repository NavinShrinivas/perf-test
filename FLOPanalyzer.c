#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<pthread.h>
#include<unistd.h>
typedef long long int ll;

//structure of the struct so that the function
//can understand derefrencing
struct result{
    int thread_id;
    ll fadd;
    ll fsub;
    ll fdiv;
    ll fmul;
};
void *flopcalculator(void* threadprops){
    /*registers are memory locations in cpu,
    here we have used register so as to not loose
    anyperformace due to memory latency*/
    register double v1=0.435e-308; 
    register double v2=0.45e308; 
    register double v3=0.234e-308; 
    register double v4=0.453e308; 
    register double v5=0.423e-308; 
    //this spam of 64bit double standard floating point numbers
    //is to make sure that compiler doesnt take any advantage of
    //operation specific pipelines that speeds up the process that 
    //is present in CPU pipelines

    while(true)
    {
        double* chc_add=(double*)malloc(sizeof(double));
        double* chc_sub=(double*)malloc(sizeof(double));
        double* chc_div=(double*)malloc(sizeof(double));
        double* chc_mul=(double*)malloc(sizeof(double));
        if(((struct result*)threadprops)->fadd==0)
        {
            *chc_add=v1+v2+v3+v4+v5; //few x86 architechture have a optimised pipline for fadd
            ((struct result*)threadprops)->fadd+=10;
        }
        if(((struct result*)threadprops)->fsub==0)
        {
            *chc_sub=v1-v2-v3-v4-v5;
            ((struct result*)threadprops)->fsub+=10;
        }
        if(((struct result*)threadprops)->fmul==0)
        {
            *chc_mul=v1*v2*v3*v4*v5; //few x86 architechture have a optimised pipline for fmul
            ((struct result*)threadprops)->fmul+=10;
        }
        if(((struct result*)threadprops)->fdiv==0)
        {
            *chc_div=(v1/v2)+(v3/v4)+(v5);
            ((struct result*)threadprops)->fdiv+=10;
        }
    }
}
int main(){
    int tot;
    printf("Total number of threads to run on :");
    scanf("%i",&tot);
    int time;
    printf("Total time for test :");
    scanf("%i",&time);
    pthread_t threads[tot];
    struct result results[tot];
    for(ll i=0;i<tot;i++)
    {
        ((struct result*)results+i)->thread_id=i;
        ((struct result*)results+i)->fadd=-1;
        ((struct result*)results+i)->fsub=-1;
        ((struct result*)results+i)->fmul=-1;
        ((struct result*)results+i)->fdiv=-1;  
    }
    for(ll i=0;i<tot;i++)
    {   
        printf("Starting fadd module!");
        ((struct result*)results+i)->fadd=0;
        pthread_create(&threads[i],NULL,flopcalculator,results+i);
    }
    sleep(time/4);
    for(int i=0;i<tot;i++){
        pthread_cancel(threads[i]);
    }
    for(ll i=0;i<tot;i++)
    {   
        printf("Starting fsub module!");
        ((struct result*)results+i)->fsub=0;
        pthread_create(&threads[i],NULL,flopcalculator,results+i);
    }
    sleep(time/4);
    for(int i=0;i<tot;i++){
        pthread_cancel(threads[i]);
    }
    for(ll i=0;i<tot;i++)
    {   
        printf("Starting fmul module!");
        ((struct result*)results+i)->fmul=0;
        pthread_create(&threads[i],NULL,flopcalculator,results+i);
    }
    sleep(time/4);
    for(int i=0;i<tot;i++){
        pthread_cancel(threads[i]);
    }
    for(ll i=0;i<tot;i++)
    {   
        printf("Starting fdiv module!");
        ((struct result*)results+i)->fdiv=0;
        pthread_create(&threads[i],NULL,flopcalculator,results+i);
    }
    sleep(time/4);
    for(int i=0;i<tot;i++){
        pthread_cancel(threads[i]);
    }

}        