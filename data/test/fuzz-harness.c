/*
    Fuzzing harness for the test cases written. Intention is to replace the #include line with the given test case and then compile with given options.
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include /*START_TEST_CASE_NAME*/ "test-001.c" /*END_TEST_CASE_NAME*/

#define BUFFER_SIZE 1024 // set buffer size

int main()
{
    char buffer[BUFFER_SIZE] = {0};
    read(0, buffer, BUFFER_SIZE); // read stdin

    bad(buffer); // function to fuzz-test

    return EXIT_SUCCESS;
}