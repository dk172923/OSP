#include<sys/ipc.h>
#include<sys/types.h>
#include<stdio.h>
#include<string.h> 
#include<sys/msg.h> 
#include<stdlib.h> 
struct
{
	long mtype; 
	char mtext[20];
} send, recv;
int main()
{
	int qid, pid, len; 
	qid = msgget((key_t)0X2000,IPC_CREAT|0666); 
	
	if(qid==-1)
	{
		perror("\nMessage failed"); exit(1);
	}
	send.mtype=1;
	strcpy(send.mtext,"\nHello, I am parent\n"); 
	len=strlen(send.mtext);
	pid=fork(); 
	if(pid>0)
	{
		if(msgsnd(qid, &send, len, 0) == -1)
		{
			perror("\nMessage sending failed"); 
			exit(1);
		}
		printf("\nMessage has been posted"); 
		sleep(2);
		if(msgrcv (qid, &recv, 100, 2, 0) == -1)
		{
			perror("\n msgrcv error "); 
			exit(1);
		}
		printf("\nMessage received from child - %s\n",recv.mtext);
	}
	else
	{
		send.mtype=2;
		strcpy(send.mtext,"\nHi, I am child"); 
		len=strlen(send.mtext); 

		if(msgrcv(qid, &recv, 100, 1, 0) == -1)
		{
 			perror("\nChild message received failed"); 
			exit(1);
		}
		if(msgsnd (qid, &send, len, 0) == -1)
		{
			perror("\nChild message send failed");
		}
		printf("\nReceived from parent - %s", recv.mtext);
	} 
}

