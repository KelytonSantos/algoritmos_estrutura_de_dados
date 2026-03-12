#include <stdio.h>
#include <string.h>
void cript(const char *nameFile)
{
    FILE *input = fopen(nameFile, "rb");
    if (input == NULL)
    {
        perror("erro ao abrir arquivo");
        return;
    }
}

int main()
{

    const char *pontToFile = "t.txt"; // ponteiro para o nome do arquivo

    FILE *file = fopen(pontToFile, "rb"); // abre o arquivo no modo leitura binaria

    if (file == NULL)
    {
        perror("Erro ao abrir arquivo"); // retorno de erro
        return 1;
    }

    char newN[] = "teste.txt"; // aqui seria a cpnstrução de um novo documento

    snprintf(newN, sizeof(newN), "%s.locked", pontToFile); /*juntanmos o nome das strings, o primeiro argumento
    trata o local onde vai ser salvo, o segundo argumento trata o tamanho daquele local, o terceiro trata do que
    vamos acrescentar, e o quarto seria oq vem no %s(que seria o nome do arquivo antigo)*/

    fwrite(newN, sizeof(char), strlen(newN), file); /* aqui escreve em blocos de dados binarios em um arquivo
        o primeiro parametro é aonde vamos salvar, o segundo parametro se trata do tamanho de cada bloco em bytes
        o terceiro parametro se trata do numero de blocos  que voce quer escrever
        o quarto parametro é o ponteiro para o arquivo onde queremos escrever

        entao se temos A B C D em um vetor e queremos escrever em um arquivo, podemos utilizar o fwrite:
        fwrite(vetorABCD, 1, 4, arquivo) perceba que coloquei o bloco de bytes em 1, e o 4 seria o tamanho total de blocos
        entao como char armazena 1 byte e temos um total de 4 bytes (A B C D)(se eu colocar um bloco total de 3 ele ignorara o D)
    */
    size_t fread(void *ptr, size_t size, size_t nmemb, FILE *stream);
    /*
         o primeiro parametro é um ponteiro para onde vai ser armazenado, o segundo parametro é  tamanho de cada elemento que queremos ler
         o terceiro é o numero de elementos que queremos ler
         o quarto parametro é ONDE IREMOS LER(inverso do fwrite)

         essa func retorna o numero de elementos lidos
    */

    // fread le o fileinput e salva no buffer
    // fwrite, le o buffer e salva no fileoutput

    FILE *output = fopen(newN, "wb");

    fclose(file);

    return 0;
}