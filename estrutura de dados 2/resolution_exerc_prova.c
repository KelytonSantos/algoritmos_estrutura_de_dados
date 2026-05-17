#include <stdio.h>
#include <stdlib.h>

typedef struct celula
{
    int contador_de_visitas;
    char *nickname;

    struct celula *prox;
} Celula;

typedef struct hash
{
    int tam;
    Celula **tab;
} Hash;

int fhash(const char *nickname)
{
    return nickname[0] - 'a';
}

void cria_hash(int n)
{
    Hash *h = malloc(sizeof(Hash));
    h->tab = malloc(n * sizeof(Celula *));

    for (int i = 0; i < n; i++)
    {
        h->tab[i] = malloc(sizeof(Celula));
        h->tab[i]->prox = NULL;
    }
    h->tam = n;
}

int conta_char_nick(const char *nickname)
{
    int cont = 0;
    for (int i = 0; nickname[i] != '\0'; i++)
    {
        cont++;
    }
    return cont + 1;
}

void copia(char *str1, char *str2, int n)
{
    for (int i = 0; i < n; i++)
    {
        str1[i] = str2[i];
    }
    str1[n] = '\0';
}

int strcmp(const char *str1, const char *str2)
{
    while (*str1 && (*str1 == *str2))
    {
        str1++;
        str2++;
    }
    return (unsigned char)*str1 - (unsigned char)*str2;
}

void insere_lista(Celula *celula, const char *nickname)
{
    Celula *nova = malloc(sizeof(Celula));
    nova->prox = celula->prox;
    nova->contador_de_visitas = 0;

    int tam = conta_char_nick(nickname);
    nova->nickname = malloc(tam * sizeof(char));

    copia(nova->nickname, nickname, tam);

    celula->prox = nova;
}

Celula *busca_em_lista(Celula *celula, const char *nickname)
{

    if (celula == NULL)
        return NULL;

    if (strcmp(celula->nickname, nickname) == 0)
        return celula;

    return busca_em_lista(celula->prox, nickname);
}

Celula *busca(Hash *h, const char *nickname)
{
    int pos = fhash(nickname);
    Celula *b = busca_em_lista(h->tab[pos]->prox, nickname);
    return b;
}

void registra_user(Hash *h, const char *nickname)
{
    int pos = fhash(nickname);
    insere_lista(h->tab[pos]->prox, nickname);
}

void marca_visita(Hash *h, const char *nickname)
{
    Celula *find = busca(h, nickname);
    find->contador_de_visitas += 1;
}

int main()
{
}