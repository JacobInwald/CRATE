/*
    ID:         001
    NAME:       strcpy-small
    TYPE:       0 (buffer)
    ACCESS:     w
*/

#include <string.h>

void bad(char *input)
{
    char buf[10];
    strcpy(buf, input);
}