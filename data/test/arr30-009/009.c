#include "stddef.h"
#include "stdlib.h"
#include "stdio.h"
#include "string.h"

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
    strncpy(p, argv[2], TABLESIZE);
    printf("%d\n", p[0] == 'a' && p < table);
}