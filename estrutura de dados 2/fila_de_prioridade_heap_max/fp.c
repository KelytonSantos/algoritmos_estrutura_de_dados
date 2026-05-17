/*
v[0] é a raiz

se v[i] é um no qualquer temos que:

v[2i+1] é filho esquerdo desse no
v[2i+2] é filho direito desse no
v[(i-1)/2] é seu pai

*/
#include "fp.h"

void troca(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

FP *cria_fp(int tam)
{
    FP *fp = malloc(sizeof(FP));
    fp->dado = malloc(tam * sizeof(int));
    fp->tam = tam;
    fp->n = 0;

    return fp;
}

void sobe_no_heap(FP *f, int k)
{
    if (k > 0)
    {
        int pai = (k - 1) / 2;
        if (f->dado[pai] < f->dado[k])
        {
            troca(&f->dado[pai], f->dado + k);
            sobe_no_heap(f, pai);
        }
    }
}

void insere(FP *f, int x)
{
    // Se FP estiver cheia --> Dobra de Tamanho
    if (f->n >= f->tam)
    {
        f->dado = realloc(f->dado, 2 * f->tam * sizeof(int));
        f->tam *= 2;
    }

    f->dado[f->n] = x;
    f->n++;
    sobe_no_heap(f, f->n - 1);
}

int extrai_maximo(FP *f)
{
    if (f->n > 0)
    {
        // Obs: ao compilar, esta função deve dar warning.
        int max = f->dado[0];
        f->dado[0] = f->dado[f->n - 1];

        f->n--; // Não precisamos deletar o 'f->dado[f->n - 1]' de fato pois vai ser SOBREESCRITO
        desce_no_heap(f, 0);
        return max;
    }
    return -1; // Retorno padrão em caso de heap vazio para evitar erro de compilação
}

void desce_no_heap(FP *f, int k)
{
    int esq = 2 * k + 1; // Formula Filho ESQ

    if (esq < f->n)
    { // Checa se ta no Limite de Números Inseridos até agora

        // Identifica o MAIOR filho de k.
        int maior_filho = esq;
        int dir = esq + 1;
        if (dir < f->n && f->dado[dir] > f->dado[esq])
        {
            maior_filho = dir;
        }

        // Se o dado for MENOR que o 'maior_filho' --> Troca (MAX_HEAP)
        if (f->dado[k] < f->dado[maior_filho])
        {
            troca(&f->dado[k], &f->dado[maior_filho]);
            desce_no_heap(f, maior_filho);
        }
    }
}

void destroi_fp(FP *f)
{
    free(f->dado);
    free(f);
}
