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

namespace connection{
	class Controle{
		private:
			std::vector<string> pessoas;
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
			~Controle();
			/*
				Adiciona usuario ao servidor
				int: socket do usuario
				string: nome do usuario
				string: senha do usuario
			*/	
			/*Verifica se usuário esta online
				string : nome do usuario
			*/
			bool userOnline(std::string);
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
				int : id do cliente dono do grupo
			*/
			bool newGroup(std::string, std::string, int);
			/*
				Adiciona pessoas no grupo
				string: nome do adm
				string: nome do usuario a ser adicionado
			*/
			bool addPGroup(std::string, std::string);
			/*
				Deleta grupo, se o usuario que solicita for adm
				string: nome do grupo
				string: nome do admin 
			*/
			bool delGroup(std::string, std::string);

	};
}

#endif