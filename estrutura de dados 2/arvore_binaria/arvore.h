#include <stdio.h>
#include <stdlib.h>

typedef struct celula
{

    struct celula *dir;
    struct celula *esq;
    int dado;

} Celula;
