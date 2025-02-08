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
char **readFirstLine(char *buff, int bufferSize)
{
    // Allocate memory for the first line
    char *firstLine = (char *)malloc(sizeof(char) * 30000);
    int firstLineSize = 0;
    for (int i = 0; i < bufferSize; i++)
    {
        if (buff[i] != '\n' && buff[i] != '\r')
        {
            firstLine[i] = buff[i];
        }
        else
        {
            break;
        }
        firstLineSize++;
    }
    firstLine[firstLineSize] = '\0';
    char **props = malloc(3 * sizeof(char *));
    for (int i = 0; i < 3; i++)
    {
        props[i] = malloc(10000 * sizeof(char));
    }
    int propNum = 0;
    int charNum = 0;
    for (int i = 0; i < firstLineSize; i++)
    {
        if (firstLine[i] == ' ')
        {
            props[propNum][charNum] = '\0';
            propNum++;
            charNum = 0;
        }
        else
        {
            props[propNum][charNum] = firstLine[i];
            charNum++;
        }
    }
    free(firstLine);
    return props;
    free(props);
}