

#include "serverchat.h"


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
        
        //if(userOnline(id,senha,login) == false){}



      

    }
    bool ServerChat::logout(Word word){
       
        //if(userOnline(id,senha,login) == true){}

    }