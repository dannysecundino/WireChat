#include "../headers/transport.hpp"

#include <iostream>

#include <sys/socket.h>     // socket()
#include <netinet/in.h>     // endereço de socket
#include <unistd.h>         // close()

#define BUFFER_SIZE 4096


// funções para detalhes de implementação
void preencher_endereco_server(struct sockaddr_in* endereco, int PORT){
    *endereco = {};                                 // para resetar o espaço de memória serverAdress (isso só tem em C++)
    
    endereco->sin_family = AF_INET;                 // IPv4
    endereco->sin_port = htons(PORT);               // porta
    endereco->sin_addr.s_addr = htonl(INADDR_ANY);  // para o loopback (localhost) seria INADDR_LOOPBACK
}



// funções do namespace
int transport::criar_client_socket(){
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == -1){
        std::cout << "error in socket()";
        return -1;
    }
    
    // retornar o socket
    return sock;
}

int transport::conectar_ao_server(int sock, int PORT){
    // preencher o endereço
    struct sockaddr_in serverAdress;
    preencher_endereco_server(&serverAdress, PORT);

    // fazer o connect()
    int test = connect(sock, (struct sockaddr *) &serverAdress, sizeof(serverAdress));
    if (test == -1){
        std::cout << "error in connect()\n";
        close(sock);
        return -1;
    } else {
        return 0;
    }

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