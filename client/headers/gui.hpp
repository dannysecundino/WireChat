#pragma once            // serve para dizer que esse header deve ser incluído, no máximo, uma vez por unidade de compilação

#include <string>  
#include <vector>

namespace gui{
    // funções
    std::string tela_inicial();
    std::string menu(std::vector <std::string> salas);
};