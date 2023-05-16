#include "Funcionario.h"

Funcionario::Funcionario() {
  //ctor
}

Funcionario::Funcionario(string n, string c, string e, string t, string l, string s) : Pessoa(n, c, e, t, l, s){

}

Funcionario::Funcionario(string n, string c, string e, string t, string l, string s, int tp) : Pessoa(n, c, e, t, l, s, tp) {
  tipo = tp;
}

Funcionario::Funcionario(string n, string c, string e, string t, string l, string s, int tp, double sl, int ca) : Pessoa(n, c, e, t, l, s, tp){
  salario = sl;
  clientesAtendidos = ca;
  tipo = tp;
}

Funcionario::~Funcionario() {
  //dtor
}

double Funcionario::getSalario() {
	return salario;
}

int Funcionario::getCliente() {
	return clientesAtendidos;
}

void Funcionario::setSalario(double s) {
  salario = s;
}

void Funcionario::setClientes(int c) {
  clientesAtendidos = c;
}

void Funcionario::aumentaClientes(){
	clientesAtendidos++;
}