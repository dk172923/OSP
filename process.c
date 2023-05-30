#include <stdio.h>
#include <unistd.h>

int main() {
    pid_t pid, parent_pid;
    pid = getpid();  // Get the PID of the current process
    parent_pid = getppid();  // Get the PID of the parent process  
    printf("Current Process ID: %d\n", pid);
    printf("Parent Process ID: %d\n", parent_pid); 
    return 0;
}

