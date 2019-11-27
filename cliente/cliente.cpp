/*
    KLEYTON LEITE

    IMPLEMENTAR HEADER PARA CLIENTE

*/

#include "cliente.h"

using namespace connection;

Cliente::Cliente(std::string ad)
{
    /*
        Criar o proprio socket
     */
    int CreateSocket = 0,n = 0;
    char dataReceived[1024];
    struct sockaddr_in ipOfServer;
 
    memset(dataReceived, '0' ,sizeof(dataReceived));
 
    if((CreateSocket = socket(AF_INET, SOCK_STREAM, 0))< 0)
    {
        printf("Socket not created \n");
    }
 
    ipOfServer.sin_family = AF_INET;
    ipOfServer.sin_port = htons(30100);
    ipOfServer.sin_addr.s_addr = inet_addr(ad.c_str());
    if(connect(CreateSocket, (struct sockaddr *)&ipOfServer,
                             sizeof(ipOfServer))<0)
    {
        printf("Connection failed due to port and ip problems\n");
    }

}

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
    cmn.sentCompleteData(user, " ", loginM, pass);
    return true;
}

bool Cliente::logout()
{
    cmn.sentCompleteData(name.c_str, " ", logoutM, "  ");
    return true;
}

bool Cliente::erro(std::string msg)
{
    std::cout << "Mensagem de erro do servidor: " << msg << "\n";
}

bool Cliente::inserirUser(std::string user, std::string pass)
{
    cmn.sentCompleteData(user, " ", i_userM, pass);
}

bool Cliente::delUser(std::string nome, std::string pass)
{
    cmn.sentCompleteData(nome, " ", d_userM, pass);
}

bool Cliente::inserirGrupo(std::string nome, std::string adm,
std::string pass)
{
    cmn.sentCompleteData(nome, adm, i_grupoM, pass);
}

bool Cliente::delGrupo(std::string nome, std::string adm,
std::string pass)
{
    cmn.sentCompleteData(nome, adm, d_grupoM, pass);
}

bool Cliente::userSend(std::string dest, std::string msg)
{
    if(controle.userIsOn(dest)){
        cmn.sentCompleteData(name, dest, u_sendM, msg);
        controle.addMsgPeople(dest, name, msg);
    }
    else
        return false;
}

bool Cliente::grupoSend(std::string dest, std::string msg)
{
    if(controle.groupIsOn(dest))
    {
        cmn.sentCompleteData(name, dest, g_sendM, msg);
        controle.addMsgGrupo(dest, name, msg);
        return true;
    }
    else
    {
        return false;
    }
    
}

bool Cliente::updateU(std::string msg)
{
    controle.updatePeopleOn(msg);
}

bool Cliente::updateG(std::string msg)
{
    controle.updateGrupo(msg);
}

Word Cliente::ouveConexao()
{
    Word palavra = cmn.receiveWord();
    return palavra;
}

void Cliente::receiveMsgU(std::string user, std::string msg)
{
    controle.addMsgPeople(user, user, msg);
}

void Cliente::receiveMsgG(std::string grp, std::string user, 
    std::string msg)
{
    controle.addMsgGrupo(grp, user, msg);
}

std::string Cliente::search(std::string user)
{
    std::vector<std::string> listaON = controle.getUsersOn();
    std::vector<std::string>:: iterator it = find(
        listaON.begin(), listaON.end(), user);
    return *it;
}