#include "../headers/GUI.hpp"

#include <string_view>

#include <iostream>
#include <string>

void GUI::pintar_caracteres(std::string_view cor) {
    if (cor == "reset") 
        std::cout << "\033[0m";
    
    else if (cor == "preto") 
        std::cout << "\033[30m";
    
    else if (cor == "vermelho") 
        std::cout << "\033[31m";
    
    else if (cor == "verde") 
        std::cout << "\033[32m";
    
    else if (cor == "amarelo") 
        std::cout << "\033[33m";
    
    else if (cor == "azul") 
        std::cout << "\033[34m";
    
    else if (cor == "magenta") 
        std::cout << "\033[35m";
    
    else if (cor == "ciano") 
        std::cout << "\033[36m";
    
    else if (cor == "branco") 
        std::cout << "\033[37m";
    
    else if (cor == "preto_claro") 
        std::cout << "\033[90m";
    
    else if (cor == "vermelho_claro") 
        std::cout << "\033[91m";
    
    else if (cor == "verde_claro") 
        std::cout << "\033[92m";
    
    else if (cor == "amarelo_claro") 
        std::cout << "\033[93m";
    
    else if (cor == "azul_claro") 
        std::cout << "\033[94m";
    
    else if (cor == "magenta_claro") 
        std::cout << "\033[95m";
    
    else if (cor == "ciano_claro") 
        std::cout << "\033[96m";
    
    else if (cor == "branco_claro") 
        std::cout << "\033[97m";
    
}

void GUI::imprimir_cabecalho(){
    // como a barra já indica um char diferente (ex.: \n), vamos usar uma coisa camada RAW STRING LITERAL (guarda literalmente a string, sem interpretar o que está dentro dela)
    std::string titulo = 
R"( _       ___           ________          __ 
| |     / (_)_______  / ____/ /_  ____ _/ /_
| | /| / / / ___/ _ \/ /   / __ \/ __ `/ __/
| |/ |/ / / /  /  __/ /___/ / / / /_/ / /_  
|__/|__/_/_/   \___/\____/_/ /_/\__,_/\__/
)";     // feio? feio. mas funciona e é mais limpo do que tratar cada barra


    // imprimir
    pintar_caracteres("verde");
    std::cout << titulo;
    pintar_caracteres("reset");
    std::cout << "A C++ network project by a curious student\n" ;
}

