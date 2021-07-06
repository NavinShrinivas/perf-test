#include<stdio.h>
#include<pthread.h>
#include<unistd.h>
#include<stdbool.h>
#include<time.h>
#include<string.h>
#include <stdlib.h>
#include"./floatfuncs/fsub.h" //float func for subraction with tot time counter
#include"./floatfuncs/fdiv.h" //float func with division tot time counter
#include"./floatfuncs/research.h" //another float func similar to fdiv and fsub but also has a per second timer
#include"./SimpleDB/simpledb.h" //this is the libsimpldbc : a c driver for our databse called SimpleDB

typedef unsigned long long ll;


struct opscount{
    ll fsubpthread;
    ll fdivpthread;
}; 
/*struct acts as final buffer for the results, before coming to this struct each thread will store 
to an induvidual memory location using arrays*/


ll subarr[256];//a temp array to stroe values in the thread function , assumin max threads 256
ll divarr[256];
/*keeping these two as global variables, as thread funtions need these parameters
during mutithreading control is transffered from the main function hence at luck
rendering these addresses unacessible by the function leading to seg faults*/


int t;//stores the total time for testing
ll tsec[32]; //final location for operations per second
int stdflag;
int total_thread;
/*these three varaibles are in global as they are accessed by main fucntion and used for
ease of scripting*/


//custom and standard tests are handled by this function
int initfloptest(){ 
    char* garbage;//used to "presss enter to return lines"
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
    if(t<=4 || total_thread <=1 | total_thread%2!=0) //checking for invalid params from user
    {
        printf("Invalid aruguments \n");
        printf("Possible errors: \n");
        printf("[time] < 4 \n");
        printf("[threads] < 2 OR thrads not in multiples of 2 \n");
        printf("Press Enter to go back to return.");
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
    hence eventually consistency was achived using array of threads*/

    for(int i=0;i<total_thread;i++)
    {
        subarr[i]=0;
        pthread_create(&thread[i],NULL,fsubtf,&subarr[i]); 
        //creates the thread NOTE : the thread fn has a timer inbuit hence control need not be tranfered
    }
    int optime=t/4;//time per function
    for(int i=0;i<total_thread;i++)
	{
		pthread_join(thread[i],NULL);// waits for the thread to finish , finish condition being NULL
	}
    for(int i=0;i<total_thread;i++)
	{
        opcount[i].fsubpthread=subarr[i];//transferes values from temp array to struct
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
    //---------------------End of fsub test---------------------


    //---------------------Start of fdiv test---------------------

    /*Using of multiple buffers and array of locations the working threads write to is cus of race
    conditions , one it felt neats this way , and of there was somesort of caching or atomic system
    making all the threads add on rapidly to a single memory location will ofc lead to counting problem
    hence eventually consistency was achived using array of threads*/

    for(int i=0;i<total_thread;i++)
    {
        divarr[i]=0;
        pthread_create(&thread[i],NULL,fdivtf,&divarr[i]);
        //creates the thread | NOTE : the thread fn has a timer inbuit hence control need not be tranfered
    }
    for(int i=0;i<total_thread;i++)
	{
		pthread_join(thread[i],NULL);// waits for the thread to finish , finish condition being NULL
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
    //---------------------End of fdiv test---------------------


    //all the stuff above "the two test" are run if the user selects a custom test
    //the ones below is executed if user selects stdtest, hence the flag
    //I could have made it a seperate function , but the similarities between custom and std test are 
    //high
    /*this flag mainly sets the time and number of cores , and takes care of uploading results to 
    database and also retrive data and display them*/
    if(stdflag)  
    {
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
        dbwrite("http://192.168.1.51:3000/","username","password",data); //invoking from from libsimpledbc
        char option[3];
        char accept[]="Y";
        printf("Do u want to see rankings?[Y/N] : ");
        scanf("%[^\n]%*c",option);
        if(strcmp(option,accept)==0)
        {
            dbread("http://192.168.1.51:3000/","stdtest","password","leaderboard.txt");
            char cwd[1000];
            getcwd(cwd,sizeof(cwd));
            printf("Results flushed to %s/leaderboards.txt \n",cwd);
        }
    }
    printf("Press Enter to go back to return.");
    scanf("%c",&garbage);
    scanf("%c",&garbage);   
    fflush(stdout);
    fflush(stdin);
}


//this function is tailor made for research and spec sheets
int research(){
    char* garbage;
    ll tsecbuffer[12]; 
    /*had to make this an array due to stupid behviours due to race conditions 
    and trying to achive eventual consistency.*/

    pthread_t thread[total_thread];
    printf("Running test for %i seconds on %d threads!\n",t,total_thread);
    ll tsecbuffer2;
    for(int j=0;j<30;j++)
    {
        if(j==0)
            tsec[j]=0;
        else{
        int temp = tsecbuffer2/1000000000;
        tsec[j]=temp;
        }
        for(int i=0;i<total_thread;i++)
        {
            tsecbuffer[i]=0;
            pthread_create(&thread[i],NULL,researchtf,&tsecbuffer[i]); //creates the thread
            //this threadfn has a 1 second timer
        }
        for(int i=0;i<total_thread;i++)
	    {
		    pthread_join(thread[i],NULL);// waits for the thread fo finish , finish condition being NULL
	    }
        tsecbuffer2=0;
        for(int i=0;i<12;i++)
        {
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
    {
        fprintf(f,"%d %lli\n",i*2,tsec[i]);
    }
    fclose(f);
    sleep(3);
    char cwd[1000];
    getcwd(cwd,sizeof(cwd));
    printf("Results flushed to %s/results.txt \n",cwd);
    printf("Graphs stored and rendered!\n");
    /*we should have this part plotting data from "results.txt"*/
    //not coded yet
    printf("Press Enter to go back to return.");
    scanf("%c",&garbage);
    scanf("%c",&garbage);   
    fflush(stdout);
    fflush(stdin);

}

