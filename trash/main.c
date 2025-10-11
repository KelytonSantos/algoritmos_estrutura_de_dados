
#include <stdio.h>

int main()
{
    float value_bank = 0, buy_value = 0;

    printf("Qual saldo da sua conta bancaria: ");
    scanf("%f", &value_bank);
    printf("Qual valor da compra: ");
    scanf("%f", &buy_value);

    if (value_bank >= buy_value)
    {
        printf("Compra autorizada");
    }
    else
    {
        printf("Compra nao autorizada");
    }

    printf("%.2f\n", value_bank);
    printf("%.2f\n", buy_value);

    return 0;
}