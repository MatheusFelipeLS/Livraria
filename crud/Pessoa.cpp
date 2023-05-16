#include "Pessoa.h"

Pessoa::Pessoa() {
  //ctor
}

Pessoa::~Pessoa() {
  // dtor
}

Pessoa::Pessoa(string n, string c, string e, string t, string l, string s) {
  nome = n;
  cpf = c;
  endereco = e;
  telefone = t;
  email = l;
  senha = s;
}

Pessoa::Pessoa(string n, string c, string e, string t, string l, string s, int tp) {
  nome = n;
  cpf = c;
  endereco = e;
  telefone = t;
  email = l;
  senha = s;
  tipo = tp;
}

// métodos set
void Pessoa::setNome(string n) { 
  nome = n;
}

void Pessoa::setCpf(string c) { 
  cpf = c;
}

void Pessoa::setCodigo(int c) { 
  codigo = c; 
}

void Pessoa::setEndereco(string e) {
  endereco = e;
}

void Pessoa::setTelefone(string t) { 
  telefone = t;
}

void Pessoa::setEmail(string l) {
	email = l;
}

void Pessoa::setSenha(string s) {
  senha = s; 
}

void Pessoa::setTipo(int t) {
  tipo = t;
}

// métodos get
string Pessoa::getNome() { 
	return nome;
}

string Pessoa::getCpf() { 
	return cpf;
}

int Pessoa::getCodigo() { 
	return codigo;
}

string Pessoa::getEndereco() { 
	return endereco;
}

string Pessoa::getTelefone() { 
	return telefone;
}

string Pessoa::getEmail() { 
	return email;
}

string Pessoa::getSenha() {
  return senha;
}

int Pessoa::getTipo() {
  return tipo;
}