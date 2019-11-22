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

bool Controle::verifyUser(std::string user)
{
    std::vector<std::string>::iterator it = find(pessoas.begin(), pessoas.end(),
    user);
    if(it!=pessoas.end())
        return false;
    else
    {
        return true;
    }
}

bool Controle::updateUser(std::string nome, std::string pass, std::string new_nome)
{
    std::vector<std::string>::iterator it_p = find(pessoas.begin(), pessoas.end(),
    nome);
    std::map< std::string, int >::iterator it = pessoasOn.find(nome);
    if(it != pessoasOn.end())
        return false;
    userAdd(it->second, new_nome, pass);
    pessoas.erase(it_p);
    pessoasOn.erase(it);
}

bool Controle::newGroup(std::string grp, std::string adm, std::string pass){
    std::map< std::string, std::vector<int> >::iterator it = 
        grupos.find(grp);
    //pessoa com esse nome ja foi encontrada
    std::map< std::string, std::string >::iterator it_p = password.find(adm);
    if(it != grupos.end() && it_p->second == pass)
        return false;

    std::vector<int> listaP;
    listaP.push_back(userOnline(adm));
    grupos.insert(std::pair<std::string, std::vector<int> >( grp, listaP));
    
    return true;
}

bool Controle::addPGroup(std::string grp, std::string adm, std::string pass,
    std::string membro)
{
    std::map< std::string, std::vector<int> >::iterator it = 
        grupos.find(grp);
    std::map< std::string, std::string >::iterator it_p = password.find(adm);
    if(it != grupos.end() && it_p->second == pass)
        return false;
    it->second.push_back(userOnline(membro));
    return true;
}

bool Controle::delGroup(std::string grupo, std::string adm, std::string pass)
{
    std::map< std::string, std::vector<int> >::iterator it = 
        grupos.find(grupo);
    //pessoa com esse nome ja foi encontrada
     std::map< std::string, std::string >::iterator it_p = password.find(adm);
    if(it != grupos.end() && it_p->second == pass)
        return false;

    grupos.erase(it);
    
    return true;
}
