#include "fp.h"

int main()
{

    FP *minha_heap = cria_fp(10);

    printf("\nInserindo elementos: 15, 10, 30, 5, 20\n");
    insere(minha_heap, 15);
    insere(minha_heap, 10);
    insere(minha_heap, 30);
    insere(minha_heap, 5);
    insere(minha_heap, 20);

    printf("Extraindo o maximo: %d\n", extrai_maximo(minha_heap)); // Deve ser 30
    printf("Novo maximo na raiz: %d\n\n", minha_heap->dado[0]);    // Deve ser 20

    return 0;
}