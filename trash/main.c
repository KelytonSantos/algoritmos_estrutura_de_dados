#include <stdio.h>

int main()
{
    int n = 10;

    int *p = &n;

    printf("%p\n", (void *)p);
    printf("%d\n", *p);
    printf("%p\n", &n);
    printf("%p\n", (void *)&p);

    return 0;
}
