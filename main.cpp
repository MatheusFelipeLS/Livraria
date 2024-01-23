#include <iostream>
#include <fstream>
#include "FuncionariosCadastrados.h"
#include "Estoque.h"
#include "Livro.h"
#include "Vendas.h"
#include "Menu.h"

using namespace std;

int main() {
  Estoque estoque;
  FuncionariosCadastrados funcionarios;
  Menu menu;
  Livro livro;
  Vendas vendas;
  bool voltar = true;
  int tipoDeEntrada, opcao = -1;
  char mostraOpcoes = 's';
  string nome;

  while(true) {
    tipoDeEntrada = -1;
    while(tipoDeEntrada < 0 || tipoDeEntrada > 2) {
      menu.opcoesDeEntrada();
      // Pergunta que o que o usuário quer fazer
      cin >> tipoDeEntrada;
      cout << endl;
      //verifica se o usuário colocou um tipo válido
      if(tipoDeEntrada < 0 || tipoDeEntrada > 2) {
        cout << "Opção inválida." << endl;
      }
    } 

    //verifica se o programa deve ser fechado
    if(tipoDeEntrada == 0) {
      break;
    }  

    if(tipoDeEntrada == 1) {
      cin.ignore();
    }
 
    //iniciando o estoque
    estoque.iniciaEstoque();
    funcionarios.iniciaFuncionarios();
    vendas.iniciaVendas();

    if(funcionarios.getTamanho() == 0) {
      funcionarios.cadastrarFuncionario();
      continue;
    }

    if(tipoDeEntrada == 1) {
      voltar = funcionarios.acessarConta();
      mostraOpcoes = 's';
      while(voltar) {
        while(opcao < 0 || opcao > 14) {
          if(mostraOpcoes == 's') {
            menu.opcoesDeFuncionario(funcionarios.getCargo()); //funcionarios.getCargo()
          }
          cin >> opcao;
          cin.ignore();

          cout << endl;
          if(opcao < 0 || opcao > 14) {
            cout << "Opção inválida" << endl;
          }
        }
        switch (opcao) {
          case 0:
            //caso para retornar para o while anterior (perguntar o que deseja fazer)
            voltar = false;
            break;
          case 1:
            estoque.adicionarLivro();
            break;
          case 2:
            estoque.exibe1();
            break;
          case 3:
            estoque.listarLivros();
            break;
          case 4:
            estoque.alterarDadosLivro();
            break;
          case 5:
            livro = estoque.removerLivro();
            if(livro.getTitulo().compare("") == 0) {
              break;
            }
            funcionarios.adicionarVendas();
            vendas.salvarEmArquivo(livro);
            break;
          case 6:
            funcionarios.alterarDadosPessoais();
          case 7:
            funcionarios.apagarConta();
            break;
          default:
            if(funcionarios.getCargo() == 1) {
              if(opcao == 8) {
                funcionarios.cadastrarFuncionario();
              } else if(opcao == 9) {
                funcionarios.alterarDadosFuncionario();
              }else if(opcao == 10) {
                funcionarios.listarFuncionarios();
              }else if(opcao == 11) {
                funcionarios.apagarFuncionario();
              }else if(opcao == 12) {
                funcionarios.promoverGerente();
              }else if(opcao == 13) {
                estoque.apagarEstoque();
              }else if(opcao == 14) {
                vendas.listarLivrosVendidos();
              }
            }
            break;
          }
        if(opcao != 0) {
          cout << "Deseja rever as opções? \"s\" p/ sim, \"n\" p/ não" << endl;
          cin >> mostraOpcoes;
          cin.ignore();
        }
        opcao = -1;
      }
    } else {
      funcionarios.alterarSenha();
    }
  }

  cout << "Encerrando programa..." << endl;

  return 0;
}