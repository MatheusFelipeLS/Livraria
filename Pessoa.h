#ifndef PESSOA_H
#define PESSOA_H
#include <iostream>
#include <vector>

using namespace std;

class Pessoa {
  public:
    Pessoa();
    Pessoa(string, string, string, string, string, string);
    Pessoa(string, string, string, string, string, string, int);
    ~Pessoa();
  
    void setNome(string);
    void setCpf(string);
    void setCodigo(int);
    void setEndereco(string);
    void setTelefone(string);
    void setEmail(string);
    void setSenha(string);
    void setTipo(int);

    string getNome();
    string getCpf();
    int getCodigo();
    string getEndereco();
    string getTelefone();
    string getEmail();
    string getSenha();
    int getTipo();
  
  protected:
    string nome;
    string cpf;
    int codigo;
    string endereco;
    string telefone;
    string email;
    string senha;
    int tipo;
};

#endif