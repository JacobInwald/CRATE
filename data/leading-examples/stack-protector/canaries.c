#include "stdio.h"

int main(int argc, char *argv[])
{
    char buffer[20];
    char *to = buffer;
    char *from = argv[1];
    while (*from)
    {
        *to = *from;
        *to++;
        *from++;
    }
    printf("Your buffer is %s\n", buffer);
}