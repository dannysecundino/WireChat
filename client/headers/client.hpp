#pragma once            // serve para dizer que esse header deve ser incluído, no máximo, uma vez por unidade de compilação

#include <string>
#include <string_view>

class Client {
protected:
    int clientSock;
    std::string nome;
public:
    // Construtor e Destrutos
    Client(std::string_view nome);
    ~Client();

    // métodos
    void logar_no_server(std::string_view nome);
    void ser_atendido_pelo_server();
};