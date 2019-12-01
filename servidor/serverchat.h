
#ifndef SERVERCHAT_H_
#define SERVERCHAT_H_

#include "controle.h"
#include "../comunication/comunication.h"
#include "../word/word.h"
#include <iostream>
#include <fstream>
#include <time.h>

namespace connection{
    
    class ServerChat{
        private:
            Controle *control;
            Comunication cmn;
            Controle ctr;
            int sock;
            std::fstream logfile;
            pthread_mutex_t accessControl;
            
        public:
            
            ServerChat(Controle *Control);
            ServerChat(Controle *Control, int socket);
            ~ServerChat();

            bool setSocket(int Socket);
            bool login(Word word);
            bool logout(Word word);
            bool erro(Word word);
            bool inserirUser(Word word);   
            bool delUser(Word word);   
            bool inserirGrupo(Word word);
            bool delGrupo(Word word);   
            bool userSend(Word word);   
            bool grupoSend(Word word);   
            bool search(Word word);
            /*
                Ouve comunicaçãoo com usuario e trata a solicitações
            */
            bool comando();
            /*
                Guarda o logo no arquivo de log do servidor
            */
            void log(std::string);
            
            friend bool IsUnexpectedCharacters(char c);
            /*
                Funcao para retirada de caracteres ineperados das funções
            */
            friend std::string arrumaString(std::string);
    };
}
#endif