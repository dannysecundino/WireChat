#include "../headers/transport.hpp"

#include <iostream>

#include <sys/socket.h>     // socket()
#include <netinet/in.h>     // endereço de socket
#include <unistd.h>         // close()

#include <stdint.h>

#define BUFFER_SIZE 4096

// funções para detalhes de implementação
void preencher_endereco(struct sockaddr_in* endereco, int PORT){
    *endereco = {};                                 // para resetar o espaço de memória serverAdress (isso só tem em C++)
    
    endereco->sin_family = AF_INET;                 // IPv4
    endereco->sin_port = htons(PORT);               // porta
    endereco->sin_addr.s_addr = htonl(INADDR_ANY);  // para o loopback (localhost) seria INADDR_LOOPBACK
}



// funções do namespace
int transport::criar_lsock(int PORT, int BACKLOG){
    // criar socket
    int lsock = socket(AF_INET, SOCK_STREAM, 0);
    if(lsock == -1){
        std::cout << "error in socket()\n";
        return -1;
    }

    // configurar (para quando derrubar o servidor não dar o "Adress already in use")
    int reuso = 1;
    setsockopt(lsock, SOL_SOCKET, SO_REUSEADDR, &reuso, sizeof(reuso));

    // endereçar o socket
    struct sockaddr_in serverAdress;
    preencher_endereco(&serverAdress, PORT);

    // fazer o bind()
    int test1 = bind(lsock, (struct sockaddr *) &serverAdress, sizeof(serverAdress));
    if (test1 == -1) {
        std::cout << "error in bind()\n";
        fechar_socket(lsock);
        return -1;
    }

    // fazer o listen()
    int teste2 = listen(lsock, BACKLOG);
    if (teste2 == -1) {
        std::cout << "error in listen()\n";
        fechar_socket(lsock);
        return -1;
    }

    // retornar o socket
    return lsock;
}

int transport::aceitar_cliente(int lsock){
    // para o accept()
    struct sockaddr_in clientAdress;
    socklen_t size_clientAdress = sizeof(clientAdress);

    // fazer o accept()
    int csock = accept(lsock, (struct sockaddr*) &clientAdress, &size_clientAdress);

    // retornar o csock
    return csock;
}

void transport::enviar(int csock, char *dado){
    send(csock, dado, sizeof(dado), 0);
}

char * transport::receber(int sock){
    char msg[BUFFER_SIZE];
    ssize_t msgSize = recv(sock, msg, sizeof(msg) - 1, 0);

    if (msgSize > 0){
        msg[msgSize] = '\0';
        return msg;
    }
    
    return "";
}

void transport::fechar_socket(int sock){
    close(sock);
}


