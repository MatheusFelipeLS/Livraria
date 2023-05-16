#include "Estoque.h"
#include <fstream>
#include <sstream>

Estoque::Estoque() {
  // ctor
}

Estoque::~Estoque() {
  // dtor
}

//FUNÇÕES PARA MEXER NO ARQUIVO Estoque.csv
void Estoque::iniciaEstoque() {
  //FUNÇÃO QUE INICIALIZA O ESTOQUE
  fstream fp;
  string titulo, autor, editora, genero;
  string linha;
  double preco;
  int quantidade;
  int id;

  fp.open("Estoque.csv", fstream::in);

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
    livros.push_back(livro);
  }
  fp.close();
}

void Estoque::exibe1() {
  string tit;
  char parecidos = 'n';
  
  cout << "Título do livro que deseja ver: ";
  getline(cin, tit);

  Livro livro = tituloExiste(tit);

  if(livro.getTitulo().compare("") != 0) {
    informacoesLivros(livro, -1);
  }else{
    cout << "Livro não encontrado." << endl;
  }

  cout << "Deseja ver livros parecidos? \"s\" p/ sim" << endl;
  cin >> parecidos;
  cin.ignore();
  if(parecidos == 's') {
    exibeParecidos(tit);
  }
}

void Estoque::listarLivros() {
  for (int i = 0; i < livros.size(); i++) {
    informacoesLivros(livros[i], -1);
  }
  cout << endl;
}

void Estoque::adicionarLivro() {
  string titulo, autor, editora, genero;
  int id, livroIgual = -1;
  double preco; 
  char cadastrar = 's';
  int auxVerifLivExist;

  while (cadastrar == 's') {
    if (livroIgual < 0) {
      cout << "Título do livro: ";
      getline(cin, titulo);
      cout << "Autor(a) do livro: ";
      getline(cin, autor);
      cout << "Editora: ";
      getline(cin, editora);
      cout << "Gênero do livro: ";
      getline(cin, genero);
      cout << "Preço do livro: ";
      cin >> preco;
    }
    int verificaLivroExiste = -1;

    while (livroIgual < 0) {
      cout << "Deseja cadastrar quantos livro igual a esse? Digite 0 p/ sair" << endl;
      cin >> livroIgual;
      cin.ignore();
    }

    Livro livro = Livro(titulo, autor, editora, genero, preco);
    
    verificaLivroExiste = livroExiste(livro);
    auxVerifLivExist = verificaLivroExiste;
    if(verificaLivroExiste == -1) {
      livros.push_back(livro);
      verificaLivroExiste = (livros.size() - 1);
    }

    while(livroIgual > 0) {
      livroIgual--;
      cout << "ID do livro: ";
      cin >> id;
      cin.ignore();
      if(idExiste(id, verificaLivroExiste) == -1) {
        livros[verificaLivroExiste].adicionaId(id);
        cout << "Livro foi adicionado ao estoque." << endl;
      }else {
        cout << "ID já existe no estoque. Digite outro id." << endl;
        livroIgual++;
      }
    }

    
    cadastrar = 'h';
    while (cadastrar != 'n' && cadastrar != 's') {
      cout << "Deseja cadastrar um novo livro? \"s\" para sim, \"n\" para não" << endl;
      cin >> cadastrar;
      cin.ignore();
    }
    livroIgual = -1;
  }
  
  ordenaAlfabeticamente();

  reescreveArquivo();
}

Livro Estoque::removerLivro() {
  int i, j, id;
  Livro liv, livAux;
  char livCorreto;

  cout << "ID do livro que deseja remover do estoque: ";
  cin >> id;
  cin.ignore();
  // verificando se tem o livro no estoque
  for(j = 0; j < livros.size(); j++) {
    i = idExiste(id, j);
    if (i != -1) {
      livCorreto = 'n';
      informacoesLivros(livros[j], i);
      cout << "Esse é o livro vendido? \"s\" para sim" << endl;
      cin >> livCorreto;
      cin.ignore();
      if(livCorreto == 's') {
        liv = livros[j];
        livros[j].removeId(i);
        livAux = removeIds(liv, id);
        if(livros[j].getQuantidade() == 0) {
          livros.erase(livros.begin() + j);
        }
        reescreveArquivo();
        cout << "Livro removido do estoque." << endl;
        return livAux;
      }
      i = -1;
    }
  }
  
  cout << "Livro não encontrado no estoque." << endl;

  return livAux;
}

void Estoque::alterarDadosLivro() {
  int i, j, id;
  string titulo, autor, editora, genero;
  double preco;
  Livro liv;
  char alterar = 's';

  while(alterar == 's') {
    alterar = 'h';
    cout << "Título do livro que deseja alterar: ";
    getline(cin, titulo);
    // verificando se tem o livro no estoque
    liv = tituloExiste(titulo);
    i = livroExiste(liv);
    if (i != -1) {
      cout << "Reescreva as informações do livro." << endl;
      cout << "Título do livro: ";
      getline(cin, titulo);
      cout << "Autor(a) do livro: ";
      getline(cin, autor);
      cout << "Editora: ";
      getline(cin, editora);
      cout << "Gênero do livro: ";
      getline(cin, genero);
      cout << "Preço do livro: ";
      cin >> preco;
      cin.ignore();
      livros[i].setTitulo(titulo);
      livros[i].setAutor(autor);
      livros[i].setEditora(editora);
      livros[i].setGenero(genero);
      livros[i].setPreco(preco);
      cout << "Livro alterado com sucesso." << endl;
      reescreveArquivo();
      return;
    }else {
      cout << "Livro não encontrado no estoque." << endl
      << "Deseja ver livros parecidos? \"s\" p/ sim" << endl;
      char parecidos;
      cin >> parecidos;
      cin.ignore();
      if(parecidos == 's') {
        exibeParecidos(titulo);
      }
      cout << "Deseja alterar algum desses livros? \"s\" p/ sim" << endl;
      cin >> alterar;
      cin.ignore();
    }
  }
}

