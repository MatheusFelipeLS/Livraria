#include "FuncionariosCadastrados.h"

FuncionariosCadastrados::FuncionariosCadastrados() {
    //ctor
}

FuncionariosCadastrados::~FuncionariosCadastrados() {
    //dtor
}

//FUNÇÕES PARA MEXER NO ARQUIVO Funcionarios.csv
void FuncionariosCadastrados::iniciaFuncionarios() {
  //FUNÇÃO QUE INICIALIZA FUNCIONARIOS
  fstream fp;
  string nome, cpf, endereco, telefone, email, senha;
  string linha;
  double salario;
  int clientes, tipo;

  fp.open("Funcionarios.csv", fstream::in);

  // verifica se o arquivo abriu corretamente
  if (!fp.is_open()) {
    cout << "Erro ao abrir o arquivo clientes para leitura" << endl;
  }


  while (getline(fp, linha)) {
    stringstream ss(linha);
    // adiciona os valores de um cliente a variáveis
    getline(ss, nome, ';');
    getline(ss, cpf, ';');
    getline(ss, endereco, ';');
    getline(ss, telefone, ';');
    getline(ss, email, ';');
    getline(ss, senha, ';');
    ss >> tipo;
    ss.ignore();
    ss >> salario;
    ss.ignore();
    ss >> clientes;
    ss.ignore();

    // cria um objeto do tipo Funcionario
    Funcionario funcionario = Funcionario(nome, cpf, endereco, telefone, email, senha, tipo, salario, clientes);

    funcionarios.push_back(funcionario);
  }
  
  fp.close();
}

void FuncionariosCadastrados::adicionarVendas() {
  funcionarios[indexFuncionarioAcessado].aumentaClientes();
  reescreveArquivo();
}

bool FuncionariosCadastrados::acessarConta() {
  string str;
  int nFuncionario;

  while(true) {
    cout << "Digite 0 p/ voltar." << endl << "Email: ";
    getline(cin, str);

    if(str.compare("0") == 0)
      return false;

    nFuncionario = emailExiste(str); 
    if(nFuncionario != -1) {
      if(senhaCorreta(nFuncionario) != -1) {
        indexFuncionarioAcessado = nFuncionario;
        break;
      }else {
        continue;
      }
    }else {
      cout << endl << "Email inexistente" << endl
      << "Tente novamente" << endl;
    }
  }
  return true;
}

void FuncionariosCadastrados::cadastrarFuncionario() {
  string nome, cpf, endereco, telefone, email, senha;
  double salario;

  cout << "Informe o nome: ";
  getline(cin, nome);

  cout << "Informe o CPF: ";
  getline(cin, cpf);

  cout << "Informe o endereço: ";
  getline(cin, endereco);

  cout << "Informe o telefone: ";
  getline(cin, telefone);

  cout << "Informe o email: ";
  getline(cin, email);

  cout << "Informe a senha: ";
  getline(cin, senha);

  cout << "Informe o salário: ";
  cin >> salario;

  cin.ignore();
  Funcionario funcionario = Funcionario(nome, cpf, endereco, telefone, email, senha);
  if(funcionarios.size() > 0) {
    funcionario.setTipo(2);
  } else {
    funcionario.setTipo(1);
  }
  
  funcionario.setSalario(salario);
  funcionarios.push_back(funcionario);
  salvarEmArquivo(funcionario);

  cout << "O funcionário foi cadastrado com sucesso!" << endl;
}

void FuncionariosCadastrados::alterarDadosFuncionario() {
  string nome, cpf, endereco, telefone;
  int a;
  Funcionario func;

  cout << "Nome do funcionário que deseja alterar: ";
  getline(cin, nome);

  a = funcionarioExiste(nome);

  if(funcionarios[a].getNome().compare("") != 0) {
    cout << "Informe o nome: ";
    getline(cin, nome);
    funcionarios[a].setNome(nome);
    
    cout << "Informe o CPF: ";
    getline(cin, cpf);
    funcionarios[a].setCpf(cpf);
    
    cout << "Informe o endereço: ";
    getline(cin, cpf);
    funcionarios[a].setEndereco(cpf);
    
    cout << "Informe o telefone: ";
    getline(cin, cpf);
    funcionarios[a].setTelefone(cpf);
    
    cout << "Informe o salário: ";
    double salario;
    cin >> salario;
    func.setSalario(salario);
    
    salvarEmArquivo(func);
    
    cout << "O funcionário foi alterado com sucesso!" << endl;
  } else {
    cout << "Funcionário não encontrado" << endl;
  }
}

