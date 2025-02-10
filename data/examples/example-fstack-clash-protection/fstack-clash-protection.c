#include "stdio.h"
#include "stdlib.h"
#include "string.h"

// static char secret[1024] = "This is a secret! This is a secret! This is a secret! This is a secret! This is a secret! This is a secret! This is a secret! This is a secret! This is a secret! This is a secret! This is a secret! This is a secret! This is a secret! This is a secret! This is";

int main(int argc, char *argv[])
{
    char *secret = malloc(1024 * sizeof(char));
    strcpy(secret, "This is a secret! This is a secret! This is a secret! This is");
    size_t size;
    sscanf(argv[1], "%zu", &size);
    printf("vla size: %zu\n", size);

    char vla[size];
    // vla[0] = 0;
    // vla[size - 1] = 0;

    // printf("&vla start:\t%p\n", vla);
    // printf("&vla end:\t%p\n", &vla[size - 1]);
    // printf("&secret:\t%p\n", secret);

    // printf("Secret:\t%s\n", secret);
}