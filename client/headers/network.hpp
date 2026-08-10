#pragma once            // serve para dizer que esse header deve ser incluído, no máximo, uma vez por unidade de compilação

#include <string> 
#include <string_view>


namespace network {
    int criar_client_socket();
    int conectar_ao_server(int sock, int PORT);     // vai ficar no local host por enquanto


    void enviar(int sock, std::string_view msg);    // string_view pq n altera o que se envia
    std::string receber(int sock);

    void fechar_socket(int sock);
};