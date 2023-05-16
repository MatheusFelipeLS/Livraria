#pragma once
#include <iostream>

using namespace std;

class Menu {
    public:
        Menu();
        ~Menu();

        void opcoesDeEntrada();
        void opcoesDeFuncionario(int tipo);

        //void opcoesDeAcesso(int);
};