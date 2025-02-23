
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include "template.c" /* REPLACE */

#define BUFFER_SIZE 1024 // set buffer size

int main()
{
    char buffer[BUFFER_SIZE] = {0};
    read(0, buffer, BUFFER_SIZE); // read stdin

    bad(buffer); // function to fuzz-test

    return EXIT_SUCCESS;
}