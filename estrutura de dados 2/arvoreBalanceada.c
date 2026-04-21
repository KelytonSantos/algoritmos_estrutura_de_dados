/*
arvore rubro negra esquerdista

regras:
1) todo nó é vermelho ou preto
2) a raíz é preta
3) as folhas são os nulls e tem cores pretas
4) se um nó é vermelho entao
    * seus filhos são pretos
    * é filho esquerdo
5)para qualquer no, a quantidade de nós pretos a qualquer folha descendente é a mesma
    * se chama altura negra do nó
    * não se conta o nó raiz


    a quantidade de nós é dado sempre por 2^bh -1 onde bh é black heigh (altura negra)

    temos as condições para correção:

    1) ehPreto(r) && ehVermelho(r->esq) && ehVermelho(r->dir): é em relação a subida de cor

    2) ehPreto(r) && ehPreto(r->esq) && ehVermelho(r->dir): rotação a esquerda

    3) ehPreto(r) && ehPreto(r->esq) && ehVermelho(r->esq->esq): rotação a direita de r

    4) ehVermelho(r) && ehPreto(r->esq) && ehVermelho(r->dir): rotação a esquerda de r

*/

#include <stdio.h>

enum Cor
{
    PRETO,
    VERMELHO
};
typedef struct celula
{
    int dado;
    enum Cor cor;
    struct celula *esq, dir;
} Celula;

void sobe_cor(Celula *raiz)
{
    raiz->cor = VERMELHO;
    raiz->esq->cor = raiz->dir->cor = PRETO;
}

void *rotacao_a_esquerda(Celula *raiz)
{
    Celula *fd = raiz->dir;
    fd->cor = raiz->cor;
    raiz->cor = VERMELHO;
    Celula *beta = fd->esq;
    fd->esq = raiz;
    raiz->dir = beta;

    return fd;
}

int main()
{

    return 0;
}