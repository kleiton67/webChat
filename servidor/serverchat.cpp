

#include "serverchat.h"


bool IsUnexpectedCharacters(char c)
{
    switch(c)
    {
    case '(':
    case ')':
    case '-':
    case '\0':
    case caractereDep: 
        return true;
    default:
        return false;
    }
}
using namespace connection;

  
    ServerChat::ServerChat(Controle *control){
        this->control = control;
    }
    ServerChat::ServerChat(Controle *control, int socket){
        this->control = control;
        
    }

    bool ServerChat::setSocket(int socket){
        
    }
    bool ServerChat::login(Word word){
        

        if(ctr.userOnline(word.getRemetente()) >1){
            ctr.userAdd(sock,word.getRemetente(),word.getDado);
        }
        

    }
    bool ServerChat::logout(Word word){
       
        //if(userOnline(id,senha,login) == true){}

    }