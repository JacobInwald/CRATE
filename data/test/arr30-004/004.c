#include "stddef.h"
#include "stdlib.h"
#include "stdio.h"
#include "string.h"

enum
{
    TABLESIZE = 10
};

static char table[TABLESIZE];

int f(char *pwszPath,
      char *wszMachineName)
{
    char *pwszServerName = wszMachineName;
    char *pwszTemp = pwszPath + 1;
    while (*pwszTemp != '\\')
        *pwszServerName++ = *pwszTemp++;
}

int main(int argc, char *argv[])
{
    f(argv[1], table);

    printf("%d\n", table[20] == 'a');
}
