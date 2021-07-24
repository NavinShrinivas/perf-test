/**********************************************************************************
                  __ _              _ 
 _ __   ___ _ __ / _| |_ ___   ___ | |
| '_ \ / _ \ '__| |_| __/ _ \ / _ \| |
| |_) |  __/ |  |  _| || (_) | (_) | |
| .__/ \___|_|  |_|  \__\___/ \___/|_|
|_|  

Copyright (c) 2021 P K Navin Shrinivas

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
**********************************************************************************/
#include<stdio.h>
#include<unistd.h>
#include<stdbool.h>
#include<time.h>
#include"../FLOPanalyzer.h"
typedef unsigned long long ll;

void* researchtf(void *oppthread) //our thread function
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
        c*=(v1+v2-v3+v4)/v5;c*=(v1+v2-v3+v4)/v5;c*=(v1+v2-v3+v4)/v5;c*=(v1+v2-v3+v4)/v5;
        c*=(v1+v2-v3+v4)/v5;c*=(v1+v2-v3+v4)/v5;c*=(v1+v2-v3+v4)/v5;c*=(v1+v2-v3+v4)/v5;
        c*=(v1+v2-v3+v4)/v5;c*=(v1+v2-v3+v4)/v5;c*=(v1+v2-v3+v4)/v5;c*=(v1+v2-v3+v4)/v5;
        c*=(v1+v2-v3+v4)/v5;c*=(v1+v2-v3+v4)/v5;c*=(v1+v2-v3+v4)/v5;c*=(v1+v2-v3+v4)/v5;
        c*=(v1+v2-v3+v4)/v5;c*=(v1+v2-v3+v4)/v5;c*=(v1+v2-v3+v4)/v5;c*=(v1+v2-v3+v4)/v5;
        c*=(v1+v2-v3+v4)/v5;c*=(v1+v2-v3+v4)/v5;c*=(v1+v2-v3+v4)/v5;c*=(v1+v2-v3+v4)/v5;
        c*=(v1+v2-v3+v4)/v5;c*=(v1+v2-v3+v4)/v5;c*=(v1+v2-v3+v4)/v5;c*=(v1+v2-v3+v4)/v5;
        c*=(v1+v2-v3+v4)/v5;c*=(v1+v2-v3+v4)/v5;c*=(v1+v2-v3+v4)/v5;c*=(v1+v2-v3+v4)/v5;
        c*=(v1+v2-v3+v4)/v5;c*=(v1+v2-v3+v4)/v5;c*=(v1+v2-v3+v4)/v5;c*=(v1+v2-v3+v4)/v5;
        c*=(v1+v2-v3+v4)/v5;c*=(v1+v2-v3+v4)/v5;c*=(v1+v2-v3+v4)/v5;c*=(v1+v2-v3+v4)/v5;
        c*=(v1+v2-v3+v4)/v5;c*=(v1+v2-v3+v4)/v5;c*=(v1+v2-v3+v4)/v5;c*=(v1+v2-v3+v4)/v5;
        c*=(v1+v2-v3+v4)/v5;c*=(v1+v2-v3+v4)/v5;c*=(v1+v2-v3+v4)/v5;c*=(v1+v2-v3+v4)/v5;
        c*=(v1+v2-v3+v4)/v5;c*=(v1+v2-v3+v4)/v5;c*=(v1+v2-v3+v4)/v5;c*=(v1+v2-v3+v4)/v5;
        c*=(v1+v2-v3+v4)/v5;c*=(v1+v2-v3+v4)/v5;c*=(v1+v2-v3+v4)/v5;c*=(v1+v2-v3+v4)/v5;
        c*=(v1+v2-v3+v4)/v5;c*=(v1+v2-v3+v4)/v5;c*=(v1+v2-v3+v4)/v5;c*=(v1+v2-v3+v4)/v5;
        c*=(v1+v2-v3+v4)/v5;c*=(v1+v2-v3+v4)/v5;c*=(v1+v2-v3+v4)/v5;c*=(v1+v2-v3+v4)/v5;
        c*=(v1+v2-v3+v4)/v5;c*=(v1+v2-v3+v4)/v5;c*=(v1+v2-v3+v4)/v5;c*=(v1+v2-v3+v4)/v5;
        c*=(v1+v2-v3+v4)/v5;c*=(v1+v2-v3+v4)/v5;c*=(v1+v2-v3+v4)/v5;c*=(v1+v2-v3+v4)/v5;
        c*=(v1+v2-v3+v4)/v5;c*=(v1+v2-v3+v4)/v5;c*=(v1+v2-v3+v4)/v5;c*=(v1+v2-v3+v4)/v5;
        c*=(v1+v2-v3+v4)/v5;c*=(v1+v2-v3+v4)/v5;c*=(v1+v2-v3+v4)/v5;c*=(v1+v2-v3+v4)/v5;
        c*=(v1+v2-v3+v4)/v5;c*=(v1+v2-v3+v4)/v5;c*=(v1+v2-v3+v4)/v5;c*=(v1+v2-v3+v4)/v5;
        c*=(v1+v2-v3+v4)/v5;c*=(v1+v2-v3+v4)/v5;c*=(v1+v2-v3+v4)/v5;c*=(v1+v2-v3+v4)/v5;
        c*=(v1+v2-v3+v4)/v5;c*=(v1+v2-v3+v4)/v5;c*=(v1+v2-v3+v4)/v5;c*=(v1+v2-v3+v4)/v5;
        c*=(v1+v2-v3+v4)/v5;c*=(v1+v2-v3+v4)/v5;c*=(v1+v2-v3+v4)/v5;c*=(v1+v2-v3+v4)/v5;
        c*=(v1+v2-v3+v4)/v5;c*=(v1+v2-v3+v4)/v5;c*=(v1+v2-v3+v4)/v5;c*=(v1+v2-v3+v4)/v5;
        c*=(v1+v2-v3+v4)/v5;c*=(v1+v2-v3+v4)/v5;c*=(v1+v2-v3+v4)/v5;c*=(v1+v2-v3+v4)/v5;
        c*=(v1+v2-v3+v4)/v5;c*=(v1+v2-v3+v4)/v5;c*=(v1+v2-v3+v4)/v5;c*=(v1+v2-v3+v4)/v5;
        c*=(v1+v2-v3+v4)/v5;c*=(v1+v2-v3+v4)/v5;c*=(v1+v2-v3+v4)/v5;c*=(v1+v2-v3+v4)/v5;
        c*=(v1+v2-v3+v4)/v5;c*=(v1+v2-v3+v4)/v5;c*=(v1+v2-v3+v4)/v5;c*=(v1+v2-v3+v4)/v5;
        c*=(v1+v2-v3+v4)/v5;c*=(v1+v2-v3+v4)/v5;c*=(v1+v2-v3+v4)/v5;c*=(v1+v2-v3+v4)/v5;
        c*=(v1+v2-v3+v4)/v5;c*=(v1+v2-v3+v4)/v5;c*=(v1+v2-v3+v4)/v5;c*=(v1+v2-v3+v4)/v5;
        c*=(v1+v2-v3+v4)/v5;c*=(v1+v2-v3+v4)/v5;c*=(v1+v2-v3+v4)/v5;c*=(v1+v2-v3+v4)/v5;
        c*=(v1+v2-v3+v4)/v5;c*=(v1+v2-v3+v4)/v5;c*=(v1+v2-v3+v4)/v5;c*=(v1+v2-v3+v4)/v5;
        c*=(v1+v2-v3+v4)/v5;c*=(v1+v2-v3+v4)/v5;c*=(v1+v2-v3+v4)/v5;c*=(v1+v2-v3+v4)/v5;
        c*=(v1+v2-v3+v4)/v5;c*=(v1+v2-v3+v4)/v5;c*=(v1+v2-v3+v4)/v5;c*=(v1+v2-v3+v4)/v5;
        c*=(v1+v2-v3+v4)/v5;c*=(v1+v2-v3+v4)/v5;c*=(v1+v2-v3+v4)/v5;c*=(v1+v2-v3+v4)/v5;
        c*=(v1+v2-v3+v4)/v5;c*=(v1+v2-v3+v4)/v5;c*=(v1+v2-v3+v4)/v5;c*=(v1+v2-v3+v4)/v5;
        c*=(v1+v2-v3+v4)/v5;c*=(v1+v2-v3+v4)/v5;c*=(v1+v2-v3+v4)/v5;c*=(v1+v2-v3+v4)/v5;
        c*=(v1+v2-v3+v4)/v5;c*=(v1+v2-v3+v4)/v5;c*=(v1+v2-v3+v4)/v5;c*=(v1+v2-v3+v4)/v5;
        c*=(v1+v2-v3+v4)/v5;c*=(v1+v2-v3+v4)/v5;c*=(v1+v2-v3+v4)/v5;c*=(v1+v2-v3+v4)/v5;
        c*=(v1+v2-v3+v4)/v5;c*=(v1+v2-v3+v4)/v5;c*=(v1+v2-v3+v4)/v5;c*=(v1+v2-v3+v4)/v5;
        int op=160*5;
        *((ll *)oppthread)+=op;
        if(time(NULL)-start>=2)
        {
            flag=false;
        }
    }
    return NULL;//void/ hence NULL
}