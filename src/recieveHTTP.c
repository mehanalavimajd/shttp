/*
recieveHTTP.c: 

receives and handles a http request 
by using the recv function of the sockfd.

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
    if (bytes <= 0) return;

    // prints the whole thing...
    printf("%.*s",bytes,buff);

    // prints everything ignoring line breaks...
    char lines[][];
    for (int i = 0; i < bytes; ++i)
    {
        if (buff[i] != '\r' && buff[i] != '\n'){
            
        }
    }
    
}