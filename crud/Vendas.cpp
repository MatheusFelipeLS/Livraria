#include "Vendas.h"
#include <fstream>
#include <sstream>

Vendas::Vendas() {
    //ctor
}

Vendas::~Vendas() {
    //dtor
}

void Vendas::iniciaVendas() {
  //FUNÇÃO QUE INICIALIZA O ESTOQUE
  fstream fp;
  string titulo, autor, editora, genero;
  string linha;
  double preco;
  int quantidade;
  int id;

  fp.open("Vendas.csv", fstream::in);

  // verifica se o arquivo abriu corretamente
  if (!fp.is_open()) {
    cout << "Erro ao abrir o arquivo estoque para leitura" << endl;
  }

  while (getline(fp, linha)) {
    stringstream ss(linha);
    // adiciona os valores de um livro a variáveis
    getline(ss, titulo, ';');
    getline(ss, autor, ';');
    getline(ss, editora, ';');
    getline(ss, genero, ';');
    ss >> preco;
    ss.ignore();
    ss >> quantidade;
    ss.ignore();

    // cria um objeto do tipo livro
    Livro livro(titulo, autor, editora, genero, preco);

    for(int i = 0; i < quantidade; i++) {
      ss >> id;
      ss.ignore();
      livro.adicionaId(id);  
    }
    // adiciona o objeto livro ao vetor de livros
    livrosVendidos.push_back(livro);
  }
  fp.close();
}

void Vendas::listarLivrosVendidos() {
  int maior = 0, indMaior = 0, quant = 0;
  double lucro = 0;
  for (int i = 0; i < livrosVendidos.size(); i++) {
    lucro += livrosVendidos[i].getPreco() * livrosVendidos[i].getQuantidade();
    quant += livrosVendidos[i].getQuantidade();
    informacoesLivros(livrosVendidos[i], 0);
    if(livrosVendidos[i].getQuantidade() > maior) {
      maior = livrosVendidos[i].getQuantidade();
      indMaior = i;
    }
  }
  cout << endl << "Livro mais vendido: ";
  informacoesLivros(livrosVendidos[indMaior], -1);
  cout << endl << "Lucro total: R$ " << lucro << endl;
  cout << quant << " livros vendidos no total." << endl;
  cout << endl;
}

void Vendas::salvarEmArquivo(Livro liv) {
    fstream fp;
    int aux;
    vector<int> auxId = liv.getId();

    // abre o arquivo no modo para escrita
    fp.open("Vendas.csv", fstream::app); // app para adicionar (append)
    // verifica se o arquivo abriu corretamente

    if (!fp.is_open()) {
        cout << "Erro ao abrir o programa para escrita" << endl;
        return;
    }

    aux = verificaVendaIgual(liv);
    if(aux != -1) {
        livrosVendidos[aux].adicionaId(auxId[0]);
        reescreveArquivo();
    } else {
        fp << liv.getTitulo() << ";";
        fp << liv.getAutor() << ";";
        fp << liv.getEditora() << ";";
        fp << liv.getGenero() << ";";
        fp << liv.getPreco() << ";";
        fp << liv.getQuantidade() << ";";
        fp << auxId[0] << endl;
    }
  // adicionando os valores no arquivo. 

  fp.close();
}

int Vendas::verificaVendaIgual(Livro liv) {
  int i;
  for(i = 0; i < livrosVendidos.size(); i++) {
      if(livrosVendidos[i].getTitulo().compare(liv.getTitulo()) == 0 && livrosVendidos[i].getAutor().compare(liv.getAutor()) == 0) {
          return i;
      }  
  }
  return -1;
}

void Vendas::reescreveArquivo() {
  fstream fp;
  int auxQuant = 0;

  // abre o arquivo no modo para escrita
  fp.open("Vendas.csv", fstream::out); // out para sobrescrever
  // verifica se o arquivo abriu corretamente
  if (!fp.is_open()) {
    cout << "Erro ao abrir o programa para atualização." << endl;
    return;
  }

  // adicionando os valores no arquivo.
  for (int j = 0; j < livrosVendidos.size(); j++) {
    fp << livrosVendidos[j].getTitulo() << ";";
    fp << livrosVendidos[j].getAutor() << ";";
    fp << livrosVendidos[j].getEditora() << ";";
    fp << livrosVendidos[j].getGenero() << ";";
    fp << livrosVendidos[j].getPreco() << ";";
    fp << livrosVendidos[j].getQuantidade() << ";";
    vector<int> auxId = livrosVendidos[j].getId();
    for(auxQuant = 0; auxQuant < livrosVendidos[j].getQuantidade() - 1; auxQuant++) {
      fp << auxId[auxQuant] << ";";
    }
    fp << auxId[auxQuant] << endl;
  }

  fp.close();
}

void Vendas::informacoesLivros(Livro liv, int x) {
  //exibe as informações de um livro que foi passado no parametro
      cout << endl << "Título: " << liv.getTitulo() << endl
      << "Autor(a): " << liv.getAutor() << endl
      << "Editor(a): " << liv.getEditora() << endl
      << "Gênero(s): " << liv.getGenero() << endl
      << "Preço: R$ " << liv.getPreco() << endl
      << "Quantidade vendida: " << liv.getQuantidade() << " unidade(s)" << endl;
}
