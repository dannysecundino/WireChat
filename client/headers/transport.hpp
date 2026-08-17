#pragma once            // serve para dizer que esse header deve ser incluído, no máximo, uma vez por unidade de compilação


namespace transport {
    int criar_client_socket();
    int conectar_ao_server(int sock, int PORT);     // vai ficar no local host por enquanto


    void enviar(int csock, const void *dado, size_t tamanho);
    char *receber(int sock);

    void fechar_socket(int sock);
};