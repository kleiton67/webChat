/*
    KLEYTON LEITE

    HEADER PARA COMUNICAÇÃO(TCP)

    Recebimento do envio e recebiimento de mensagens
		e arquivos
*/


#ifndef COMUNICATION_H_
#define COMUNICATION_H_

#include <string>
#include <sys/types.h>
#include <unistd.h>
#include <sys/socket.h>//Socket
#include <sys/types.h>//Tipos para socket
#include <arpa/inet.h> //addrstructure
#include <fstream> //Manipulação de arquivos
#include <cstdlib> //system
#include <fcntl.h> // open
#include "word.h"


namespace connection
{

	class Comunication
	{
		protected:
			//id do socket a se conectar
			int sock = 0;
			//Envia uma mensagem(Data)
		public:
            bool sentData(std::string rmt, std::string dest, 
				std::string cmd, bool more, std::string msg);
			//Recebe uma palavra
            Word receiveWord();
            //Envia mensagem completa
            bool sentCompleteData(std::string rmt,
				std::string dest,std::string cmd, std::string msg);
            //Recebe a mensagem completa(Dados)
            std::string receiveAllMsg();
            //Recebimento de arquivos Binarios
            bool receiveBinRecordFile(std::string caminho);
            //Envio de arquivos binarios
            bool sentFileBinArq(std::string caminho, 
			std::string rmt, std::string dest, 
			std::string cmd, bool more);
			//Faz o encaminho da mensagem (usar char)
			std::string forward(Word, int sock);
			Comunication(){};
			Comunication(int id){sock = id;};
			~Comunication();

	};
}
#endif