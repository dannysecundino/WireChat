#include "../headers/server.hpp"

#include "../headers/network.hpp"

#include <string_view>
#include <vector>
#include <tuple>
#include <format>

#define SERVER_PORT 9090
#define BACKLOG 10

// funções para detalhes de implementação


// Construtor e Destrutor
Server::Server(){
    this->lsock = network::criar_lsock(SERVER_PORT, BACKLOG);
}

Server::~Server(){
    network::fechar_socket(this->lsock);
}

// métodos
int Server::logar_cliente(){
    // 0. aceitar o cliente (criar o socket de conexão)
    int csock = network::aceitar_cliente(this->lsock);

    // 1. receber o nome do cliente
    std::string_view nome = network::receber(csock);

    // 2. guardar o cadastro
    this->clientes.emplace_back(nome, csock);

    return csock;
}

void Server::atender_cliente(){
    // 1. logar cliente
    int csock = logar_cliente();

    // 2. mandar lista de salas
    std::vector <std::string> salas = this->salas;
    for (int i = 0; i < salas.size(); ++i){
        network::enviar(csock, salas[i]);
        network::enviar(csock, "\n");
    }
    
    // 3. esperar resposta da sala desejada
    std::string sala_desejada = network::receber(csock);
    
    // teste
    network::enviar(csock, "OK");
}