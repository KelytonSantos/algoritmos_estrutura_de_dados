#ifndef FILA_DE_PRIORIDADE_HEAP_MAX
#define FILA_DE_PRIORIDADE_HEAP_MAX

#include <stdlib.h>

typedef struct
{
    int *dado;
    int tamanho, n;
} FP;

FP *cria_fp(int tam);
void insere(FP *f, int x);
int extrai_maximo(FP *f);
void desce_no_heap(FP *f);
void destroi_fp(FP *f);

#endif // !