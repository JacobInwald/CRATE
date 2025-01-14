#include "stddef.h"
#include "stdlib.h"
#include "stdio.h"

enum
{
    TABLESIZE = 100
};

static int table[TABLESIZE];

int *f(int index)
{
    if (index < TABLESIZE)
    {
        return table + index;
    }
    return NULL;
}

int main(int argc, char *argv[])
{
    int *p = f(atoi(argv[1]));
    printf("%d\n", p < table || p >= table + TABLESIZE);
}