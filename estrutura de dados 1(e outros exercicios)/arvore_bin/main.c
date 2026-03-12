#include <stdio.h>
#include <stdlib.h>

typedef struct no
{
    int conteudo;
    struct no *esquerdo;
    struct no *direito;
} No;

typedef struct
{
    No *raiz;

} ArvB;

void inserirEsquerda(No *no, int valor)
{
    if (no->esquerdo == NULL)
    {
        No *novo = (No *)malloc(sizeof(No));
        novo->conteudo = valor;
        novo->esquerdo = NULL;
        novo->direito = NULL;
        no->esquerdo = novo;
    }
    else
    {
        if (valor < no->esquerdo->conteudo)
        {
            inserirEsquerda(no->esquerdo, valor);
        }
        else
        {
            inserirDireita(no->esquerdo, valor);
        }
    }
}

void inserirDireita(No *no, int valor)
{
}

void inserir(ArvB *arv, int valor)
{
    if (arv->raiz == NULL)
    {
        No *novo = (No *)malloc(sizeof(No));
        novo->conteudo = valor;
        novo->esquerdo = NULL;
        novo->direito = NULL;
        arv->raiz = novo;
    }
    else
    {
        if (valor < arv->raiz->conteudo)
        {
            inserirEsquerda(arv->raiz, valor);
        }
        else
        {
            inserirDireita(arv->raiz, valor);
        }
    }
}

int main()
{

    return 0;
}