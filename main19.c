#include <stdio.h>

int bb(int *v, int indice_esquerdo, int indice_direito, int valor_buscado)
{
    if (indice_esquerdo < indice_direito - 1)
    {
        int m = (indice_esquerdo + indice_direito) / 2;
        if (v[m] >= valor_buscado)
            return bb(v, indice_esquerdo, m, valor_buscado);
        else
            return bb(v, m, indice_direito, valor_buscado);
    }
    return indice_direito;
}

int busca(int *v, int n, int x)
{
    return bb(v, -1, n, x);
}

int main()
{
    int v[] = {2, 4, 6, 8, 10};
    int n = 5;

    int x = busca(v, n, 6); // Retorna 2 (elemento encontrado na posição 2)

    printf("%d\n", x);
    // busca(v, n, 7);  // Retorna 3 (7 deveria ser inserido entre 6 e 8)
    // busca(v, n, 1);  // Retorna 0 (1 deveria ser inserido no início)
    // busca(v, n, 15); // Retorna 5 (15 deveria ser inserido no final)

    return 0;
}