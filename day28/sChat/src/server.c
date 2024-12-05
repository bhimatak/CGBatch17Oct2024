#include "server.h"

void run_server() {
    int server_fd, client_fd, max_fd;
    struct sockaddr_in server_addr, client_addr;
    fd_set read_fds, master_fds;
    socklen_t client_len = sizeof(client_addr);
    char buffer[BUFFER_SIZE];
    int client_sockets[MAX_CLIENTS] = {0};

    // Create the server socket
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(SERVER_PORT);

    // Bind the socket to the server address
    if (bind(server_fd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("Bind failed");
        close(server_fd);
        exit(EXIT_FAILURE);
    }

    // Start listening for client connections
    if (listen(server_fd, 5) < 0) {
        perror("Listen failed");
        close(server_fd);
        exit(EXIT_FAILURE);
    }

    printf("Server listening on port %d...\n", SERVER_PORT);

    FD_ZERO(&master_fds);
    FD_SET(server_fd, &master_fds);
    max_fd = server_fd;

    while (1) {
        read_fds = master_fds;

        if (select(max_fd + 1, &read_fds, NULL, NULL, NULL) < 0) {
            perror("select() error");
            break;
        }

        // Iterate through all file descriptors to check for activity
        for (int i = 0; i <= max_fd; i++) {
            if (FD_ISSET(i, &read_fds)) {
                if (i == server_fd) {
                    // New client connection
                    if ((client_fd = accept(server_fd, (struct sockaddr *)&client_addr, &client_len)) < 0) {
                        perror("Accept failed");
                        continue;
                    }

                    // Add the new client to the master set
                    FD_SET(client_fd, &master_fds);
                    if (client_fd > max_fd) max_fd = client_fd;

                    printf("New client connected: %d\n", client_fd);
                } else {
                    // Data from an existing client
                    int bytes_received = recv(i, buffer, BUFFER_SIZE, 0);
                    if (bytes_received <= 0) {
                        // Client disconnected
                        printf("Client %d disconnected.\n", i);
                        close(i);
                        FD_CLR(i, &master_fds);
                    } else {
                        buffer[bytes_received] = '\0';
                        printf("Message from client %d: %s", i, buffer);

                        // Broadcast the message to all other clients
                        for (int j = 0; j <= max_fd; j++) {
                            if (FD_ISSET(j, &master_fds) && j != server_fd && j != i) {
                                send(j, buffer, bytes_received, 0);
                            }
                        }
                    }
                }
            }
        }
    }

    close(server_fd);
}
