#pragma once            // serve para dizer que esse header deve ser incluído, no máximo, uma vez por unidade de compilação

#include <string>
#include <string_view>

namespace network {
    int criar_lsock(int PORT, int BACKLOG);
    int aceitar_cliente(int lsock);

    void enviar(int csock, std::string_view msg);   // string_view pq n altera o que se envia
    std::string receber(int csock);

    void fechar_socket(int sock);
};