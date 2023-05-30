#include<sys/types.h> 
#include<unistd.h> 
#include<stdio.h> 
void main()
{
printf("Before execl \n"); 
execl("/bin/ls","ls",(char*)0); 
printf("After Execl\n");
}

