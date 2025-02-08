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
#define BUFFER_SIZE 1024
#define MAX_BUFFER_SIZE 1000000 // ~ 1MB

void receiveHTTP(int clientSockfd, int flags)
{
    int total = 0;
    int lastCharPos = 0;
    char *mainBuff = malloc(sizeof(char) * BUFFER_SIZE);
    // mainBuff has all the data
    // buff gets it with BUFFER_SIZE  
    // and pours it into mainBuff.
    while (total < MAX_BUFFER_SIZE)
    {
        char *buff = malloc(sizeof(char) * BUFFER_SIZE);
        int bytes = recv(clientSockfd, buff, BUFFER_SIZE, flags);
        lastCharPos += total + bytes;
        for (int i = 0; i < bytes; i++)
        {
            mainBuff[total + i] = buff[i];
        }
        // printf("%s\n\n",mainBuff);
        // use \r\n\r\n to check if ends.
        if (strstr(mainBuff, "\r\n\r\n") != NULL || bytes == 0)
        {
            break;
        }
        mainBuff[lastCharPos] = '\0';
        // making mainBuff bigger for next buff.
        total += BUFFER_SIZE;
        char *tmp = realloc(mainBuff, total + (BUFFER_SIZE * sizeof(char)));
        mainBuff = tmp;
        if (total > (MAX_BUFFER_SIZE - BUFFER_SIZE))
        {
            printf("MAX_BUFFER_SIZE exceeded.");
        }
        free(buff);
    }
    mainBuff[lastCharPos] = '\0';
    printf("%s",mainBuff);
    char **s = readFirstLine(mainBuff, lastCharPos);
    printf("%s\n",s[1]);
}