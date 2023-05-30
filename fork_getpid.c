#include<stdio.h> 
#include <unistd.h> 
#include<sys/types.h> 
int main() {
	int id, childid; 
            id=getpid(); 
	if((childid=fork( ))>0) {
		printf("\nI am in the parent process %d",id); 
		printf("\nI am in the parent process %d",getpid()); 
		printf("\nI am in the parent process %d\n",getppid());
	}
	else {
		printf("\nI am in child process %d",id); 
		printf("\nI am in the child process %d",getpid());
		printf("\nI am in the child process %d\n",getppid());	
	}
}

