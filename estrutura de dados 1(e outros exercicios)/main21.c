#include <stdio.h>

void imprimir_tracos(int quantidade)
{
    if (quantidade <= 0)
    {
        return;
    }
    printf("-");

    imprimir_tracos(quantidade - 1);
}

void desenhar_regua(int n)
{
    if (n <= 0)
    {
        return;
    }

    desenhar_regua(n - 1);

    printf(".");
    imprimir_tracos(n);
    printf("\n");

    desenhar_regua(n - 1);
}

int main()
{
    int ordem;

    if (scanf("%d", &ordem) == 1)
    {
        desenhar_regua(ordem);
    }

    return 0;
}