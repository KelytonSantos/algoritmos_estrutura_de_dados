#include <stdio.h>

int atoi(const char *str)
{
    int num = 0;

    while (*str >= '0' && *str <= '9')
    {
        num = num * 10 + (*str - '0');
        str++;
    }
    return num;
}

void strcmp(const char *str1, const char *str2)
{
    while (*str1 && (*str1 == *str2))
    {
        str1++;
        str2++;
    }
    return (unsigned char)*str1 - (unsigned char)*str2;
}

int main()
{

    printf("%d\n", atoi("198020"));
    return 0;
}