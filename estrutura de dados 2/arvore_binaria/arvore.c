#include "arvore.h"
// arvore binaria de busca sem balanceamento

Celula *buscar(Celula *raiz, int x)
{
    if (raiz != NULL) // se arvore for diferente de nula(se existir algo)
    {
        if (x < raiz->dado) // se x for menor que o dado na raiz
        {
            return buscar(raiz->esq, x); // vai pra esquerda
        }
        else if (x > raiz->dado) // caso x for maior
        {
            return buscar(raiz->dir, x); // vai pra direita
        }
        else
        {
            return raiz; // caso for igual(caso restante) retorna a raiz
        }
    }
    else
        return raiz;
}

Celula *cria_arvore_binaria_de_busca(int x)
{
    Celula *raiz = malloc(sizeof(Celula));
    raiz->dado = x;
    raiz->esq = raiz->dir = NULL;
    return raiz;
}

void destroi_arvore_binaria_de_busca(Celula *raiz)
{
    if (raiz != NULL)
    {
        destroi_arvore_binaria_de_busca(raiz->esq);
        destroi_arvore_binaria_de_busca(raiz->dir);
        free(raiz);
    }
}

void remove_sucessor(Celula *raiz)
{
    Celula *pai = raiz;
    Celula *filho = pai->dir;

    while (filho->esq != NULL)
    {
        pai = filho;
        filho = filho->esq;
    } // ele fica atualizando o pai e o filho até chegar no menor do lado direito (no caso ele so vai pra esquerda ate encontrar null)

    // filho aponta para o sucessor da raiz
    raiz->dado = filho->dado; // agora o menor numero da arvore é colocado no lugar da raiz (apenas substitui o dado da raiz)

    if (pai == raiz)
    {
        pai->dir = filho->dir;
    }
    else
    {
        pai->esq = filho->dir;
    }

    free(filho);
}

Celula *remover(Celula *raiz, int x)
{
    if (raiz != NULL)
    {
        if (x < raiz->dado)
        {
            raiz->esq = remover(raiz->esq, x);
        }
        else if (x > raiz->dado)
        {
            raiz->dir = remover(raiz->dir, x);
        } // ate aqui foi pra buscar o elemento

        //------------------------------------
        else if (raiz->esq == NULL)
        {
            Celula *p = raiz->dir;
            free(raiz);
            return p; // quando ele voltar na pilha ele associa o novo direito a esse p
        } // caso 1
        //----------------------------------

        else if (raiz->dir == NULL)
        {
            Celula *p = raiz->esq;
            free(raiz);
            return p;
        }
        else
        {
            remove_sucessor(raiz);
        }
        return raiz;
    }

    return NULL;
}

Celula *insere(Celula *raiz, int x)
{
    if (raiz != NULL)
    {
        if (x > raiz->dado)
        {
            raiz->dir = insere(raiz->dir, x);
        }
        else if (x < raiz->dado)
        {
            raiz->esq = insere(raiz->esq, x);
        }

        return raiz; // na hora que encontrar o null é pq ali é o local correto pra inserir o novo elemento
    }
    else // quando ele da o return ele cai no retorno da stack do elemento anterior que entao cai dentro desse else
    // e ao mesmo tempo ele ja faz a associação do elemento a raiz (nos dois if ao tentar procurar pelo null)
    {
        return cria_arvore_binaria_de_busca(x);
    }
}

void preordem(Celula *head)
{

    if (head != NULL)
    {
        printf("%d ", head->dado);
        preordem(head->esq);
        preordem(head->dir);
    }
}

void ordem(Celula *head)
{
    if (head != NULL)
    {
        ordem(head->esq);
        printf("%d ", head->dado);
        ordem(head->dir);
    }
}

void posordem(Celula *head)
{
    if (head != NULL)
    {
        posordem(head->esq);
        posordem(head->dir);
        printf("%d ", head->dado);
    }
}

static void imprime_arvore_aux(Celula *raiz, const char *prefixo, int eh_esquerda)
{
    if (raiz == NULL)
    {
        return;
    }

    if (raiz->dir != NULL)
    {
        char novo_prefixo[256];
        snprintf(novo_prefixo, sizeof(novo_prefixo), "%s%s", prefixo, eh_esquerda ? "|   " : "    ");
        imprime_arvore_aux(raiz->dir, novo_prefixo, 0);
    }

    printf("%s%s%d\n", prefixo, eh_esquerda ? "\\-- " : "/-- ", raiz->dado);

    if (raiz->esq != NULL)
    {
        char novo_prefixo[256];
        snprintf(novo_prefixo, sizeof(novo_prefixo), "%s%s", prefixo, eh_esquerda ? "    " : "|   ");
        imprime_arvore_aux(raiz->esq, novo_prefixo, 1);
    }
}

void imprime_arvore(Celula *raiz)
{
    if (raiz == NULL)
    {
        printf("(arvore vazia)\n");
        return;
    }

    imprime_arvore_aux(raiz, "", 1);
}

int main()
{
    Celula *raiz = NULL;

    int valores[] = {10, 5, 15, 3, 7, 12, 18, 1, 4, 6, 8};
    int total = sizeof(valores) / sizeof(valores[0]);

    printf("Inserindo valores na arvore: ");
    for (int i = 0; i < total; i++)
    {
        printf("%d ", valores[i]);
        raiz = insere(raiz, valores[i]);
    }
    printf("\n\nArvore inicial:\n");
    imprime_arvore(raiz);

    printf("\nPre-ordem: ");
    preordem(raiz);
    printf("\nEm-ordem: ");
    ordem(raiz);
    printf("\nPos-ordem: ");
    posordem(raiz);
    printf("\n");

    Celula *encontrada = buscar(raiz, 7);
    if (encontrada != NULL)
    {
        printf("\nBusca 7: encontrado (%d)\n", encontrada->dado);
    }

    encontrada = buscar(raiz, 99);
    if (encontrada == NULL)
    {
        printf("Busca 99: nao encontrado\n");
    }

    printf("\nRemovendo folha (1):\n");
    raiz = remover(raiz, 1);
    imprime_arvore(raiz);

    printf("\nRemovendo no com 1 filho (3):\n");
    raiz = remover(raiz, 3);
    imprime_arvore(raiz);

    printf("\nRemovendo no com 2 filhos (10 - raiz):\n");
    raiz = remover(raiz, 10);
    imprime_arvore(raiz);

    destroi_arvore_binaria_de_busca(raiz);
    return 0;
}