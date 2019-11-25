/*
    KLEYTON LEITE

    HEADER PARA CONTROLE

*/

#ifndef CONTROLE_H_
#define CONTROLE_H_


#include <string>
#include <string>
#include <map>
#include <vector>
#include <algorithm>

namespace connection{
	class Controle{
		private:
			std::vector<std::string> pessoas;
			std::map<std::string, int> pessoasOn;
			std::map<std::string, std::vector<int> > grupos;
			/*
				First contem o usuario
				Second a senha
 			*/
			std::map< std::string, std::string > password;

		protected:
			//Descoberta do nome para encaminhar pacote
		public:
			Controle(){};
			~Controle(){};
			/*
				Adiciona usuario ao servidor
				int: socket do usuario
				string: nome do usuario
				string: senha do usuario
			*/	
			bool userAdd(std::string, std::string);
			/*Verifica se usuário esta online e retorna socket dele
				string : nome do usuario
				retorno > 0 se o usuario esta na lista
			*/
			int userOnline(std::string);
			/*
				Deleta usuario das estruturas
				string: Nome do usuario a ser excluido
				string: senha do usuario
			*/
			bool delUser(std::string, std::string);
			/*
				Login do usuario
				string: nome usuario
				string: senha usuario
				int: id da conexao
			*/
			bool userLogin(std::string, std::string, int);
			/*
				Fazer logof do usuario
				string: nome do usuario
			*/
			bool userLogof(std::string);
			//Verifica se o usuario esta na lista
			bool verifyUser(std::string);
			/*
				Atualiza nome do usuario
				string: nome
				string: senha
				string: novo nome
			*/
			bool updateUser(std::string, std::string, std::string);
			/*
				Cria grupo
				string : nome do grupo
				string : nome do admin
				string : senha do admm
			*/
			bool newGroup(std::string, std::string, std::string);
			/*
				Adiciona pessoas no grupo
				string: nome do grupo
				string: nome do adm
				string: senha adm
				string: nome do usuario a ser adicionado
			*/
			bool addPGroup(std::string, std::string,  std::string, 
				std::string);
			/*
				Deleta grupo, se o usuario que solicita for adm
				string: nome do grupo
				string: nome do admin 
				string: senha admin
			*/
			bool delGroup(std::string, std::string, std::string);
			/*
				Retorna lista de ids dos usuarios conectados
				string: nome do grupo
			*/
			std::vector<int> usersGroup(std::string);
			/*
				Retorna lista de usuarios online
			*/
			std::vector<std::string> listUserOn();
	};
}

#endif