void Estoque::apagarEstoque() {
  char confirmar = 'n';
  cout << "Tem certeza que deseja apagar o estoque? \"s\" para sim" << endl;
  cin >> confirmar;
  cin.ignore();
  if(confirmar == 's') {
    livros.clear();
    reescreveArquivo();
  }
}

void Estoque::exibeParecidos(string tit) {
  int pos;
  for(int i = 0; i < livros.size(); i++) {
    pos = livros[i].getTitulo().find(tit); 
    if(pos >= 0 && pos < livros[i].getTitulo().length()) {
      informacoesLivros(livros[i], -1);
      break;
    }
  }
}

void Estoque::informacoesLivros(Livro liv, int x) {
  //exibe as informações de um livro que foi passado no parametro
  cout << endl << "Título: " << liv.getTitulo() << endl
  << "Autor(a): " << liv.getAutor() << endl
  << "Editor(a): " << liv.getEditora() << endl
  << "Gênero(s): " << liv.getGenero() << endl
  << "Preço: R$ " << liv.getPreco() << endl;
  if(x == -1) {
    cout << "Quantidade: " << liv.getQuantidade() << " unidade(s)" << endl;
  }else {
    cout << "Id: " << liv.getId()[x] << endl;
  }
}

void Estoque::salvarEmArquivo(Livro liv) {
  fstream fp;

  // abre o arquivo no modo para escrita
  fp.open("Estoque.csv", fstream::app); // app para adicionar (append)
  // verifica se o arquivo abriu corretamente
  if (!fp.is_open()) {
    cout << "Erro ao abrir o programa para escrita" << endl;
    return;
  }

  // adicionando os valores no arquivo. 
  fp << liv.getTitulo() << ";";
  fp << liv.getAutor() << ";";
  fp << liv.getEditora() << ";";
  fp << liv.getGenero() << ";";
  fp << liv.getPreco() << ";";
  fp << liv.getQuantidade() << ";";
  vector<int> aux = liv.getId();
  for(int i = 0; i < liv.getQuantidade() - 1; i++) {
    fp << aux[i] << ";";
  }
  fp << aux[liv.getQuantidade()] << endl;
  
  fp.close();
}

void Estoque::reescreveArquivo() {
  fstream fp;
  int auxQuant = 0;

  // abre o arquivo no modo para escrita
  fp.open("Estoque.csv", fstream::out); // out para sobrescrever
  // verifica se o arquivo abriu corretamente
  if (!fp.is_open()) {
    cout << "Erro ao abrir o programa para atualização." << endl;
    return;
  }

  // adicionando os valores no arquivo.
  for (int j = 0; j < livros.size(); j++) {
    fp << livros[j].getTitulo() << ";";
    fp << livros[j].getAutor() << ";";
    fp << livros[j].getEditora() << ";";
    fp << livros[j].getGenero() << ";";
    fp << livros[j].getPreco() << ";";
    fp << livros[j].getQuantidade() << ";";
    vector<int> auxId = livros[j].getId();
    for(auxQuant = 0; auxQuant < livros[j].getQuantidade() - 1; auxQuant++) {
      fp << auxId[auxQuant] << ";";
    }
    fp << auxId[auxQuant] << endl;
  }

  fp.close();
}

void Estoque::ordenaAlfabeticamente() {
  Livro aux;
  int trocou, i;
  trocou = 1;
    while(trocou){
        trocou = 0;
        for(i = 0; i < livros.size()-1; i++){
            if (livros[i].getTitulo().compare(livros[i+1].getTitulo()) > 0){
                aux = livros[i];
                livros[i] = livros[i+1];
                livros[i+1] = aux;
                trocou = 1;
            }
        }
    }
}

//Funções para achar livros no arquivo (Pelo título, autor, gênero, id)
int Estoque::idExiste(int ident, int pos) {
  // verifica se o livro com determinado id existe
  vector<int> aux = livros[pos].getId();
  for (int i = 0; i < livros[pos].getQuantidade(); i++) {
    // verifica se o id foi encontrado
    if (ident == aux[i]) {
      return i;
      }
    }
  // se saiu do for, o livro não foi encontrado no vetor. Retorna -1
  return -1;
}

Livro Estoque::tituloExiste(string tit) {
  int i;
  Livro livro;

  for(i = 0; i < livros.size(); i++) {
    if(tit.compare(livros[i].getTitulo()) == 0) {
      livro = livros[i];
      return livro;
    }
  }

  cout << "Livro não existe!" << endl;
  return livro;
}

int Estoque::livroExiste(Livro liv) {
  for(int i = 0; i < livros.size(); i++) {
    if(liv.getTitulo().compare(livros[i].getTitulo()) == 0 && liv.getAutor().compare(livros[i].getAutor()) == 0) {
      return i;
    }
  }
  return -1;
}

Livro Estoque::removeIds(Livro liv, int id) {
  liv.zeraIds();
  liv.adicionaId(id);

  return liv;
}
