
#include "../comunication.h"
#include "../server/controle.h"
#include "../word.h"
namespace connection{
    
    class ServerChat{
        private:
            Controle *control;
        public:
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

            ServerChat(Controle *Control);
            ServerChat(Controle *Control, int socket);
                 


    };
}
