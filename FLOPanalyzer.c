#include<stdio.h>
#include<pthread.h>
#include <unistd.h>
typedef long long int ll;

struct test{
    ll ops;
    ll thread;
};
void *testfunc(void* struc)//just to test the multithreading operations
{
    ((struct test*)struc)->ops=0;
    while(1)
    {
        double a=0.2324234+0.2353465465+0.2423+7.34543+7.23423;
        ((struct test*)struc)->ops+=5;
    }
}
ll main(){
    ll tot;
    printf("Total number of threads to run on :");
    scanf("%i",&tot);
    pthread_t threads[tot];
    struct test test1[tot];
    for(ll i=0;i<tot;i++)
    {
        ((struct test*)test1+i)->thread=i;
        pthread_create(&threads[i],NULL,testfunc,test1+i);
    }
    sleep(20);
    for(ll i=0;i<tot;i++){
        printf("%ist threads ops value : %i\n",((struct test*)test1+i)->thread,((struct test*)test1+i)->ops);
        pthread_cancel(threads[i]);
    }
    }
        