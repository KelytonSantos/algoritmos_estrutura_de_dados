#include "lista_encadeada.h"

celula *cria_lista()
{
    celula *le = malloc(sizeof(celula)); // space in memory for data struct
    le->prox = NULL;                     // apoint to next as null
    return le;                           // returning null
}

void insere_inicio(celula *le, int x)
{
    celula *new = malloc(sizeof(celula)); // declaring new celula
    new->dado = x;                        // new dado equals x
    new->prox = le->prox;                 // apointing the new prox as the last prox i.e null
    le->prox = new;                       // now, the prox of the begining one is the new one
}

void insere_depois_(celula *le, int y, int x)
{
    while (le->prox != NULL && le->prox->dado != y) // while prox is different from null and dado is different from y
        le = le->prox;                              // keep pointing to the next node

    if (le->prox == NULL) // if le->prox is null then we can add in the posit of null (see insere_inicio)
    {
        insere_inicio(le, x);
    }
    else
    {
        insere_inicio(le->prox, x); // if le->prox is not null then we gonna add the value in the le->prox->prox (see implementation of insere inicio)
    }
}

int remove_inicio(celula *le)
{
    celula *lixo = le->prox; // jumping head node
    le->prox = lixo->prox;   // linking le->prox with the prox ahead lixo
    int dado = lixo->dado;   // getting the deleted value
    free(lixo);              // free space
    return dado;             // returning dado
}

int remove_elemento(celula *le, int x)
{
    int dado = 0;
    while (le->prox != NULL && le->prox->dado != x) // while prox is different from null and data of prox is different from x
        le = le->prox;                              // pointing to the next

    if (le->prox != NULL) // if prox is different from null than we remove le->prox (see implementation remove_inicio)
        dado = remove_inicio(le);
    return dado;
}

celula *busca(celula *le, int x)
{
    le = le->prox;                      // the head node is empty so we got to apoint to the next node
    while (le != NULL && le->dado != x) // while not at end and not found x
    {
        le = le->prox;
    }
    return le; // returns node with x or null(the last one)
}

celula *busca_por_posit(celula *le, int i)
{
    if (le != NULL) // checks if le is different from null
    {
        le = le->prox;               // jump head node
        int j = 0;                   // control number
        while (le != NULL && j != i) // while le is different from null and j is different from i
        {
            le = le->prox; // pointing to the next
            j++;           // increments j;
        }
    }

    return le; // returning le, even if it is null
}

int lista_vazia(celula *le)
{
    return le->prox == NULL; // if le->prox equals null than return 1
}

void print_lista(celula *le)
{
    if (le != NULL)
    {
        // le = le->prox;
        while (le->prox != NULL)
        {
            le = le->prox;
            printf("%d ", le->dado);
        }
    }
    printf("\n");
}

void destroi_lista(celula *le)
{
    while (!lista_vazia(le))
        remove_inicio(le);
}