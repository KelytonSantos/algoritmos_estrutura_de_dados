#include <stdio.h>
#include <string.h>

int main()
{
    char str[33]; // 32 caracteres + '\0'

    // Lê a string de entrada (até 32 caracteres ou até encontrar newline)
    if (fgets(str, sizeof(str), stdin) != NULL)
    {
        int len = strlen(str);

        // Remove o '\n' do final se existir
        if (len > 0 && str[len - 1] == '\n')
        {
            str[len - 1] = '\0';
            len--;
        }

        // Converte cada caractere para hexadecimal
        for (int i = 0; i < len; i++)
        {
            // Imprime o valor ASCII em hexadecimal com 2 dígitos
            printf("%02x", (unsigned char)str[i]);
        }
        printf("\n");
    }

    return 0;
}