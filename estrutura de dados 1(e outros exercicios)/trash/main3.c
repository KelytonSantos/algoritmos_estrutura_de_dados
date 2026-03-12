#include <stdio.h>

int main()
{

    int n1 = 1, n2 = 2, n3 = 3;

    if (n1 >= n2)
    {
        if (n1 >= n3)
        {
            printf("um maior\n");
        }
        else
        {
            printf("tres maior\n");
        }
    }
    else if (n2 >= n3)
    {
        if (n2 >= n1)
        {
            printf("dois maior\n");
        }
        else
        {
            printf("um maior");
        }
    }
    else if (n3 >= n1)
    {
        if (n3 >= n2)
        {
            printf("n3 maior\n");
        }
        else
        {
            printf("n2 maior\n");
        }
    }

    return 0;
}