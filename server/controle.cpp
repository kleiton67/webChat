/*
    KLEYTON LEITE

	IMPLEMENTAÇÃO PARA O HEADER	
    HEADER PARA CONTROLE

*/

#include "controle.h"

using namespace connection;

bool Controle::userAdd(int sock, std::string user, std::string pass)
{
    std::map< std::string, int >::iterator it = pessoasOn.find(user);
    //pessoa com esse nome ja foi encontrada
    if(it != pessoasOn.end())
        return false;
    pessoasOn.insert(std::pair<std::string, int>( user, sock));

    password.insert(std::pair<std::string, std::string>(user, pass));

    return true;
}

int Controle::userOnline(std::string user)
{
    std::map< std::string, int >::iterator it = pessoasOn.find(user);
    //pessoa com esse nome ja foi encontrada
    if(it != pessoasOn.end())
        return -1;
    else
    {
        return it->second;
    }
    
}