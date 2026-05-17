#ifndef FILA_DE_PRIORIDADE_HEAP_MAX
#define FILA_DE_PRIORIDADE_HEAP_MAX

#include <stdlib.h>
#include <stdio.h>

typedef struct
{
    int *dado;
    int tam, n;
} FP;

FP *cria_fp(int tam);
void sobe_no_heap(FP *f, int k);
void insere(FP *f, int x);
int extrai_maximo(FP *f);
void desce_no_heap(FP *f, int k);
void destroi_fp(FP *f);
void troca(int *a, int *b);
#endif // !