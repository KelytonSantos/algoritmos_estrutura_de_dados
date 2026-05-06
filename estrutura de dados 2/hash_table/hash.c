#include "hash.h"

void inserir_lista(Celula *celula, int ch)
{
    Celula *nova = malloc(sizeof(Celula));
    if (nova == NULL)
        return;

    nova->chave = ch;

    nova->prox = celula->prox;
    celula->prox = nova;
}

void remover_lista(Celula *celula, int ch)
{
    if (celula == NULL || celula->prox == NULL)
        return;

    if (celula->prox->chave == ch)
    {
        Celula *temp = celula->prox;
        celula->prox = temp->prox;
        free(temp);

        return;
    }

    remover_lista(celula->prox, ch);
}

Celula *buscar_lista(Celula *celula, int ch)
{
    if (celula == NULL)
        return NULL;

    if (celula->chave == ch)
        return celula;

    return buscar_lista(celula->prox, ch);
}

void destruir_lista(Celula *celula)
{
    if (celula == NULL)
        return;
    destruir_lista(celula->prox);
    free(celula);
}

int fhash(Hash *h, int ch)
{
    int pos = ch % h->m;

    if (pos < 0)
        pos += h->m;

    return pos;
}

Hash *cria_hash(int m)
{
    if (m <= 0)
        return NULL;

    Hash *h = malloc(sizeof(Hash));
    if (h == NULL)
        return NULL;

    h->m = m;
    h->tab = malloc(m * sizeof(Celula *)); // seria a inicialização de endereços
    if (h->tab == NULL)
    {
        free(h);
        return NULL;
    }

    for (int i = 0; i < m; i++)
    {
        h->tab[i] = malloc(sizeof(Celula));
        if (h->tab[i] == NULL)
            return NULL;

        h->tab[i]->chave = 0;
        h->tab[i]->prox = NULL;
    }

    return h;
}

void inserir(Hash *h, int ch)
{
    int pos = fhash(h, ch);
    inserir_lista(h->tab[pos], ch);
}

void remover(Hash *h, int ch)
{
    int pos = fhash(h, ch);
    remover_lista(h->tab[pos], ch);
}

Celula *buscar(Hash *h, int ch)
{
    int pos = fhash(h, ch);
    return buscar_lista(h->tab[pos]->prox, ch);
}

void destruir_hash(Hash *h)
{
    for (int i = 0; i < h->m; i++)
    {
        destruir_lista(h->tab[i]);
    }
    free(h->tab);
    free(h);
}