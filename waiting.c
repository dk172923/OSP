#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

int main() {
    pid_t child_pid;
    int status;

    // Create a child process
    child_pid = fork();

    if (child_pid == -1) {
        perror("fork");
        exit(1);
    } else if (child_pid == 0) {
        // Child process
        printf("Child process running\n");
        printf("Child process exiting\n");
        exit(0);
    } else {
        // Parent process
        printf("Parent process waiting for child to exit\n");

        // Wait for any child process to exit
        wait(&status);
        
        printf("Parent process exiting\n");
        exit(0);
    }

    return 0;
}

