#include <stdio.h>

// Função que implementa o Bubble Sort
void bubbleSort(int arr[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - 1 - i; j++)
        {

            if (arr[j] > arr[j + 1])
            {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

// Função para imprimir o array
void printArray(int arr[], int size)
{
    int i;
    for (i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// Função principal
int main()
{
    int arr[] = {64, 34, 25, 12, 22, 11, 90};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Array original: \n");
    printArray(arr, n);

    bubbleSort(arr, n);

    printf("Array ordenado: \n");
    printArray(arr, n);

    return 0;
}

/*
    o laço externo controla o numero de passadas pelo vetor (a cada passada empurra o maior para o final)
    o laço interno faz a comparaçao entre vizinhos dentro de cada passada

    o primeiro for é n-1, isso porque num vetor de 5 elementos o maximo que precisamos é de 4 passadas (conta-se a transição de "empurrada")
    no segundo for fazemos n-1-i, o i se da por conta q a passada anterior ja foi feita, ou seja, ja esta em ordem

*/