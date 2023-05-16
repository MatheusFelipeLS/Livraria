#ifndef FUNCIONARIO_H
#define FUNCIONARIO_H
#include "Pessoa.h"
#include <fstream>
#include <sstream>

class Funcionario : public Pessoa {
  public:
    Funcionario();
    Funcionario(string, string, string, string, string, string);
    Funcionario(string, string, string, string, string, string, int);
    Funcionario(string, string, string, string, string, string, int, double, int);
    ~Funcionario();
  
    double getSalario();
    int getCliente();
  
    void setSalario(double);
    void setClientes(int);
  
    void aumentaClientes();
  
  private:
    double salario = 0.0;
    int clientesAtendidos = 0;
};

#endif