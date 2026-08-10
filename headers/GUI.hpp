#pragma once            // serve para dizer que esse header deve ser incluído, no máximo, uma vez por unidade de compilação

#include <string_view>  // string_view não guarda a string, só uma visão dela, impedindo que se crie uma cópia

namespace GUI{
    // funções
    void pintar_caracteres(std::string_view cor);
    void imprimir_cabecalho();
};