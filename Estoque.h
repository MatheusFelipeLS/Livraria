#ifndef ESTOQUE_H
#define ESTOQUE_H
#include "Livro.h"
#include <vector>

class Estoque {
  //Funções se encontram na mesma ordem em Estoque.cpp
  public:
    Estoque();
    ~Estoque();

    void iniciaEstoque();
    
    void exibe1();
    void listarLivros();

    void adicionarLivro();
    Livro removerLivro();
    void alterarDadosLivro();
    void apagarEstoque();

  private:

    //funções de exibição
    void exibeParecidos(string);
    void informacoesLivros(Livro, int);

    //funções para mexer no arquivo estoque.csv
    void salvarEmArquivo(Livro);
    void reescreveArquivo();
    void ordenaAlfabeticamente();

    //funções para procurar uma caracteristica especifica do livro
    int idExiste(int, int);
    Livro tituloExiste(string);
    int livroExiste(Livro);

    Livro removeIds(Livro, int);

    //atributo
    vector<Livro> livros;
};

#endif
