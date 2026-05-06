#include <stdio.h>
#include "hash.h"

static void imprimir_hash(Hash *h)
{
    for (int i = 0; i < h->m; i++)
    {
        printf("bucket %d:", i);

        Celula *atual = h->tab[i]->prox;
        while (atual != NULL)
        {
            printf(" %d", atual->chave);
            atual = atual->prox;
        }

        printf("\n");
    }
}

static void testar_busca(Hash *h, int chave)
{
    Celula *encontrada = buscar(h, chave);

    if (encontrada != NULL)
        printf("chave %d encontrada\n", chave);
    else
        printf("chave %d nao encontrada\n", chave);
}

int main(void)
{
    Hash *h = cria_hash(5);

    if (h == NULL)
    {
        printf("erro ao criar hash\n");
        return 1;
    }

    int valores[] = {10, 15, 20, 1, 6, 11, 16, 21};
    int quantidade = (int)(sizeof(valores) / sizeof(valores[0]));

    for (int i = 0; i < quantidade; i++)
        inserir(h, valores[i]);

    printf("estado inicial\n");
    imprimir_hash(h);

    testar_busca(h, 20);
    testar_busca(h, 99);

    printf("\nremovendo 20, 10 e 11\n");
    remover(h, 20);
    remover(h, 10);
    remover(h, 11);

    printf("\nestado apos remocoes\n");
    imprimir_hash(h);

    testar_busca(h, 20);
    testar_busca(h, 10);
    testar_busca(h, 11);

    destruir_hash(h);
    return 0;
}