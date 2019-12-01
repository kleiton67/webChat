/* #include <gtkmm/main.h>
#include "pWindows.h"
*/

#include "cliente.h"
#include <iostream>

using namespace connection;

bool IsUnexpectedCharacters(char c)
{
    switch(c)
    {
    case '(':
    case ')':
    case '-':
    case '\0':
    case caractereDep: 
        return true;
    default:
        return false;
    }
}

typedef struct param
{
	Cliente * cliente;
}param;

std::string cmdRec(Word palavra)
{
	
		std::string aux;
        aux = palavra.getCommand();
        std::transform(aux.begin(), aux.end(), aux.begin(), ::toupper);
		aux.erase(std::remove_if(aux.begin(), aux.end(),
						 &IsUnexpectedCharacters), aux.end());
		return aux;
}

void * trataMsg(void *parametros)
{
	param * aux;
	aux = (param *) parametros;
	Cliente *cliente = aux->cliente;
}

int main (int argc, char *argv[])
{
/*Gtk::Main kit(argc, argv);

HelloWorld helloworld;
//Shows the window and returns when it is closed.
Gtk::Main::run(helloworld);*/

	Cliente* cliente =  new Cliente("127.0.0.1", 30100);

	std::string cmd;
	Word pal('1');
	std::string name;
	std::cout << "Cadastre-se: ";
	std::cout << "Entre com seu nome: ";
	std::cin >> name;
	std::cout << "Entre com sua senha: ";
	std::string pass;
	std::cin >> pass;
	cliente->inserirUser(name, pass);
	pal = cliente->ouveConexao();
	cmd = cmdRec(pal);
	if(cmd == okM)
		std::cout << "Usuário cadastrado!!!" << "\n";
	else
	{
		std::cout << "Erro incomun!!!" << "\n";
		exit(EXIT_FAILURE);
	}
	
	while(true)
	{
		std::cout << "Entre com seu nome: ";
		std::cin >> name;
		std::cout << "Entre com sua senha: ";
		std::string pass;
		std::cin >> pass;
		cliente->login(name, pass);
		std::cout << "Aguardando servidor!!!";
		pal = cliente->ouveConexao();
		cmd = cmdRec(pal);
		if(cmd == okM)
		{
			std::cout << "Login realizado com sucesso!!!\n" ;
			break;
		}
	}

	param *parametros = new param;
	
	parametros->cliente = cliente;

	pthread_t thread;

	//pthread_create(&thread, NULL, trataMsg, parametros);

	while(true)
	{
		std::string userSend;
		std::cout << "Com quem deseja se conectar?";
		std::cin >> userSend;
		std::string msg;
		std::cout << "Mensagem a ser enviada: ";
		std::cin >> msg;
		std::cout << "Aguardando servidor!!!";
		cliente->userSend(userSend, msg);
		
		std::cout << "Deseja ver as mensagens de quem?";
		std::cin >> name;
		std::vector< Mensagem > mensagem; 
		mensagem = cliente->getMensagem(name);
	}

	return 0;
}