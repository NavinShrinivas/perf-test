#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<pthread.h>
#include<unistd.h>

typedef unsigned long long int ll;


void *faddcalculator(void* thread_ops){
    /*registers are memory locations in cpu,
    here we have used register so as to not loose
    anyperformace due to memory latency*/
    register double v1=0.435e-308; 
    register double v2=0.45e308; 
    register double v3=0.234e-308; 
    register double v4=0.453e308; 
    register double v5=0.423e-308; 
    register double v6=0.435e-308; 
    register double v7=0.45e308; 
    register double v8=0.234e-308; 
    register double v9=0.453e308; 
    register double v10=0.423e-308; 
    //this spam of 64bit double standard floating point numbers
    //is to make sure that compiler doesnt take any advantage of
    //operation specific pipelines that speeds up the process that 
    //is present in CPU pipelines
    while(true)
    {
        /*the spam of operations below is beacuse i Observed maximum throughput
        at 30*19 opetartion for every loops , anything lesser is giving giving a lesser
        number of max ops and anything higher gives around the same values , 
        I my guess would be that anything lower than 30*19 operations is faster that the 
        while loops and more cpu time is spent in while loops than flops , keeping in mind faster
        c compilers and faster cpus i am settling on 40*19 ops for single while loop*/

        //few x86 architechture have a optimised pipline for fadd
        
        double chc_add=v1+v2+v3+v4+v5+v6+v7+v8+v9+v10+v2+v3+v4+v5+v6+v7+v8+v9+v10;
        chc_add=v1+v2+v3+v4+v5+v6+v7+v8+v9+v10+v2+v3+v4+v5+v6+v7+v8+v9+v10;
        chc_add=v1+v2+v3+v4+v5+v6+v7+v8+v9+v10+v2+v3+v4+v5+v6+v7+v8+v9+v10;
        chc_add=v1+v2+v3+v4+v5+v6+v7+v8+v9+v10+v2+v3+v4+v5+v6+v7+v8+v9+v10;
        chc_add=v1+v2+v3+v4+v5+v6+v7+v8+v9+v10+v2+v3+v4+v5+v6+v7+v8+v9+v10;
        chc_add=v1+v2+v3+v4+v5+v6+v7+v8+v9+v10+v2+v3+v4+v5+v6+v7+v8+v9+v10;
        chc_add=v1+v2+v3+v4+v5+v6+v7+v8+v9+v10+v2+v3+v4+v5+v6+v7+v8+v9+v10;
        chc_add=v1+v2+v3+v4+v5+v6+v7+v8+v9+v10+v2+v3+v4+v5+v6+v7+v8+v9+v10;
        chc_add=v1+v2+v3+v4+v5+v6+v7+v8+v9+v10+v2+v3+v4+v5+v6+v7+v8+v9+v10;
        chc_add=v1+v2+v3+v4+v5+v6+v7+v8+v9+v10+v2+v3+v4+v5+v6+v7+v8+v9+v10;
        chc_add=v1+v2+v3+v4+v5+v6+v7+v8+v9+v10+v2+v3+v4+v5+v6+v7+v8+v9+v10;
        chc_add=v1+v2+v3+v4+v5+v6+v7+v8+v9+v10+v2+v3+v4+v5+v6+v7+v8+v9+v10;
        chc_add=v1+v2+v3+v4+v5+v6+v7+v8+v9+v10+v2+v3+v4+v5+v6+v7+v8+v9+v10;
        chc_add=v1+v2+v3+v4+v5+v6+v7+v8+v9+v10+v2+v3+v4+v5+v6+v7+v8+v9+v10;
        chc_add=v1+v2+v3+v4+v5+v6+v7+v8+v9+v10+v2+v3+v4+v5+v6+v7+v8+v9+v10;
        chc_add=v1+v2+v3+v4+v5+v6+v7+v8+v9+v10+v2+v3+v4+v5+v6+v7+v8+v9+v10;
        chc_add=v1+v2+v3+v4+v5+v6+v7+v8+v9+v10+v2+v3+v4+v5+v6+v7+v8+v9+v10;
        chc_add=v1+v2+v3+v4+v5+v6+v7+v8+v9+v10+v2+v3+v4+v5+v6+v7+v8+v9+v10;
        chc_add=v1+v2+v3+v4+v5+v6+v7+v8+v9+v10+v2+v3+v4+v5+v6+v7+v8+v9+v10;
        chc_add=v1+v2+v3+v4+v5+v6+v7+v8+v9+v10+v2+v3+v4+v5+v6+v7+v8+v9+v10;
        chc_add=v1+v2+v3+v4+v5+v6+v7+v8+v9+v10+v2+v3+v4+v5+v6+v7+v8+v9+v10;
        chc_add=v1+v2+v3+v4+v5+v6+v7+v8+v9+v10+v2+v3+v4+v5+v6+v7+v8+v9+v10;
        chc_add=v1+v2+v3+v4+v5+v6+v7+v8+v9+v10+v2+v3+v4+v5+v6+v7+v8+v9+v10;
        chc_add=v1+v2+v3+v4+v5+v6+v7+v8+v9+v10+v2+v3+v4+v5+v6+v7+v8+v9+v10;
        chc_add=v1+v2+v3+v4+v5+v6+v7+v8+v9+v10+v2+v3+v4+v5+v6+v7+v8+v9+v10;
        chc_add=v1+v2+v3+v4+v5+v6+v7+v8+v9+v10+v2+v3+v4+v5+v6+v7+v8+v9+v10;
        chc_add=v1+v2+v3+v4+v5+v6+v7+v8+v9+v10+v2+v3+v4+v5+v6+v7+v8+v9+v10;
        chc_add=v1+v2+v3+v4+v5+v6+v7+v8+v9+v10+v2+v3+v4+v5+v6+v7+v8+v9+v10;
        chc_add=v1+v2+v3+v4+v5+v6+v7+v8+v9+v10+v2+v3+v4+v5+v6+v7+v8+v9+v10;
        chc_add=v1+v2+v3+v4+v5+v6+v7+v8+v9+v10+v2+v3+v4+v5+v6+v7+v8+v9+v10;
        chc_add=v1+v2+v3+v4+v5+v6+v7+v8+v9+v10+v2+v3+v4+v5+v6+v7+v8+v9+v10;
        chc_add=v1+v2+v3+v4+v5+v6+v7+v8+v9+v10+v2+v3+v4+v5+v6+v7+v8+v9+v10;
        chc_add=v1+v2+v3+v4+v5+v6+v7+v8+v9+v10+v2+v3+v4+v5+v6+v7+v8+v9+v10;
        chc_add=v1+v2+v3+v4+v5+v6+v7+v8+v9+v10+v2+v3+v4+v5+v6+v7+v8+v9+v10;
        chc_add=v1+v2+v3+v4+v5+v6+v7+v8+v9+v10+v2+v3+v4+v5+v6+v7+v8+v9+v10;
        chc_add=v1+v2+v3+v4+v5+v6+v7+v8+v9+v10+v2+v3+v4+v5+v6+v7+v8+v9+v10;
        chc_add=v1+v2+v3+v4+v5+v6+v7+v8+v9+v10+v2+v3+v4+v5+v6+v7+v8+v9+v10;
        chc_add=v1+v2+v3+v4+v5+v6+v7+v8+v9+v10+v2+v3+v4+v5+v6+v7+v8+v9+v10;
        chc_add=v1+v2+v3+v4+v5+v6+v7+v8+v9+v10+v2+v3+v4+v5+v6+v7+v8+v9+v10;
        chc_add=v1+v2+v3+v4+v5+v6+v7+v8+v9+v10+v2+v3+v4+v5+v6+v7+v8+v9+v10;
        chc_add=v1+v2+v3+v4+v5+v6+v7+v8+v9+v10+v2+v3+v4+v5+v6+v7+v8+v9+v10;
        (*((ll *)thread_ops))+=19*40;

        /*rapidlt acessing this adress was giving very weird segfaults
        hence increasing ops to 19*40 seems to have fixed that too*/
        /*i.e new upsation values faster than write times*/
    }
}
// void *fsubcalculator(){
//     register double v1=0.435e-308; 
//     register double v2=0.45e308; 
//     register double v3=0.234e-308; 
//     register double v4=0.453e308; 
//     register double v5=0.423e-308; 
//     register double v6=0.435e-308; 
//     register double v7=0.45e308; 
//     register double v8=0.234e-308; 
//     register double v9=0.453e308; 
//     register double v10=0.423e-308; 
//     while(true)
//     {
//         double chc_sub=v1-v2-v3-v4-v5-v6-v7-v8-v9-v10;
//         c[1]+=10;
//     }
// }
// void *fmulcalculator(){
//     register double v1=0.435e-308; 
//     register double v2=0.45e308; 
//     register double v3=0.234e-308; 
//     register double v4=0.453e308; 
//     register double v5=0.423e-308;
//     register double v6=0.435e-308; 
//     register double v7=0.45e308; 
//     register double v8=0.234e-308; 
//     register double v9=0.453e308; 
//     register double v10=0.423e-308;  
//     while(true)
//     {