void FuncionariosCadastrados::alterarDadosPessoais() {
  cout << "O que deseja alterar?" << endl
  << "1 - Nome" << endl
  << "2 - CPF" << endl
  << "3 - Endereço" << endl
  << "4 - Telefone" << endl
  << "5 - Email" << endl
  << "6 - Senha" << endl;

  int opcao;
  cin >> opcao;
  cin.ignore();

  switch(opcao) {
    case 1:
      alterarNome();
      break;
    case 2:
      alterarCpf();
      break;
    case 3:
      alterarEndereco();
      break;
    case 4:
      alterarTelefone();
      break;
    case 5:
      alterarEmail();
      break;
    case 6:
      alterarSenha();
      break;
    default:
      cout << "Opção inválida" << endl;
  }
}

void FuncionariosCadastrados::apagarFuncionario() {
  int indexFunc = funcionarioExiste("");
  if(indexFunc == -1) {
    return;
  }
  funcionarios.erase(funcionarios.begin() + indexFunc);
  reescreveArquivo();
  cout << "Funcionário apagado com sucesso" << endl;
}

void FuncionariosCadastrados::apagarConta() {
  cout << "Tem certeza que deseja apagar sua conta?" << endl;
  cout << "Digite 1 para confirmar ou 0 para cancelar: ";
  int n;
  cin >> n;
  cin.ignore();
  if(n == 0) {
    return;
  }
  funcionarios.erase(funcionarios.begin() + indexFuncionarioAcessado);
  reescreveArquivo();
}

void FuncionariosCadastrados::alterarSenha() {
  string nome, email;
  int a = -1;
  char retornar;

  while(true) {
    while(a == -1) {
      cin.ignore();
      cout << "Informe seu nome: ";
      getline(cin, nome);
      a = funcionarioExiste(nome);
      if(a == -1) {
        cout << "Nome não cadastrado" << endl;
        return;
      }
    }

    indexFuncionarioAcessado = a;

    a = -1;
    while(a == -1) {
      cout << "Informe seu email: ";
      getline(cin, email);
      a = emailExiste(email);
      if(a == -1) {
        cout << "Email diferente do cadastrado" << endl
        << "Tente novamente" << endl;
      }
    }

    informacoesFuncionario(funcionarios[indexFuncionarioAcessado]);
    cout << "Você é esse funcionário? (s/n)" << endl;
    cin >> retornar;
    cin.ignore();
    if(retornar == 'n') {
      a = -1;
      continue;
    }else {
      break;
    }
  }

  cout << "Informe a nova senha: ";
  getline(cin, nome);
  funcionarios[indexFuncionarioAcessado].setSenha(nome);
  reescreveArquivo();
  cout << "Senha alterada com sucesso" << endl << endl;
}

void FuncionariosCadastrados::promoverGerente() {
    int indexFunc = funcionarioExiste("");

    if(indexFunc == -1) {
        return;
    }
    
    funcionarios[indexFunc].setTipo(1);
    reescreveArquivo();

    cout << "Funcionário promovido com sucesso" << endl;
}

int FuncionariosCadastrados::getCargo() {
  return funcionarios[indexFuncionarioAcessado].getTipo();
}

void FuncionariosCadastrados::listarFuncionarios() {
  for(int i = 0; i < funcionarios.size(); i++) {
    informacoesFuncionario(funcionarios[i]);
  }
}

int FuncionariosCadastrados::getTamanho() {
  return funcionarios.size();
}

void FuncionariosCadastrados::salvarEmArquivo(Funcionario func) {
  fstream fp;

  // abre o arquivo no modo para escrita
  fp.open("Funcionarios.csv", fstream::app); // app para adicionar (append)
  // verifica se o arquivo abriu corretamente
  if (!fp.is_open()) {
    cout << "Erro ao abrir o arquivo para escrita" << endl;
    return;
  }

  // adicionando os valores no arquivo. 
  fp << func.getNome() << ";";
  fp << func.getCpf() << ";";
  fp << func.getEndereco() << ";";
  fp << func.getTelefone() << ";";
  fp << func.getEmail() << ";";
  fp << func.getSenha() << ";";
  fp << func.getTipo() << ";";
  fp << func.getSalario() << ";";
  fp << func.getCliente() << endl;

  fp.close();
}

