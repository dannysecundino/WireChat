#pragma once            // serve para dizer que esse header deve ser incluído, no máximo, uma vez por unidade de compilação

#include <vector>
#include <string>
#include <tuple>

class Server {
private:
    int lsock;
    std::vector <std::tuple <std::string, int>> clientes;
    std::vector <std::string> salas = {"sala1", "sala2", "sala3"};
public:
    // get e set
    

    // Construtor e Destrutor
    Server();
    ~Server();

    // métodos [não precisa de método iniciar(), o construtor faz isso já]
    int logar_cliente();
    void atender_cliente();
};