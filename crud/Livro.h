#ifndef LIVRO_H
#define LIVRO_H
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Livro {
  public:
    Livro();
    Livro(string tit, string aut, string edit, string gen, double pre);
    ~Livro();

    void setTitulo(string);
    void setAutor(string);
    void setEditora(string);
    void setGenero(string);
    void setPreco(double);
    void setQuantidade(int);

    string getTitulo();
    string getAutor();
    string getEditora();
    string getGenero();
    double getPreco();
    vector<int> getId();
    int getQuantidade();

    void adicionaId(int);
    void removeId(int);
    void zeraIds();

  private:
    string titulo = "";
    string autor = "";
    string editora = "";
    string genero = "";
    double preco= 0.0;
    vector<int> id;
    int quantidade = 0;
};

#endif //Livro.h