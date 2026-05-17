#include <stdlib.h>
#include <stdio.h>

// Função Auxiliar
void troca(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Tipo Abstrato de Dado
typedef struct {
    int *dado;
    int n, tam;
} FP;

/* Funções HEAP
    FP *cria_fp(int tam);
    void destroi_fp(FP *f);
    void insere(FP *f, int x);
    int extrai_maximo(FP *f);
    void sobe_no_heap(FP *f, int k);
    void desce_no_heap(FP *f, int k);
*/

FP *cria_fp(int tam) {
    FP *f = malloc(sizeof(FP)); // Aloca struct
    f->dado = malloc(sizeof(int) * tam); // Aloca o vetor.
    f->n = 0;
    f->tam = tam;
    return f;
}

void destroi_fp(FP *f) { 
    free(f->dado); 
    free(f); 
}

void sobe_no_heap(FP *f, int k) {
    if (k > 0) {
        int pai = (k - 1) / 2;
        if (f->dado[pai] < f->dado[k]) {
            troca(&f->dado[pai], f->dado + k);
            sobe_no_heap(f, pai);
        }
    }
}

void insere(FP *f, int x) {
    // Se FP estiver cheia --> Dobra de Tamanho
    if (f->n >= f->tam) {
        f->dado = realloc(f->dado, 2 * f->tam * sizeof(int));
        f->tam *= 2;
    }
    
    f->dado[f->n] = x;
    f->n++;
    sobe_no_heap(f, f->n - 1);
}

void desce_no_heap(FP *f, int k) {
    int esq = 2 * k + 1; // Formula Filho ESQ

    if (esq < f->n) { // Checa se ta no Limite de Números Inseridos até agora

        // Identifica o MAIOR filho de k.
        int maior_filho = esq; 
        int dir = esq + 1;
        if (dir < f->n && f->dado[dir] > f->dado[esq]) {
            maior_filho = dir;
        }
        
        // Se o dado for MENOR que o 'maior_filho' --> Troca (MAX_HEAP)
        if (f->dado[k] < f->dado[maior_filho]) { 
            troca(&f->dado[k], &f->dado[maior_filho]);
            desce_no_heap(f, maior_filho);
        }
    }
}

int extrai_maximo(FP *f) {
    if (f->n > 0) {
        // Obs: ao compilar, esta função deve dar warning.
        int max = f->dado[0];
        f->dado[0] = f->dado[f->n - 1];

        f->n--; // Não precisamos deletar o 'f->dado[f->n - 1]' de fato pois vai ser SOBREESCRITO
        desce_no_heap(f, 0);
        return max;
    }
    return -1; // Retorno padrão em caso de heap vazio para evitar erro de compilação
}

int main(){

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