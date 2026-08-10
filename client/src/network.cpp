#include "../headers/network.hpp"

#include <iostream>
#include <string>
#include <string_view>

#include <sys/socket.h>     // socket()
#include <netinet/in.h>     // endereço de socket
#include <unistd.h>         // close()
#include <string.h>

#define BUFFER_SIZE 4096


// funções para detalhes de implementação
void preencher_endereco_server(struct sockaddr_in* endereco, int PORT){
    *endereco = {};                                 // para resetar o espaço de memória serverAdress (isso só tem em C++)
    
    endereco->sin_family = AF_INET;                 // IPv4
    endereco->sin_port = htons(PORT);               // porta
    endereco->sin_addr.s_addr = htonl(INADDR_ANY);  // para o loopback (localhost) seria INADDR_LOOPBACK
}



// funções do namespace
int network::criar_client_socket(){
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == -1){
        std::cout << "error in socket()";
        return -1;
    }
    
    // retornar o socket
    return sock;
}

int network::conectar_ao_server(int sock, int PORT){
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

void network::enviar(int sock, std::string_view msg){
    send(sock, msg.data(), msg.size(), 0);
}

std::string network::receber(int sock){
    char msg[BUFFER_SIZE];
    ssize_t msgSize = recv(sock, msg, sizeof(msg) - 1, 0);
    if (msgSize > 0){
        msg[msgSize] = '\0';
        return std::string(msg);
    }
    
    return "";
}

void network::fechar_socket(int sock){
    close(sock);
}