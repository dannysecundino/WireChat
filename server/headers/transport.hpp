#pragma once            // serve para dizer que esse header deve ser incluído, no máximo, uma vez por unidade de compilação

namespace transport {
    int criar_lsock(int PORT, int BACKLOG);
    int aceitar_cliente(int lsock);

    void enviar(int csock, char* dado);   // string_view pq n altera o que se envia
    char *receber(int csock);

    void fechar_socket(int sock);
};