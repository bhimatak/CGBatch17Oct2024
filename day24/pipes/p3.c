#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include <stdlib.h>

// Signal handler for SIGPIPE
void handle_sigpipe(int sig) {
    printf("Caught SIGPIPE signal %d. Attempted to write to a closed pipe.\n", sig);
    exit(EXIT_FAILURE); // Exit gracefully after handling the signal
}

int main() {
    int pipe_fds[2]; // Array to hold the file descriptors for the pipe
    pid_t pid;
    
    // Create a pipe
    if (pipe(pipe_fds) == -1) {
        perror("pipe");
        exit(EXIT_FAILURE);
    }

    // Set up the SIGPIPE handler
    signal(SIGPIPE, handle_sigpipe);

    // Fork a child process
    pid = fork();
    if (pid < 0) {
        perror("fork");
        exit(EXIT_FAILURE);
    } else if (pid == 0) {
        // Child process - Close the reading end and exit immediately
        close(pipe_fds[0]);  // Close the read end
        close(pipe_fds[1]);  // Close the write end
        exit(0);             // Exit immediately
    } else {
        // Parent process
        close(pipe_fds[0]);  // Close the read end

        sleep(1);  // Give child time to exit and close the pipe

        // Try writing to the pipe
        printf("Parent: Attempting to write to a closed pipe.\n");
        if (write(pipe_fds[1], "Hello, World!", 13) == -1) {
            perror("write");  // This will trigger SIGPIPE if write fails
        }
        
        // Close the write end after use
        close(pipe_fds[1]);
    }

    return 0;
}
