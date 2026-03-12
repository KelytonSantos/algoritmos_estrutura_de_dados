/*

Métodos numericos para Engenharia

Lucas X - Métodos Intercalares
          Método da Bissecção

    Método para encontrar as raizes de uma equação: Escolhe-se um intervalo [a, b] onde f(a)*f(b) < 0 (valores negativos)
    Ou seja a função tem valores opostos nos extremos. Pelo teorema do valor intermediario, existe pelo menos uma raiz entre a e b

    xm = (a + b) / 2

    Verifica-se o sinal de f(xm)
        Se f(xm) = 0, achamos a raiz

        Se f(a)*f(xm) < 0, a raiz esta entre 'a' e 'xm'

        Se f(xm)*f(b) < 0, a raiz esta entre 'xm' e 'b'
*/
#include <stdio.h>
#include <math.h>

double f(double x)
{
    return x * x - 2; // função f(x) = x² - 2
}

int main()
{
    double a = 0.0, b = 2.0; // intervalo inicial
    double x_ant, x_atual;
    double Er; // erro relativo
    int iter = 0, max_iter = 50;
    double tol = 1e-6; // tolerância (10^-6)

    // verificar se existe raiz no intervalo
    if (f(a) * f(b) > 0)
    {
        printf("Nao existe raiz no intervalo [%.2f, %.2f]\n", a, b);
        return 1;
    }

    do
    {
        iter++;
        x_ant = x_atual;

        // decide o novo intervalo
        if (f(a) * f(x_atual) < 0)
        {
            b = x_atual;
        }
        else
        {
            a = x_atual;
        }

        x_atual = (a + b) / 2.0; // ponto médio (calculado APÓS atualizar o intervalo)

        // calcula o erro relativo
        Er = fabs((x_atual - x_ant) / x_atual);

        printf("Iter %2d: x = %.10f, Er = %.10e\n", iter, x_atual, Er);

    } while (Er > tol && iter < max_iter);

    printf("\nA raiz aproximada eh: %.10f\n", x_atual);
    return 0;
}
