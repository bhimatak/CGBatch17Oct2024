#include "client.h"

void run_client(const char *server_ip) {
    int sockfd;
    struct sockaddr_in server_addr;
    fd_set read_fds;
    char buffer[BUFFER_SIZE];

    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(SERVER_PORT);
    inet_pton(AF_INET, server_ip, &server_addr.sin_addr);

    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("Connection failed");
        close(sockfd);
        exit(EXIT_FAILURE);
    }

    printf("Connected to the chat server. Start typing:\n");

    while (1) {
        FD_ZERO(&read_fds);
        FD_SET(STDIN_FILENO, &read_fds);
        FD_SET(sockfd, &read_fds);

        if (select(sockfd + 1, &read_fds, NULL, NULL, NULL) < 0) {
            perror("select() error");
            break;
        }

        if (FD_ISSET(STDIN_FILENO, &read_fds)) {
            fgets(buffer, BUFFER_SIZE, stdin);
            send(sockfd, buffer, strlen(buffer), 0);
        }

        if (FD_ISSET(sockfd, &read_fds)) {
            int bytes_received = recv(sockfd, buffer, BUFFER_SIZE, 0);
            if (bytes_received <= 0) {
                printf("Server disconnected.\n");
                break;
            }
            buffer[bytes_received] = '\0';
            printf("Message: %s", buffer);
        }
    }

    close(sockfd);
}
