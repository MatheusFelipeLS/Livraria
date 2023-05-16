#include "Menu.h"

Menu::Menu() {
    //ctor
}

Menu::~Menu() {
    //dtor
}

void Menu::opcoesDeEntrada() {
cout << "0 - Encerrar programa" << endl
  << "1 - Entrar" << endl
  << "2 - Alterar senha" << endl
  << "Escolha uma opção: ";
}


void Menu::opcoesDeFuncionario(int tipo) {
  cout << endl
  << "=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=" << endl
  << "0  -  Voltar" << endl
  << "1  -  Cadastrar livro no estoque" << endl
  << "2  -  Pesquisar livro por título" << endl
  << "3  -  Listar todos os livros do estoque" << endl
  << "4  -  Alterar dados do livro" << endl
  << "5  -  Vender livro" << endl
  << "6  -  Alterar dados pessoais" << endl
  << "7  -  Excluir conta" << endl;
  if(tipo == 1) {
    cout << "8  -  Cadastrar funcionário" << endl
    << "9  -  Modificar dados de funcionário" << endl
    << "10 -  Listar funcionários" << endl
    << "11 -  Remover funcionário" << endl
    << "12 -  Promover a gerente" << endl
    << "13 -  Zerar estoque" << endl
    << "14 -  Gerar relatório de vendas" << endl;
  }
  cout << "Escolha uma opção: ";
}

/* caso existisse cliente
void Menu::opcoesDeAcesso(int t) {
    cout << "0 - Voltar" << endl 
    << "1 - Gerente" << endl
    << "2 - Funcionário" << endl
    << "Como deseja continuar? ";
}
*/