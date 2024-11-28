#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main() {
    pid_t pid = fork();

    if (pid < 0) {
        // Fork failed
        perror("fork failed");
        exit(1);
    } else if (pid == 0) {
        // Child process
        printf("Child process (PID: %d) is exiting...\n", getpid());
        exit(0);  // Child exits immediately
    } else {
        // Parent process
        printf("Parent process (PID: %d) created a child process (PID: %d)\n", getpid(), pid);
        
        // Sleep to keep the child as a zombie for 10 seconds
        printf("Parent process sleeping for 10 seconds...\n");
        sleep(40);

        // Check zombie process with `ps` command during this sleep
        // Example: run in terminal `ps aux | grep Z`

        // Finally, parent reaps the child to remove the zombie state
        wait(NULL);
        printf("Parent process reaped the child process (PID: %d)\n", pid);
    }

    return 0;
}
