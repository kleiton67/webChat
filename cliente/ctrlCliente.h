/*
    KLEYTON LEITE

    HEADER PARA CONTROLE DE CLIENTE

    Implementação
*/

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
#include <pthread.h>

#ifndef CTRLCLIENTE_H
#define CTRLCLIENTE_H

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
			pthread_mutex_t restrict_access;
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
			bool rmGrupo(std::string);
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
				Funcao para retornar mensagens de uma conversa
			*/
			std::vector<Mensagem> getMessages(std::string);
			/*
				Função para cortar string e separar em vetores
			*/
			friend std::vector<std::string> split(const std::string& , char );
	};
}
#endif