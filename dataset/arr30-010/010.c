#include "stddef.h"
#include "stdlib.h"
#include "stdio.h"
#include "string.h"

enum
{
    TABLESIZE = 10
};

int f(char *pwszPath)
{
    char wszMachineName[TABLESIZE + 1];
    char *pwszServerName = wszMachineName;
    char *pwszTemp = pwszPath + 1;
    while (*pwszTemp != '\\')
        *pwszServerName++ = *pwszTemp++;
}

int main(int argc, char *argv[])
{
    f(argv[1]);
}
