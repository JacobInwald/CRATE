#include "stdio.h"
#include "string.h"

int main(int argc, char *argv[])
{
    char buffer[20] = "b";
    char from[40];

    strncpy(from, argv[1], 39);
    strcpy(&buffer[1], from);

    printf("Your buffer is %s\n", buffer);
}