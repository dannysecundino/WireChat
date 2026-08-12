#include "../headers/client.hpp"

#include "../headers/network.hpp"
#include "../headers/gui.hpp"

#include <iostream>
#include <string_view>
#include <string>
#include <vector>

#define SERVER_PORT 9090 

// funções para detalhes de implementação


// Construtor e Destrutor
Client::Client(std::string_view nome){
    this->nome = nome;
    this->clientSock = network::criar_client_socket();
}

Client::~Client(){
    network::fechar_socket(this->clientSock);
}

// métodos
void Client::logar_no_server(std::string_view nome){
    // conectar no server
    network::conectar_ao_server(this->clientSock, SERVER_PORT);

    // enviar o nome de login
    network::enviar(this->clientSock, nome);

    // TODO: receber a resposta do server (saber se já tem alguém com aquele nome)
}

void Client::ser_atendido_pelo_server(){
    // 1. receber nome da tela inicial
    std::string_view nome = gui::tela_inicial();

    // 2. logar com esse nome
    this->logar_no_server(nome);

    // 3. receber a lista de salas
    std::vector <std::string> salas_disponiveis;
    for (int i = 0; i < 3; ++i){   // FIX: receber todas as salas
        std::string sala = network::receber(this->clientSock);
        salas_disponiveis.push_back(sala);
    }

    // 4. mostrar salas e receber a sala desejada
    std::string_view sala_desejada = gui::menu(salas_disponiveis);

    // 5. mandar a sala desejada para o server
    network::enviar(this->clientSock, sala_desejada);

    // 6. testar
    if (network::receber(this->clientSock) == "OK") std::cout << "We have something\n";
}