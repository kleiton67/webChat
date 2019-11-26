/*
    KLEYTON LEITE

    IMPLEMENTAR HEADER PARA CLIENTE

*/

#include "cliente.h"

using namespace connection;

Cliente::Cliente(int sock)
{
    Comunication com(sock);
    cmn = com;
}

Cliente::~Cliente()
{

}

bool Cliente::login(std::string user, std::string pass)
{
    Word palavra;
    name = user;
    palavra.setCabecalho('1', user.c_str(), " ", loginM, "FM");
    palavra.setDado(pass.c_str(), pass.size());
    return true;
}

bool Cliente::logout()
{
    Word palavra;
    palavra.setCabecalho('1', name.c_str(), " ", logoutM, "FM");
    palavra.setDado(" ", 1);
    return true;
}

