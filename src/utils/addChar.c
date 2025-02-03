#include <stdio.h>
void addChar(char *s, char c) {

      // Move pointer to the end
    while (*s != '\0') *s++;
  
    // Append the new character
    *s = c;
  
    // Add null terminator to mark new end
    *(s+1) = '\0';
}

