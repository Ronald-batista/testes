#include <stdio.h>
#include <string.h>

int test () {
       char msg[6];
 
    strcpy(msg, "Hello!");
 
    printf("%s\n", msg);
 
    return 0;
}