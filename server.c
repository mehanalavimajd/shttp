#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <arpa/inet.h>
#include "src/recieveHTTP.c"

int main()
{
    // Create socket
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);

    int opt = 1;
    if (setsockopt(sockfd, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt)) < 0)
    {
        perror("setsockopt failed");
        close(sockfd);
        exit(EXIT_FAILURE);
    }
    // Set up server address
    struct sockaddr_in addr;
    addr.sin_family = AF_INET;
    addr.sin_port = htons(8080);
    addr.sin_addr.s_addr = inet_addr("127.0.0.1"); // Bind to localhost only

    // Bind socket to address
    bind(sockfd, (struct sockaddr *)&addr, sizeof(addr));

    // Listen for incoming connections
    listen(sockfd, 10);
    printf("Server listening on port 8080...\n");

    // Accept a new connection
    struct sockaddr_in clientAddr;
    socklen_t clientAddrLen = sizeof(clientAddr);
    int cliendSockfd = accept(sockfd, (struct sockaddr *)&clientAddr, &clientAddrLen);
    printf("Client connected!\n");
    // Send data to the client;
    char buf[2000];
    receiveHTTP(cliendSockfd, buf, 2000, 0);


    // Close the client socket
    close(cliendSockfd);
    // printf("Client socket closed.\n");

    // // Close the server socket
    close(sockfd);
    // printf("Server soket closed.\n");

    return 0;
}