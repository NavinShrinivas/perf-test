//https://github.com/torvalds/test-tlb
//Above is the reference for testing logic

#include<stdio.h>
#include <sys/mman.h>

int main()//to be commented out later...for testing/dev puposes only
{
    int size,stride;
    printf("Enter size and stride : ");
    scanf("%d %d ",&size,&stride);
}

create_map(void* map, int size, int stride)
{
    map=mmap(map, size, PROT_READ|PROT_WRITE, MAP_PRIVATE | MAP_ANONYMOUS, -1,0); 
    /*the last two variables are for file mapping compared to simply the memory mapping we are trying 
    to achieve here , so -1 for file descriptor and 0 for offset if justified */
    if(map==MAP_FAILED)
        printf("Memory mapping failed, possible due to invalid match of memory size and stride");
        return 0;
    
    //so far we only have created a map , we need to fill data in this map with accordance to stride

}

int memtest(int size , int stride){
    #ifdef _WIN32   
        printf("This test unfortunately can not be run on your platform.\n");
        printf("Possible reasons : \n");
        printf("1.Your OS did not give the devs easy interface for mapping memory. *Stares at Windows*\n");
        printf("2.Your OS is MacOS , the dev does not own a MacOS to write code for it.\n");
        printf("Bye , Cya later!\n");
        return 0;
    #endif
    //lets first create a map , shall we ?
    void* map;
    create_mmap(map,size,stride)
}