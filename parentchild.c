#include <stdio.h>
#include <unistd.h>

int main() {
    pid_t pid;
    
    pid = fork();  // Create a new process
    
    if (pid < 0) {
        fprintf(stderr, "Fork failed.\n");
        return 1;
    } else if (pid == 0) {
        printf("Child process\n");
    } else {
        printf("Parent process\n");
    }
    
    return 0;
}

