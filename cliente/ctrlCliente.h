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
#include <fstream>
#include <iostream>
#include <sstream>
#include <algorithm>

#define DELIMITER ';'

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
			std::vector<std::string> peopleOn;
			std::vector<std::string> groupOn;
			std::map <std::string, std::vector<Mensagem> > peoples_msg;
			/*
				Chave é o nome do grupo, segunda parte:
					nome é a a pessoa, segundo é a mensagem
			*/
			std::map <std::string, std::vector<Mensagem> > grupo_msg;

		public: 
			CtrlCliente();
			~CtrlCliente();
			/*
				Nome da conversa
				Nome do remetente
				Conteudo da mensagem
			*/

			bool addMsgPeople(std::string , std::string, std::string);
			/*
				Nome do grupo
				Nome do remetente
				Conteudo da mensagem
			*/
			bool addMsgGrupo(std::string, std::string, std::string);
			/*
				Noma da pessoa a ser removida
			*/
			bool rmPeople(std::string);
			/*	
				Nome do grupo a ser removido
			*/	
			bool rmgrupo(std::string);
			/*
				Mensagem com todos os usuarios online
			*/
			void updatePeopleOn(std::string);
			/*
				Mensagem com todos os grupos online
			*/
			void updateGrupo(std::string);
			/*
				Verifica se usuario esta onine para enviar mensagem
			*/
			bool userIsOn(std::string);
			/*
				Verifica se o grupo esta online para mandar msg
			*/
			bool groupIsOn(std::string);
			/*
				retorna lista de usuarios online
			 */
			std::vector<std::string> getUsersOn();
			/*
				retorna lista de grupos
			 */
			std::vector<std::string> getGroup();
			/*
				Função para cortar string e separar em vetores
			*/
			friend std::vector<std::string> split(const std::string& , char );
	};
}
#endif