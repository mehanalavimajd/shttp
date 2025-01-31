/*
recv.c:

receives and handle a http request



*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <arpa/inet.h>

void receiveHTTP(int clientSockfd, char *buff, size_t __n, int __flags)
{
    int bytes = recv(clientSockfd, buff, __n, __flags);
    if (bytes < 0)
    {
        perror("Recv failed");
        close(clientSockfd);
    }
    // for (int i = 0; i < sizeof(buff)/sizeof(char); i++)
    // {
    //     printf("%c",buff[i]);
    // }
    
}