
#ifndef SERVERCHAT_H_
#define SERVERCHAT_H_

#include "controle.h"
#include "../comunication/comunication.h"
#include "../word/word.h"
namespace connection{
    
    class ServerChat{
        private:
            Controle *control;
            Comunication cmn;
            Controle ctr;
            int sock;
            
        public:
            
            ServerChat(Controle *Control);
            ServerChat(Controle *Control, int socket);

            bool setSocket(int Socket);
            bool login(Word word);
            bool logout(Word word);
            bool erro(Word word);
            bool inserirUSer(Word word);   
            bool delUSer(Word word);   
            bool inserirGrupo(Word word);   
            bool delGrupo(Word word);   
            bool userSend(Word word);   
            bool grupoSend(Word word);   
            bool search(Word word);   
            void comando();

         
            friend bool IsUnexpectedCharacters(char c);             


    };
}
#endif