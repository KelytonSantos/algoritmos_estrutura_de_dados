#include <stdio.h>

void fatorar_e_totient(int n)
{
    if (n <= 1)
    {
        return;
    }

    int toti = n; // Inicializa φ(n) = n
    int i = 2;

    while (i * i <= n)
    {
        if (n % i == 0)
        {
            toti = toti / i * (i - 1); // φ(n) = φ(n) × (1 - 1/p) equivale a φ(n) / p × (p-1)

            // Remove todas as ocorrências deste fator
            while (n % i == 0)
            {
                n /= i;
            }
        }
        else
        {
            i++;
        }
    }

    // Último fator primo (se existir)
    if (n > 1)
    {
        // printf("%d", n);
        toti = toti / n * (n - 1);
    }

    printf("%d\n", toti);
}

int main()
{
    int n = 0;
    scanf("%d", &n);

    if (n >= 65536 || n <= 1)
    {
        printf("Entrada invalida.\n");
        return 0;
    }

    fatorar_e_totient(n);
    return 0;
}