//         double chc_mul=v1*v2*v3*v4*v5*v6*v7*v8*v9*v10; //few x86 architechture have a optimised pipline for fmul
//         c[2]+=10;

//     }
// }
// void *fdivcalculator(){
//     register double v1=0.435e-308; 
//     register double v2=0.45e308; 
//     register double v3=0.234e-308; 
//     register double v4=0.453e308; 
//     register double v5=0.423e-308;
//     register double v6=0.435e-308; 
//     register double v7=0.45e308; 
//     register double v8=0.234e-308; 
//     register double v9=0.453e308; 
//     register double v10=0.423e-308;  
//     while(true)
//     {
      
        
//         double chc_div=(v1/v2)+(v3/v4)+(v5/v6)+(v7/v8)+(v9/v10)+0.6;
//         c[3]+=11;
//     }
// }

int main(){
    int total_threads;
    printf("Total number of threads to run on :");
    scanf("%i",&total_threads);
    int time;
    printf("Total time for test :");
    scanf("%i",&time);
    printf("Running tests!\n");
    fflush(stdout);
    pthread_t threads[total_threads];
    ll thread_ops[total_threads];
    for(int i=0;i<total_threads;i++)
    {
        thread_ops[i]=0;
    }
    printf("Starting fadd module!");
    for(int i=0;i<total_threads;i++)
    {   
        pthread_create(&threads[i],NULL,faddcalculator,&thread_ops[i]);
    }
    sleep(10);
    for(int i=0;i<total_threads;i++){
        pthread_cancel(threads[i]);
    }
    // printf("Starting fsub module!");
    // for(ll i=0;i<total_threads;i++)
    // {   
        
    //     pthread_create(&threads[i],NULL,fsubcalculator,NULL);
    //     pthread_join(threads[i],NULL);
    // }
    // sleep(time/4);
    // pthread_exit(NULL);
    // for(int i=0;i<total_threads;i++){
    //     pthread_cancel(threads[i]);
    // }
    // printf("Starting fmul module!");
    // for(ll i=0;i<total_threads;i++)
    // {   
       
    //     int a=pthread_create(&threads[i],NULL,fmulcalculator,NULL);
    //     pthread_join(threads[i],NULL);
    //     printf("%i",a);
    // }
    // sleep(time/4);
    // for(int i=0;i<total_threads;i++){
    //     pthread_cancel(threads[i]);
    // }
    // printf("Starting fdiv module!");
    // for(ll i=0;i<total_threads;i++)
    // {   
        
    //     pthread_create(&threads[i],NULL,fdivcalculator,NULL);
    //     pthread_join(threads[i],NULL);
    // }
    // sleep(time/4);
    // for(int i=0;i<total_threads;i++){
    //     pthread_cancel(threads[i]);
    // }
    for(int i=0;i<total_threads;i++)
        printf("%llu\n",thread_ops[i]);
    return 0;


}        