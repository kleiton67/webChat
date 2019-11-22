/*
    KLEYTON LEITE

    HEADER PARA CONTROLE DE CLIENTE

    Implementação
*/

#ifndef CTRLCLIENTE_H
#define CTRLCLIENTE_H

#include <vector>
#include <map>
#include <string>
#include <algorithm>

namespace connection
{
	class CtrlCliente
	{
		private:
			/*
				Chave é o nome do usuáŕio, segundo é a mensagem
			*/
			std::map <std::string, std::vector<std::string> > peoples_msg;
			/*
				Chave é o nome do grupo, segunda parte:
					nome é a a pessoa, segundo é a mensagem
			*/
			std::map <std::string, std::map<std::string, std::string> >
				grupo_msg;
		public: 
			CtrlCliente(){}
			void addPeople(std::vector<std::string>);
			bool delPeople(std::string);
			void addGroups(std::vector<std::string>);
			std::vector<std::string> getListPeoples();
			std::vector< std::string > getListGroup();
	};
}
#endif