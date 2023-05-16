#pragma once
#include "Funcionario.h"

class FuncionariosCadastrados {
    public:
        FuncionariosCadastrados();
        ~FuncionariosCadastrados();

        void iniciaFuncionarios(); 

        void adicionarVendas();

        bool acessarConta();
        void cadastrarFuncionario();
        void alterarDadosFuncionario();
        void alterarDadosPessoais();
        void apagarFuncionario();
        void apagarConta();


        void alterarSenha();

        void promoverGerente();

        int getCargo();

        void listarFuncionarios();

        int getTamanho();

    private:
        vector<Funcionario> funcionarios;
        int indexFuncionarioAcessado = -1;

        void salvarEmArquivo(Funcionario);
        void reescreveArquivo();
        
        int emailExiste(string);
        int senhaCorreta(int);

        int funcionarioExiste(string);
        
        void informacoesFuncionario(Funcionario);

        void alterarNome();
        void alterarCpf();
        void alterarEndereco();
        void alterarTelefone();
        void alterarEmail();
};