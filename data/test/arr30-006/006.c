#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[])
{
    char buffer[20];
    strcpy(buffer, argv[1]);
    printf("%d", buffer[21] == 'a');
}
