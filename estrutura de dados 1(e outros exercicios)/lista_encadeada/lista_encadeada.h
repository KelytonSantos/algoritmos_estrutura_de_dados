
#ifndef LISTA_ENCADEADA_H

typedef struct celula
{
    int dado;
    struct celula *prox;

} celula;

#include <stdio.h>
#include <stdlib.h>

celula *cria_lista();
void insere_inicio(celula *le, int x);
void insere_depois_(celula *le, int y, int x);
int remove_inicio(celula *le);
int remove_elemento(celula *le, int x);
celula *busca(celula *le, int x);
celula *busca_por_posit(celula *le, int i);
int lista_vazia(celula *le);
void destroi_lista(celula *le);
void print_lista(celula *le);

#endif // !LISTA_ENCADEADA_H
