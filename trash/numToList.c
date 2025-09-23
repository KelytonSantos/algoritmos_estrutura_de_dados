#include <stdio.h>

int atoi_simples(const char *str)
{
    int num = 0;
    while (*str >= '0' && *str <= '9')
    {
        num = num * 10 + (*str - '0');
        str++;
    }
    return num;
}

int atoi(const char *str)
{
    int num = 0;
    while (*str >= '0' && *str <= '9')
    {
        num = num * 10 + (*str - '0');
        str++;
    }
}
int main()
{

    char num[10] = "9728";

    int nume = atoi_simples(num);

    printf("%d\n", nume);
    return 0;
}
/*
Se str = "1234":

num = 0 * 10 + ( '1' - '0') = 1

num = 1 * 10 + ( '2' - '0') = 12

num = 12 * 10 + ( '3' - '0') = 123

num = 123 * 10 + ( '4' - '0') = 1234
*/