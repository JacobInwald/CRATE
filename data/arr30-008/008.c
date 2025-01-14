#include "stddef.h"
#include "stdlib.h"
#include "stdio.h"

enum
{
    TABLESIZE = 100
};

char *f(int index, char *table)
{
    if (index < TABLESIZE)
    {
        return table + index;
    }
    return NULL;
}

int main(int argc, char *argv[])
{
    char table[TABLESIZE];
    char *p = f(atoi(argv[1]), table);
    printf("%p %p %p %p\n", p);
}