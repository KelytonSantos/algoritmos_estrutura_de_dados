#include <stdio.h>

void insertion_sort(int *vet, int n)
{

    for (int j = 1; j < n; j++)
    {
        /*
            j começa em 1 pois supõe-se que a primeira posição 0 ja esta ordenado

        */

        int x = vet[j]; /*
            marcamos x começando apartir da segunda posição (no nosso exemplo x = 2)

        */

        int i = j - 1;

        /*
            variavel de controle do while: começamos uma posição antes do j, entao se j começa em 1,
             i começa em 0

        */

        /*
            se i for maior igual a 0(perceba q na primeira vez ele vai cair aqui direto pq i é igual a 0)
            e o vet[i](deslocado em uma unidade em comparação a j) for maior que x(x recebe o valor do vetor
            em j)entao fica vet[j-1] > vet[j]; pergunta: vet na posição anterior é maior que vet na posição atual(ou posterior dependendo de como analisar)?

            o interessante é que ele não é >= pq se ele for igual ele ja nem entra no loop n precisando assim fazer
            mais uma comparação
            */
        while (i >= 0 && vet[i] > x)
        {

            /*
            aqui é o swap: vet[i+1](que é o mesmo de vet[j] =  vet[i](que é o mesmo de ve[j-1]))
            e decrementamos o i

            ele faz a copia daquele pra frente entao se era (5, 2) fica (5, 5)
            */
            vet[i + 1] = vet[i];
            i--;
        }

        /*
            aqui o vet[i+1] ou vet[j] = vet[j]
            entao seguindo o mesmo exemplo temos: (5, 2)
            vet[j] = vet[i+1] = x onde x = vet[j] anterior a mudança entao o x ainda continha o 2, logo
            vet[i+1] = 2
        */
        vet[i + 1] = x;
    }
}
/*
    logica: faz copia pra frente e como ele tinha salvado o da frente caso obedeça as condições ele joga pra posit atual
    (aqui ele comparar e jogar pra tras enquanto a condição for verdadeira)
*/

/*
    [5, 2, 4, 6, 1, 3]

    na primeira iteração até o while fica

    [5, 5, 4, 6, 1, 3] sai do while

    [2, 5, 4, 6, 1, 3] vet[j] agora é 5, ele ve se 5 > 4? e entra no while de novo

    [2, 5, 5, 6, 1, 3] (o 4 ficou salvo no x) aqui ele ainda ta dentro do while pois a condição de parada nao foi imposta

    entao entra de novo no while:

    2 > 4? não entao ele sai do while e roda a instrução vet[i+1] = x

    [2, 4, 5, 6, 1, 3]

    vet[j] = 6 = x e vet[i] = vet[j-1] = 5
    while: 5 > 6? nao(nem entra no while)
    roda instrução vet[i + 1] = x; -> ve[j] = vet[j antigo] -> vet[j] = 5 (ele n alterou nada) 5 = 5

    [2, 4, 5, 6, 1, 3]
    vet[j] = 1 = x
    vet[i] = vet[j-1] = 6

    while: 6 > 1? sim; entra no while
    move 6 pra frente

    [2, 4, 6, 6, 3]

    5 > 1? sim



*/

int main()
{

    int vet[] = {5, 2, 4, 6, 1, 3};

    int n = 6;

    insertion_sort(vet, n);

    for (int i = 0; i < n; i++)
    {
        printf("%d\n", vet[i]);
    }

    return 0;
}