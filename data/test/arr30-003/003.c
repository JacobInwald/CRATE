#include "stddef.h"
#include "stdlib.h"
#include "stdio.h"
#include "string.h"

enum
{
    TABLESIZE = 100
};

static char table[TABLESIZE];

char *f(int index)
{
    if (index < TABLESIZE)
    {
        return table + index;
    }
    return NULL;
}

int main(int argc, char *argv[])
{
    char *p = f(atoi(argv[1]));
    strncpy(p, argv[2], TABLESIZE);
    printf("%d\n", p[0] == 'a');
}