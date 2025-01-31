/*
a TCP socket client to test
pre-http version of server.c
*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <arpa/inet.h>

int main()
{
    // Create socket
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);

    // Set up server address
    struct sockaddr_in addr;
    addr.sin_family = AF_INET;
    addr.sin_port = htons(8080);
    addr.sin_addr.s_addr = inet_addr("127.0.0.1");

    // Connect to the server
    connect(sockfd, (struct sockaddr *)&addr, sizeof(addr));
    printf("Connected to server!\n");

    // Receive data from the server
    char buf[1024] = {0};
    recv(sockfd, buf, sizeof(buf), 0);
    printf("Received from server: %s\n", buf);

    // Close the socket
    close(sockfd);
    printf("Client socket closed.\n");

    return 0;
}