void FuncionariosCadastrados::reescreveArquivo() {
  fstream fp;

  // abre o arquivo no modo para escrita
  fp.open("Funcionarios.csv", fstream::out); // out para sobrescrever
  // verifica se o arquivo abriu corretamente
  if (!fp.is_open()) {
    cout << "Erro ao abrir o programa para atualização." << endl;
    return;
  }

  // adicionando os valores no arquivo.
  for (int j = 0; j < funcionarios.size(); j++) {
    fp << funcionarios[j].getNome() << ";";
    fp << funcionarios[j].getCpf() << ";";
    fp << funcionarios[j].getEndereco() << ";";
    fp << funcionarios[j].getTelefone() << ";";
    fp << funcionarios[j].getEmail() << ";";
    fp << funcionarios[j].getSenha() << ";";
    fp << funcionarios[j].getTipo() << ";";
    fp << funcionarios[j].getSalario() << ";";
    fp << funcionarios[j].getCliente() << endl;
  }

  fp.close();
}

int FuncionariosCadastrados::emailExiste(string e) {
  for(int i = 0; i < funcionarios.size(); i++) {
    if(funcionarios[i].getEmail().compare(e) == 0) {
      return i;
    }
  }
  return -1;
}

int FuncionariosCadastrados::senhaCorreta(int n) {
  string str;
  char retornar;
  while(true) {
    cout << "Senha: ";
    getline(cin, str);
    if(str.compare(funcionarios[n].getSenha()) == 0) {
      break;
    }else {
      cout << endl << "Senha incorreta" << endl
      << "Deseja mudar o email? " << endl;
      cin >> retornar;
      cin.ignore();
      if(retornar == 's') {
        return -1;
      }
    }
  }
  return 1;
}

int FuncionariosCadastrados::funcionarioExiste(string nm) {
  int i;
  if(nm.compare("") == 0) {      
    string nome;

    cout << "Nome do funcionário que procura: ";
    getline(cin, nome);

    for(i = 0; i < funcionarios.size(); i++) {
      if(nome.compare(funcionarios[i].getNome()) == 0) {
        return i;
      }
    }
  }else {
    for(i = 0; i < funcionarios.size(); i++) {
      if(nm.compare(funcionarios[i].getNome()) == 0) {
        return i;
      }
    }
  }

  cout << "Funcionário não encontrado" << endl;
  return -1;
}

void FuncionariosCadastrados::informacoesFuncionario(Funcionario func) {
  cout << "Nome: " << func.getNome() << endl
  << "CPF: " << func.getCpf() << endl
  << "Endereco: " << func.getEndereco() << endl
  << "Telefone: " << func.getTelefone() << endl
  << "Email: " << func.getEmail() << endl
  << "Salário: R$ " << func.getSalario() << endl
  << "Vendas: " << func.getCliente() << endl
  << "Cargo: ";
  if(func.getTipo() == 1) {
    cout << "Gerente" << endl;
  }else {
    cout << "Funcionario" << endl;
  }
  cout << endl;
}

void FuncionariosCadastrados::alterarNome() {
  cout << "Informe o novo nome: ";
  string nome;
  getline(cin, nome);
  funcionarios[indexFuncionarioAcessado].setNome(nome);
}

void FuncionariosCadastrados::alterarCpf() {
  cout << "Informe o novo CPF: ";
  string cpf;
  getline(cin, cpf);
  funcionarios[indexFuncionarioAcessado].setCpf(cpf);
}

void FuncionariosCadastrados::alterarEndereco() {
  cout << "Informe o novo endereço: ";
  string endereco;
  getline(cin, endereco);
  funcionarios[indexFuncionarioAcessado].setEndereco(endereco);
}

void FuncionariosCadastrados::alterarTelefone() {
  cout << "Informe o novo telefone: ";
  string telefone;
  getline(cin, telefone);
  funcionarios[indexFuncionarioAcessado].setTelefone(telefone);
}

void FuncionariosCadastrados::alterarEmail() {
  cout << "Informe o novo email: ";
  string email;
  getline(cin, email);
  funcionarios[indexFuncionarioAcessado].setEmail(email);
}
