#include <stdio.h>
#include <stdlib.h>

int func_hash(const char *str)
{
    return str[0] - 'a';
}

int main()
{

    printf("posit: %d \n", func_hash("bcara"));

    return 0;
}