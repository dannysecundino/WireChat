#include "../headers/GUI.hpp"

#include <iostream>
#include <string>

int main(){
    std::string nome = GUI::tela_inicial();
    std::cout << nome << '\n';

    return 0;
}