/*
    KLEYTON LEITE

    HEADER PARA CONTROLE DE CLIENTE

    Implementação
*/

#ifndef CTRLCLIENTE_H
#define CTRLCLIENTE_H

#include <vector>
#include <map>
#include <vector>
#include <string>
#include <algorithm>
#include "msgclient.h"

namespace connection
{
	class CtrlCliente
	{
		/*
			Mensagens sincronizadas por um contador
		*/
		private:
			/*
				Chave é o nome do usuário, segundo é a mensagem
			*/
			std::map <std::string, Mensagem> peoples_msg;
			/*
				Chave é o nome do grupo, segunda parte:
					nome é a a pessoa, segundo é a mensagem
			*/
			std::map <std::string, std::vector<Mensagem> >
				grupo_msg;
		public: 
			CtrlCliente();
			~CtrlCliente();
			/*
				Nome da conversa
				Nome de quem enviou a mensagem
				Conteudo da mensagem
			*/
			bool addMsgPeople(std::string , std::string, std::string);
			bool addMsgGrupo(std::string, std::string, std::string);
			bool rmPople(std::string);
			bool rmgrupo(std::string);
	};
}
#endif