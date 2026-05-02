#ifndef ARVORE_BINARIA_DE_BUSCA_RUBRO_NEGRA_ESQUERDISTA
#define ARVORE_BINARIA_DE_BUSCA_RUBRO_NEGRA_ESQUERDISTA

enum Cor
{
    PRETO,
    VERMELHO
};

typedef struct celula
{
    struct celula *esq, *dir;
    int dado;
    enum Cor cor;
} Celula;

int eh_preto(Celula *no);
int eh_vermelho(Celula *no);
Celula *insere(Celula *raiz, int x);
Celula *rotacao_a_direita(Celula *raiz);
Celula *rotacao_a_esquerda(Celula *raiz);
void sobe_cor(Celula *raiz);
Celula *insere_abbrne(Celula *raiz, int x);
Celula *busca(Celula *raiz, int x);
Celula *remover(Celula *raiz, int x);

#endif