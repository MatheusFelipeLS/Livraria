a.out: main.o Pessoa.o Funcionario.o FuncionariosCadastrados.o Livro.o Estoque.o Vendas.o Menu.o
	g++ -o a.out main.o Pessoa.o Funcionario.o FuncionariosCadastrados.o Livro.o Estoque.o Vendas.o Menu.o

main.o: main.cpp
	g++ -c main.cpp

Pessoa.o: Pessoa.h Pessoa.cpp
	g++ -c Pessoa.cpp

Funcionario.o: Funcionario.h Funcionario.cpp
	g++ -c Funcionario.cpp

FuncionariosCadastrados.o: FuncionariosCadastrados.h FuncionariosCadastrados.cpp
	g++ -c FuncionariosCadastrados.cpp

Livro.o: Livro.h Livro.cpp
	g++ -c Livro.cpp

Estoque.o: Estoque.h Estoque.cpp
	g++ -c Estoque.cpp

Vendas.o: Vendas.h Vendas.cpp
	g++ -c Vendas.cpp

Menu.o: Menu.h Menu.cpp
	g++ -c Menu.cpp

clean:
	rm *.o