/*
response.c:
sends a response to client using the
send function.
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <arpa/inet.h>
#include <time.h>

void response(int sockfd, int statusCode, char *statusText, char *body)
{
    char headers[512];
    char response[2048];
    time_t rawtime;
    struct tm *timeinfo;
    char date_str[128];
    time(&rawtime);
    timeinfo = gmtime(&rawtime);
    strftime(date_str, sizeof(date_str), "Date: %a, %d %b %Y %H:%M:%S GMT", timeinfo);
    int headersLength = snprintf(headers, sizeof(headers),
                                 "HTTP/1.1 %d %s\r\n"
                                 "%s\r\n"
                                 "Server: MyCServer\r\n"
                                 "Content-Length: %zu\r\n"
                                 "Content-Type: text/html\r\n"
                                 "Connection: Closed\r\n"
                                 "\r\n",
                                 statusCode, statusText, date_str, body ? strlen(body) : 0);
    int responseLength = headersLength + (body ? strlen(body) : 0);
    memcpy(response, headers, headersLength); // Using memcpy is slightly more efficient
    if (body)
    {
        memcpy(response + headersLength, body, strlen(body));
    }

    send(sockfd, response, responseLength, 0);
}