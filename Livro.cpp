#include "Livro.h"

Livro::Livro() {
	//ctor
}

Livro::Livro(string tit, string aut, string edit, string gen, double pre) {
  titulo = tit;
  autor = aut;
  editora = edit;
  genero = gen;
  preco = pre;
}

Livro::~Livro() {
	//dtor
}

//métodos set
void Livro::setTitulo(string t) {
	titulo = t;
}

void Livro::setAutor(string a) {
	autor = a;
}

void Livro::setEditora(string e) {
	editora = e;
}

void Livro::setGenero(string g) {
  genero = g;
}

void Livro::setPreco(double p) {
	preco = p;
}

void Livro::setQuantidade(int q) {
	quantidade = q;
}

//métodos get
string Livro::getTitulo() {
	return titulo;
}

string Livro::getAutor() {
	return autor;
}

string Livro::getEditora() {
	return editora;
}

string Livro::getGenero() {
	return genero;
}

double Livro::getPreco() {
	return preco;
}

vector<int> Livro::getId() {
	return id;
}

int Livro::getQuantidade() {
	return quantidade;
}

//Funções para mexer nos id's
void Livro::adicionaId(int i) {
  id.push_back(i);
  quantidade++;
}

void Livro::removeId(int i) {
  //i = pos do id do livro
  id.erase(id.begin() + i);
  quantidade--;
}

void Livro::zeraIds() {
	id.clear();
	quantidade = 0;
}