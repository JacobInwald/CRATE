#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include <pthread.h>

struct arg_t
{
    unsigned n;
    char *secret;
};

unsigned long long counter = 0;
unsigned long *top = 0;

unsigned long fib(unsigned long n, char *secret)
{
    counter++;

    printf("Fib Iteration: %llu | Stack Size = %luKB | Secret = %s \n", counter, (top - &n) / 1000, secret);
    if (n == 0)
        return 1;
    if (n == 1)
        return 1;
    return fib(n - 1, secret) + fib(n - 2, secret);
}

void *_fib(void *_args)
{
    unsigned long a = 1;
    top = &a;

    char *_secret = (char *)malloc(sizeof(char) * 50);
    strncpy(_secret, "This is my well-kept secret!\n", 50);

    struct arg_t *args = _args;
    printf("Result: %lu\n", fib(args->n, _secret));

    strncpy(args->secret, _secret, 50);

    pthread_exit(NULL);
    return NULL;
}

int main(int argc, char *argv[])
{
    unsigned n = atoi(argv[1]);

    char *secret = (char *)malloc(sizeof(char) * 50);
    strncpy(secret, "This is my well-kept secret!\n", 50);

    struct arg_t *args = (struct arg_t *)malloc(sizeof(struct arg_t));
    args->n = n;
    args->secret = secret;

    pthread_attr_t tattr;
    pthread_attr_init(&tattr);
    pthread_attr_setguardsize(&tattr, 0); // Remove guard page to simulate older systems
    // pthread_attr_setstacksize(&tattr, 1024); // 1KB stack size

    pthread_t tid;
    pthread_create(&tid, &tattr, &_fib, (void *)args);
    // printf("%u\n", fib(n, secret));
    pthread_join(tid, NULL);
    printf("%s", secret);
}