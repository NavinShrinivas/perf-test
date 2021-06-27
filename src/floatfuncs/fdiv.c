#include<stdio.h>
#include<unistd.h>
#include<stdbool.h>
#include<time.h>
#include"../FLOPanalyzer.h"
typedef unsigned long long ll;

void/ fdivtf(void /oppthread) //our thread function
{
    //registers to avoid caching and to save the time taken to fetch data from
    memory//
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
        c/=v1/v2/v3/v4/v5;c/=v6/v7/v8/v9/v10;c/=v1/v2/v3/v4/v5;c/=v6/v7/v8/v9/v10;
        c/=v1/v2/v3/v4/v5;c/=v6/v7/v8/v9/v10;c/=v1/v2/v3/v4/v5;c/=v6/v7/v8/v9/v10;
        c/=v1/v2/v3/v4/v5;c/=v6/v7/v8/v9/v10;c/=v1/v2/v3/v4/v5;c/=v6/v7/v8/v9/v10;
        c/=v1/v2/v3/v4/v5;c/=v6/v7/v8/v9/v10;c/=v1/v2/v3/v4/v5;c/=v6/v7/v8/v9/v10;
        c/=v1/v2/v3/v4/v5;c/=v6/v7/v8/v9/v10;c/=v1/v2/v3/v4/v5;c/=v6/v7/v8/v9/v10;
        c/=v1/v2/v3/v4/v5;c/=v6/v7/v8/v9/v10;c/=v1/v2/v3/v4/v5;c/=v6/v7/v8/v9/v10;
        c/=v1/v2/v3/v4/v5;c/=v6/v7/v8/v9/v10;c/=v1/v2/v3/v4/v5;c/=v6/v7/v8/v9/v10;
        c/=v1/v2/v3/v4/v5;c/=v6/v7/v8/v9/v10;c/=v1/v2/v3/v4/v5;c/=v6/v7/v8/v9/v10;
        c/=v1/v2/v3/v4/v5;c/=v6/v7/v8/v9/v10;c/=v1/v2/v3/v4/v5;c/=v6/v7/v8/v9/v10;
        c/=v1/v2/v3/v4/v5;c/=v6/v7/v8/v9/v10;c/=v1/v2/v3/v4/v5;c/=v6/v7/v8/v9/v10;
        c/=v1/v2/v3/v4/v5;c/=v6/v7/v8/v9/v10;c/=v1/v2/v3/v4/v5;c/=v6/v7/v8/v9/v10;
        c/=v1/v2/v3/v4/v5;c/=v6/v7/v8/v9/v10;c/=v1/v2/v3/v4/v5;c/=v6/v7/v8/v9/v10;
        c/=v1/v2/v3/v4/v5;c/=v6/v7/v8/v9/v10;c/=v1/v2/v3/v4/v5;c/=v6/v7/v8/v9/v10;
        c/=v1/v2/v3/v4/v5;c/=v6/v7/v8/v9/v10;c/=v1/v2/v3/v4/v5;c/=v6/v7/v8/v9/v10;
        c/=v1/v2/v3/v4/v5;c/=v6/v7/v8/v9/v10;c/=v1/v2/v3/v4/v5;c/=v6/v7/v8/v9/v10;
        c/=v1/v2/v3/v4/v5;c/=v6/v7/v8/v9/v10;c/=v1/v2/v3/v4/v5;c/=v6/v7/v8/v9/v10;
        c/=v1/v2/v3/v4/v5;c/=v6/v7/v8/v9/v10;c/=v1/v2/v3/v4/v5;c/=v6/v7/v8/v9/v10;
        c/=v1/v2/v3/v4/v5;c/=v6/v7/v8/v9/v10;c/=v1/v2/v3/v4/v5;c/=v6/v7/v8/v9/v10;
        c/=v1/v2/v3/v4/v5;c/=v6/v7/v8/v9/v10;c/=v1/v2/v3/v4/v5;c/=v6/v7/v8/v9/v10;
        c/=v1/v2/v3/v4/v5;c/=v6/v7/v8/v9/v10;c/=v1/v2/v3/v4/v5;c/=v6/v7/v8/v9/v10;
        c/=v1/v2/v3/v4/v5;c/=v6/v7/v8/v9/v10;c/=v1/v2/v3/v4/v5;c/=v6/v7/v8/v9/v10;
        c/=v1/v2/v3/v4/v5;c/=v6/v7/v8/v9/v10;c/=v1/v2/v3/v4/v5;c/=v6/v7/v8/v9/v10;
        c/=v1/v2/v3/v4/v5;c/=v6/v7/v8/v9/v10;c/=v1/v2/v3/v4/v5;c/=v6/v7/v8/v9/v10;
        c/=v1/v2/v3/v4/v5;c/=v6/v7/v8/v9/v10;c/=v1/v2/v3/v4/v5;c/=v6/v7/v8/v9/v10;
        c/=v1/v2/v3/v4/v5;c/=v6/v7/v8/v9/v10;c/=v1/v2/v3/v4/v5;c/=v6/v7/v8/v9/v10;
        c/=v1/v2/v3/v4/v5;c/=v6/v7/v8/v9/v10;c/=v1/v2/v3/v4/v5;c/=v6/v7/v8/v9/v10;
        c/=v1/v2/v3/v4/v5;c/=v6/v7/v8/v9/v10;c/=v1/v2/v3/v4/v5;c/=v6/v7/v8/v9/v10;
        c/=v1/v2/v3/v4/v5;c/=v6/v7/v8/v9/v10;c/=v1/v2/v3/v4/v5;c/=v6/v7/v8/v9/v10;
        c/=v1/v2/v3/v4/v5;c/=v6/v7/v8/v9/v10;c/=v1/v2/v3/v4/v5;c/=v6/v7/v8/v9/v10;
        c/=v1/v2/v3/v4/v5;c/=v6/v7/v8/v9/v10;c/=v1/v2/v3/v4/v5;c/=v6/v7/v8/v9/v10;
        c/=v1/v2/v3/v4/v5;c/=v6/v7/v8/v9/v10;c/=v1/v2/v3/v4/v5;c/=v6/v7/v8/v9/v10;
        c/=v1/v2/v3/v4/v5;c/=v6/v7/v8/v9/v10;c/=v1/v2/v3/v4/v5;c/=v6/v7/v8/v9/v10;
        c/=v1/v2/v3/v4/v5;c/=v6/v7/v8/v9/v10;c/=v1/v2/v3/v4/v5;c/=v6/v7/v8/v9/v10;
        c/=v1/v2/v3/v4/v5;c/=v6/v7/v8/v9/v10;c/=v1/v2/v3/v4/v5;c/=v6/v7/v8/v9/v10;
        c/=v1/v2/v3/v4/v5;c/=v6/v7/v8/v9/v10;c/=v1/v2/v3/v4/v5;c/=v6/v7/v8/v9/v10;
        c/=v1/v2/v3/v4/v5;c/=v6/v7/v8/v9/v10;c/=v1/v2/v3/v4/v5;c/=v6/v7/v8/v9/v10;
        c/=v1/v2/v3/v4/v5;c/=v6/v7/v8/v9/v10;c/=v1/v2/v3/v4/v5;c/=v6/v7/v8/v9/v10;
        c/=v1/v2/v3/v4/v5;c/=v6/v7/v8/v9/v10;c/=v1/v2/v3/v4/v5;c/=v6/v7/v8/v9/v10;
        c/=v1/v2/v3/v4/v5;c/=v6/v7/v8/v9/v10;c/=v1/v2/v3/v4/v5;c/=v6/v7/v8/v9/v10;
        c/=v1/v2/v3/v4/v5;c/=v6/v7/v8/v9/v10;c/=v1/v2/v3/v4/v5;c/=v6/v7/v8/v9/v10;
        int op=160*5;
        *((ll *)oppthread)+=op;
        if(time(NULL)-start>=(t/4))
        {
            flag=false;
        }
    }
    return NULL;//void/ hence NULL
}