#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/wait.h>
int main( )
{
	int i, pid; 
	pid = fork( ); 
	if ( pid == -1 )
	{
		printf("Fork failed"); 
		exit (0);
	}
	else if (pid==0)
	{
		printf("\nChild process starts"); 
		for(i=0; i<5; i++)
		{
			printf("\nChild process %d is called", i);
		}
		printf("\nChild process ends");
	}
	else 
	{
		wait (0);
		printf("\nParent process ends\n");
	}
	exit (0);
}

