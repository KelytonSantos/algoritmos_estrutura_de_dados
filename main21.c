#include <stdio.h>

/**
 * @brief Função auxiliar RECURSIVA para imprimir um traço '-' uma certa quantidade de vezes.
 * Substitui um loop 'for' ou 'while'.
 *
 * @param quantidade O número de traços restantes para imprimir.
 */
void imprimir_tracos(int quantidade)
{
    // Caso Base: se não há mais traços a imprimir, a função para.
    if (quantidade <= 0)
    {
        return;
    }

    // Ação: imprime um único traço.
    printf("-");

    // Passo Recursivo: chama a si mesma para imprimir o resto dos traços.
    imprimir_tracos(quantidade - 1);
}

/**
 * @brief Desenha recursivamente uma régua inglesa de ordem n.
 *
 * @param n Um inteiro não negativo representando a ordem da régua.
 */
void desenhar_regua(int n)
{
    // Caso Base: se a ordem for 0 ou menor, não há nada para desenhar.
    if (n <= 0)
    {
        return;
    }

    // 1. Desenha a sub-régua superior de ordem n-1.
    desenhar_regua(n - 1);

    // 2. Imprime a marcação central (ponto e traços).
    printf(".");
    // Chama a função auxiliar recursiva para imprimir os traços, em vez de usar um loop.
    imprimir_tracos(n);
    printf("\n");

    // 3. Desenha a sub-régua inferior de ordem n-1.
    desenhar_regua(n - 1);
}

int main()
{
    int ordem;

    // Lê a entrada do usuário.
    if (scanf("%d", &ordem) == 1)
    {
        // Inicia o processo recursivo principal.
        desenhar_regua(ordem);
    }

    return 0;
}