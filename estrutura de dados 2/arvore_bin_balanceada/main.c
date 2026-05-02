#include <stdio.h>
#include <stdlib.h>
#include "arvoreBalanceada.h"

static const char *nome_cor(enum Cor cor)
{
    return cor == PRETO ? "preto" : "vermelho";
}

static void imprime_em_ordem(Celula *raiz)
{
    if (raiz == NULL)
        return;

    imprime_em_ordem(raiz->esq);
    printf("%d(%s) ", raiz->dado, nome_cor(raiz->cor));
    imprime_em_ordem(raiz->dir);
}

static void destroi(Celula *raiz)
{
    if (raiz == NULL)
        return;

    destroi(raiz->esq);
    destroi(raiz->dir);
    free(raiz);
}

int main(void)
{
    Celula *raiz = NULL;
    int valores[] = {3, 4, 2, 10, 5, 1, 7};
    int total = (int)(sizeof(valores) / sizeof(valores[0]));

    for (int i = 0; i < total; i++)
    {
        raiz = insere(raiz, valores[i]);
    }

    printf("Arvore apos insercoes em ordem: ");
    imprime_em_ordem(raiz);
    printf("\n");

    Celula *achado = busca(raiz, 10);
    if (achado != NULL)
        printf("Busca 10: encontrado em no com cor %s\n", nome_cor(achado->cor));
    else
        printf("Busca 10: nao encontrado\n");

    achado = busca(raiz, 99);
    if (achado != NULL)
        printf("Busca 99: encontrado\n");
    else
        printf("Busca 99: nao encontrado\n");

    printf("\nRemovendo 4...\n");
    raiz = remover(raiz, 4);
    printf("Arvore apos remover 4 em ordem: ");
    imprime_em_ordem(raiz);
    printf("\n");

    achado = busca(raiz, 4);
    if (achado != NULL)
        printf("Busca 4 apos remover: encontrado\n");
    else
        printf("Busca 4 apos remover: nao encontrado\n");

    printf("\nRemovendo 2...\n");
    raiz = remover(raiz, 2);
    printf("Arvore apos remover 2 em ordem: ");
    imprime_em_ordem(raiz);
    printf("\n");

    destroi(raiz);
    return 0;
}