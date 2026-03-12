#include <stdio.h>
#include <string.h>

void copy();
void readFile(const char *nameFile);

int main()
{

    readFile("teste.txt");

    return 0;
}

void copy(FILE *fileInput, FILE *fileOutput)
{
    size_t bytesLidos;
    char buffer[1024];
    const char *chave = "e3b0c44298fc1c149afbf4c8996fb92427ae41e4649b934ca495991b7852b855";
    size_t tamanhoChave = strlen(chave);

    size_t i;
    size_t posicaoChave = 0;

    while ((bytesLidos = fread(buffer, 1, sizeof(buffer), fileInput)) > 0)
    {
        for (i = 0; i < bytesLidos; i++)
        {
            buffer[i] ^= chave[posicaoChave];
            posicaoChave = (posicaoChave + 1) % tamanhoChave; // reinicia a chave se chegar ao fim
        }

        fwrite(buffer, 1, bytesLidos, fileOutput);
    }
}

void readFile(const char *nameFile)
{
    char newName[100] = {0};

    FILE *input = fopen(nameFile, "rb");
    if (input == NULL)
    {
        perror("erro ao abrir arquivo");
        return;
    }
    snprintf(newName, sizeof(newName), "%s.locked", nameFile);

    FILE *out = fopen(newName, "wb");

    if (out == NULL)
    {
        perror("erro ao criar arquivo");
        return;
    }

    copy(input, out);
    remove(nameFile);
    fclose(input);
    fclose(out);
}