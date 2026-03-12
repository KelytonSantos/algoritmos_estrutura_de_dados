#include "lista_encadeada.h"

int main()
{
    printf("------------------------------\n");
    printf("LISTA ENCADEADA\n");
    printf("------------------------------\n");

    printf("Criando lista\n");
    celula *list = cria_lista();

    printf("Digite o primerio valor a ser inserido: ");
    int dado = 0;
    scanf("%d", &dado);
    insere_inicio(list, dado);
    printf("\n");

    int escolha = 0;
    do
    {
        printf("O que deseja fazer?\n");
        printf("1 - inserir novo item\n");
        printf("2 - remover elemento\n");
        printf("3 - buscar elemento por posição\n");
        printf("4 - buscar elemento por valor\n");
        printf("5 - imprimi lista\n");
        printf("6 - destruir lista\n");

        scanf("%d", &escolha);

        switch (escolha)
        {
        case 1:
            printf("Digite o novo dado: ");
            int novo_dado;
            scanf("%d", &novo_dado);
            insere_depois_(list, dado, novo_dado);
            printf("\n");

            break;

        case 2:
            printf("Digite o dado a ser deletado: ");
            int dado_remove;
            scanf("%d", &dado_remove);
            int dado_removido = remove_elemento(list, dado_remove);
            printf("Dado removido: ", dado_removido);
            printf("\n");
            break;

        case 3:
            printf("Digite a posição do elemento: ");
            int posit;
            scanf("%d", &posit);
            celula *celu;
            celu = busca_por_posit(list, posit);
            printf("Posição do elemento: %d", posit);
            printf("Dado: %d", celu->dado);
            printf("\n");

            break;

        case 4:
            printf("Digite o valor a ser buscado: ");
            scanf("%d", &dado);
            celula *celu2;
            celu2 = busca(list, dado);
            printf("Valor: %d", celu2->dado);
            printf("\n");
            break;
        case 5:
            print_lista(list);
            break;
        case 6:
            printf("Destruindo lista");
            destroi_lista(list);
            printf("\n");
            break;

        default:
            printf("Comando invalido");
        }

    } while (escolha != 1 || escolha != 2 || escolha != 3 || escolha != 4 || escolha != 5 || escolha != 6);
}