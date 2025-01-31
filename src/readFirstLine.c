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
