#include<stdio.h>
#include<string.h> 
#define msgsize 29 
int main()
{
	int ser[2], cli[2], pid; 
	char inbuff[msgsize];
	char *msg="Thank you";
	system("clear"); 
	pipe(ser);
	pipe(cli);
	printf("\nServer read id = %d, write id = %d", ser[0], ser[1]); 
	printf("\nClient read id = %d, write id = %d", cli[0], cli[1]); 
	pid=fork();
	if(pid==0)
	{
		printf("\nI am in child process !"); 
		close(cli[0]);
		close(ser[1]); 
		write(cli[1],msg,msgsize);
		printf("\nMessage written to pipe..!"); 
		sleep(2);
		read(ser[0], inbuff,msgsize);
		printf("\nEcho message received from server"); 
		printf("\n %s",inbuff);
	}
	else
	{
		close(cli[1]);
		close(ser[0]);
		printf("\nParent process"); 
		read(cli[0],inbuff,msgsize);
		write(ser[1], inbuff,msgsize); 
		printf("\nParent ended!\n");
	}
}

