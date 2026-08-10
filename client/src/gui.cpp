#include "../headers/gui.hpp"

#include <iostream>
#include <string_view>
#include <string>

// funções de detalhes de implementação
void pintar_caracteres(std::string_view cor) {
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
    
    else if (cor == "cinza") // preto_claro
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

void limpar_tela(){
    std::cout << "\033[2J\033[H";
}

void imprimir_cabecalho(){
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

void imprimir_about(){
    pintar_caracteres("cinza");
    std::cout << "About the project: WireChat is a general-purpose chat application\n";
    std::cout << "developed by Danny Secundino. Here, you can talk with your friends\n";
    std::cout << "and enjoy good times. It gets even better when you remember that\n";
    std::cout << "this is a C++ application created by integrating knowledge of\n";
    std::cout << "Software Engineering, OOP, and Computer Networking. Welcome!\n";
    pintar_caracteres("reset");
}

std::string receber_texto(){    // função que é para ser muito importante em todo o projeto
    // declarar string
    std::string texto;
    // receber conteúdo
    std::cin >> texto;
    // retornar string
    return texto;
}

// funções que estão no header
std::string gui::tela_inicial(){
    limpar_tela();
    imprimir_cabecalho();
    imprimir_about();

    std::cout << "Before we continue, I wanna know a thing about you: How should we call you?\n";
    std::cout << "> ";
    std::string nome = receber_texto();
    return nome;
}