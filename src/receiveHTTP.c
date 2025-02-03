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
#include "readFirstLine.c"

void receiveHTTP(int clientSockfd, char *buff, size_t n, int flags)
{

    int bytes = recv(clientSockfd, buff, n, flags);
    if (bytes <= 0)
        return;
    buff[bytes] = '\0';
    // prints the whole thing...
    printf("%.*s", bytes, buff);

    // prints everything ignoring line breaks...
    readFirstLine(buff, 100);
}