/*
readFirstLine.c:

reads the first line of the buffer
to find method, url, and HTTP version.


*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <arpa/inet.h>
#include "utils/addChar.c"

void readFirstLine(char *buff, int bufferSize)
{
    char *firstLine = (char *) malloc(sizeof(char)*1024);
    int firstLineSize = 0;
    for (int i = 0; i < bufferSize; i++)
    {
        if (buff[i]!='\r' && buff[i] != '\n')
        {
            addChar(firstLine, buff[i]);
            printf("%c",firstLine[i]);
            firstLineSize++;
        }
        else
        {
            break;
        }
    }
    char props[3][100] = {};
    int propNumber = 0;
    int c = 0;
    int l=0;
    for (int i = 0; i < firstLineSize; i++)
    {
        if (firstLine[i] == ' ')
        {
            c++;
            l=0;
        }
        else
        {
            props[c][l] = firstLine[i];
            l++;
        }
    }
     printf("\n %s | %s | %s \n",props[0], props[1], props[2]);
}