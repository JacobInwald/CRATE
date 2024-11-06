/*
    ID:         001
    NAME:       strcpy-small
    TYPE:       0 (buffer)
    ACCESS:     w
*/

/*
    Fuzzing harness for the test cases written. Intention is to replace the #include line with the given test case and then compile with given options.
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void bad(char *input)
{
    printf(input);
}

#define BUFFER_SIZE 1024 // set buffer size

int main()
{
    char buffer[BUFFER_SIZE] = {0};
    read(0, buffer, BUFFER_SIZE); // read stdin

    bad(buffer); // function to fuzz-test

    return EXIT_SUCCESS;
}
