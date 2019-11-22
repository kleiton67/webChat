

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
        

    }

    
    bool ServerChat::logout(Word word){
        if(ctr.userOnline(word.getRemetente) != -1){
            
        }
        //if(userOnline(id,senha,login) == true){}

    }
    bool ServerChat::erro(Word word){

    }

    bool ServerChat::inserirUSer(Word word){
        if(ctr.userOnline(word.getRemetente()) ==-1){
            ctr.userAdd(word.getRemetente(),word.getDado());
        }
    }
    
    bool ServerChat::delUSer(Word word){
        if(ctr.verifyUser(word.getRemetente)){
            ctr.delUser(word.getRemetente(),word.getDado());
        }
    }
    bool ServerChat::inserirGrupo(Word word){
        ctr.newGroup(word.getRemetente(),word.getDestinatario(),word.getDado());
    }
    bool ServerChat::delGrupo(Word word){
        ctr.delGroup(word.getRemetente(),word.getDestinatario(),word.getDado());
    }
    bool ServerChat::userSend(Word word){

        cmn.forward(word,ctr.userOnline(word.getRemetente()));
        
    }
    bool ServerChat::grupoSend(Word word){

        
    }