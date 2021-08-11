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
#include<pthread.h>
#include<unistd.h>
#include<stdbool.h>
#include<time.h>
#include<string.h>
#include<stdlib.h>

#include"./fsub.h" //float func for subraction with tot time counter
#include"./fdiv.h" //float func with division tot time counter
#include"./research.h" //another float func similar to fdiv and fsub but also has a per second timer
#include"../SimpleDB/simpledb.h" //this is the libsimpldbc : a c driver for our databse called SimpleDB

typedef unsigned long long ll;


struct opscount{
    ll fsubpthread;
    ll fdivpthread;
}; 
/*struct acts as final buffer for the results, before coming to this struct each thread will store 
to an individual memory location using arrays*/


ll subarr[256];//a temp array to store values in the thread function , assuming max threads 256
ll divarr[256];
/*keeping these two as global variables, as thread funtions need these parameters
during mutithreading control is transffered from the main function hence at luck
rendering these addresses unaccessible by the function leading to seg faults*/


int t;//stores the total time for testing
ll tsec[32]; //final location for operations per second
int stdflag;
int total_thread;
/*these three variables are in global as they are accessed by main function and used for
ease of scripting*/


//custom and standard tests are handled by this function
int initfloptest(){ 
    char* garbage;//used to "presss enter to return lines"
    if(total_thread==0){    //for optional menu options!
        printf("Enter total number of threads : ");
        scanf("%i",&total_thread);
    }
    if(t==0){   //optional menu options!
        printf("Time to run the test [Seconds] : ");
        scanf("%i",&t);
    }
    if(t<=4 || total_thread <=1 | total_thread%2!=0){   //checking for invalid params from user
        printf("Invalid arguments \n");
        printf("Possible errors: \n");
        printf("[time] < 4 \n");
        printf("[threads] < 2 OR threads not in multiples of 2 \n");
        printf("Press Enter to go back or return.");
        scanf("%c",&garbage);
        scanf("%c",&garbage);   
        return 0;
    }
    printf("Running test for %i seconds on %d threads!\n",t,total_thread);
    fflush(stdout);

    //==========creating our array of threads==========
    struct opscount opcount[total_thread];
    pthread_t thread[total_thread];


    //---------------------Start of fsub test----------------------------------

    /*Using of multiple buffers and array of locations the working threads write to is cus of race
    conditions , one it felt neats this way , and of there was somesort of caching or atomic system
    making all the threads add on rapidly to a single memory location will ofc lead to counting problem
    hence eventually consistency was achieved using array of threads*/

    for(int i=0;i<total_thread;i++){
        subarr[i]=0;
        pthread_create(&thread[i],NULL,fsubtf,&subarr[i]); 
        //creates the thread NOTE : the thread fn has a timer inbuilt hence control need not be transferred
    }
    int optime=t/4;//time per function

    for(int i=0;i<total_thread;i++)
		pthread_join(thread[i],NULL);// waits for the thread to finish , finish condition being NULL

    for(int i=0;i<total_thread;i++)
        opcount[i].fsubpthread=subarr[i];//transfers values from temp array to struct

    ll totalfsub=0;
    ll maxfsub=0;
    for(int i=0;i<total_thread;i++){
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
    //---------------------End of fsub test---------------------


    //---------------------Start of fdiv test---------------------

    /*Using of multiple buffers and array of locations the working threads write to is cus of race
    conditions , one it felt neats this way , and of there was somesort of caching or atomic system
    making all the threads add on rapidly to a single memory location will ofc lead to counting problem
    hence eventually consistency was achieved using array of threads*/

    for(int i=0;i<total_thread;i++){
        divarr[i]=0;
        pthread_create(&thread[i],NULL,fdivtf,&divarr[i]);
        //creates the thread | NOTE : the thread fn has a timer inbuilt hence control need not be transferred
    }
    for(int i=0;i<total_thread;i++)
		pthread_join(thread[i],NULL);// waits for the thread to finish , finish condition being NULL

    for(int i=0;i<total_thread;i++)
        opcount[i].fdivpthread=divarr[i];//transfers values from temp array to struct

    ll totalfdiv=0;
    ll maxfdiv=0;
    for(int i=0;i<total_thread;i++){
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
    //---------------------End of fdiv test---------------------


    //all the stuff above "the two test" are run if the user selects a custom test
    //the ones below is executed if user selects stdtest, hence the flag
    //I could have made it a separate function , but the similarities between custom and std test are 
    //high
    /*this flag mainly sets the time and number of cores , and takes care of uploading results to 
    database and also retrive data and display them*/
    if(stdflag)  {
        char data[3000];
        char cpu[200];
        fflush(stdin);
        fflush(stdout);
        printf("Enter CPU Name [ENTER MODEL NUMBER ONLY WITH NO SPACE]:");
        scanf(" %[^\n]%*c",cpu);
        strcat(data,cpu);
        int testresult=(fdivgflop/3)+(fsubgflop/1.5);
        char res[100];
        sprintf(res, "%d",testresult);
        strcat(data,",");
        strcat(data,res);
        char accept[]="Y";
        char option1[3];
        printf("Results : %s\n",data);
        printf("Do you want to upload these results to the web?[Y/N] : ");
        scanf("%[^\n]%*c",option1);
        if(strcmp(option1,accept)==0)
            dbwrite("http://navin.works:8080/","stdtest","*",data); //invoking from from libsimpledbc

        char option2[3];
        printf("Do you want to see rankings?[Y/N] : ");
        scanf("%[^\n]%*c",option2);
        if(strcmp(option2,accept)==0){
            // dbread("http://navin.works:8080/","stdtest","*","STDOUT");
            dbread("http://navin.works:8080/","stdtest","*","leaderboard.txt");
            
            /*Leaderboard.txt needs sorting and has to be displayed to terminal*/

            char cwd[1000];
            getcwd(cwd,sizeof(cwd));
            printf("Results flushed to %s/leaderboards.txt \n",cwd);
        }
    }
    printf("Press Enter to go back or return.");
    scanf("%c",&garbage);  
    fflush(stdout);
    fflush(stdin);
}


//this function is tailor made for research and spec sheets
int research(){
    char* garbage;
    ll tsecbuffer[12]; 
    /*had to make this an array due to stupid behaviour due to race conditions 
    and trying to achieve eventual consistency.*/

    pthread_t thread[total_thread];
    printf("Running test for %i seconds on %d threads!\n",t,total_thread);
    ll tsecbuffer2;
    for(int j=0;j<30;j++){
        if(j==0)
            tsec[j]=0;
        else{
            int temp = tsecbuffer2/1000000000;
            tsec[j]=temp;
        }
        for(int i=0;i<total_thread;i++){
            tsecbuffer[i]=0;
            pthread_create(&thread[i],NULL,researchtf,&tsecbuffer[i]); //creates the thread
            //this threadfn has a 1 second timer
        }
        for(int i=0;i<total_thread;i++)
		    pthread_join(thread[i],NULL);// waits for the thread fo finish , finish condition being NULL
    
        tsecbuffer2=0;
        for(int i=0;i<12;i++){
            tsecbuffer2+=tsecbuffer[i];
            tsecbuffer[i]=0;
        }
    }
    FILE* f=fopen("result.txt","w+");
    fclose(f);
    f=fopen("result.txt","w");
    printf("Flushing data to file...\n");
    fflush(stdout);
    fflush(stdin);
    for(int i=0;i<30;i++)
        fprintf(f,"%d %lli\n",i*2,tsec[i]);

    fclose(f);
    sleep(3);
    char cwd[1000];
    getcwd(cwd,sizeof(cwd));
    printf("Results flushed to %s/results.txt \n",cwd);
    printf("Graphs stored and rendered!\n");
    /*we should have this part plotting data from "results.txt"*/
    //not coded yet
    printf("Press Enter to go back or return.");
    scanf("%c",&garbage);
    fflush(stdout);
    fflush(stdin);
}

