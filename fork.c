#include  <stdio.h> 
#include <unistd.h> 
#include  <sys/types.h> 
int main()
{
    int id,childid; 
    id=getpid(); 
    if((childid=fork())>0)
    {
        printf("\n I am in the parent process %d",id); 
        printf("\n I am in the parent process %d",getpid()); 
        printf("\n I am in the parent process %d\n",getppid());
    }
    else
    {
        printf("\n I am in child process %d",id); 
        printf("\n I am in the child process %d",getpid());
        printf("\n I am in the child process %d",getppid());
    }
    return 0;
}
 






