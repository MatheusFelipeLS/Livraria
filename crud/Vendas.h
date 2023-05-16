#pragma once
#include "Livro.h"

class Vendas {
    public:
        Vendas();
        ~Vendas();

        void iniciaVendas();
        void listarLivrosVendidos();
        void salvarEmArquivo(Livro);

   private:
        vector<Livro> livrosVendidos;

        //Funções para mexer no arquivo vendas.csv
        void reescreveArquivo();
        int verificaVendaIgual(Livro);

        //Funcções para exibir informações
        void informacoesLivros(Livro, int);
};