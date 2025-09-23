#include <stdio.h>
#include <stdlib.h>

int convertParaNumber(char *str);
int convertPartInteira(int numToConvert);
float convertPartFracionaria(int numToConvert);

long long pot(int base, int exp);

int main()
{
    char numBinario[] = "11000101.101";
    int countReal = 0, countFrac = 0, i;
    int inteiroBin = 0, fracionalBin = 0;
    int inteiroDec = 0;
    float fracionalDec = 0;

    for (i = 0; numBinario[i] != '.'; i++)
        countReal++;

    for (int j = countReal + 1; numBinario[j] != '\0'; j++)
        countFrac++;

    i = 0;

    char *partReal = malloc(countReal * sizeof(int));
    char *partFrac = malloc(countFrac * sizeof(int));

    while (numBinario[i] != '.')
    {
        partReal[i] = numBinario[i];
        i++;
    }
    int contador = 0;

    for (int j = countReal + 1; numBinario[j] != '\0'; j++)
    {
        partFrac[contador++] = numBinario[j];
    }

    inteiroBin = convertParaNumber(partReal);
    fracionalBin = convertParaNumber(partFrac);

    inteiroDec = convertPartInteira(inteiroBin);
    fracionalDec = convertPartFracionaria(fracionalBin);

    float result = inteiroDec + fracionalDec;
    printf("%.3f\n\n", result);

    // printf("%s\n", partReal);
    // printf("%s\n", partFrac);
    // printf("%d\n", inteiroDec);

    // printf("%d\n", realBin);
    // printf("%d\n", fracionalBin);

    free(partReal);
    free(partFrac);
    return 0;
}

int convertParaNumber(char *str)
{
    int num = atoi(str);
    return num;
}

long long pot(int base, int exp)
{
    long long resultado = 1;
    for (int j = 0; j < exp; j++)
    {
        resultado *= base;
    }
    return resultado;
}

int convertPartInteira(int numToConvert)
{
    int numToConvertCopy = numToConvert;
    int count = 0, somador = 0;

    while (numToConvertCopy != 0)
    {
        numToConvertCopy = numToConvertCopy / 10;
        count++;
    }

    int *vet = malloc(count * sizeof(int));
    int count2 = 0;

    for (int i = 1; i <= count; i++)
    {

        if (i == 1)
        {
            vet[count2] = (numToConvert % 10);
        }
        vet[count2] = ((numToConvert / pot(10, i - 1)) % 10);

        count2++;
    }

    // printf("te: %d\n", (numToConvert % (0 * 10)));
    // printf("te: %d\n", (numToConvert % (1 * 10)));
    // printf("te: %d\n", ((numToConvert / 10) % (10)));
    // printf("te: %d\n", ((numToConvert / 100) % (10)));

    for (int i = 0; i < count; i++)
    {
        vet[i] = pot(2 * vet[i], i);
    }

    for (int i = 0; i < count; i++)
    {
        somador += vet[i];
    }
    return somador;
}
float convertPartFracionaria(int numToConvert)
{
    int numToConvertCopy = numToConvert;
    int count = 0;
    float somador = 0.0;

    while (numToConvertCopy != 0)
    {
        numToConvertCopy = numToConvertCopy / 10;
        count++;
    }

    float *vet = malloc(count * sizeof(float));
    int count2 = 0;

    for (int i = 1; i <= count; i++)
    {

        if (i == 1)
        {
            vet[count2] = (numToConvert % 10);
        }
        vet[count2] = ((numToConvert / pot(10, i - 1)) % 10);

        count2++;
    }

    for (int i = 0; i < count; i++)
    {
        vet[i] = (vet[i] * (1.0f / (pot(2, i + 1))));
    }

    for (int i = 0; i < count; i++)
    {
        somador += vet[i];
    }
    return somador;
}
/*

    int num = 1234 caso utilize / fica 123
    caso utilize % fica 4;(atualizando sempre num)

*/