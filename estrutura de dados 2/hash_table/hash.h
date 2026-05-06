#ifndef HASH_TABLE
#define HASH_TABLE

#include <stdio.h>
#include <stdlib.h>
// #include "arvore_bin_balanceada/arvoreBalanceada.h"

typedef struct celula
{
    int chave;
    struct celula *prox;
} Celula;

typedef struct
{
    Celula **tab;
    int m;

} Hash;

// funcs da lista

void inserir_lista(Celula *celula, int ch);
void remover_lista(Celula *celula, int ch);
Celula *buscar_lista(Celula *celula, int ch);
void destruir_lista(Celula *celula);
//----
int fhash(Hash *h, int ch);
Hash *cria_hash(int m);
void inserir(Hash *h, int ch);
void remover(Hash *h, int ch);
Celula *buscar(Hash *h, int ch);
void destruir_hash(Hash *h);

#endif