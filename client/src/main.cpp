#include "../headers/gui.hpp"

#include <iostream>
#include <string>

int main(){
    std::string nome = gui::tela_inicial();
    std::cout << nome << '\n';

    return 0;
}