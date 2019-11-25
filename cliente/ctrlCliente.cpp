/*
    KLEYTON LEITE

    IMPLEMENTAÇÃO DO HEADER PARA CONTROLE DE CLIENTE

    Implementação
*/
#include "ctrlCliente.h"

using namespace connection;

CtrlCliente::CtrlCliente()
{

}

CtrlCliente::~CtrlCliente()
{

}

bool CtrlCliente::addMsgPeople(std::string nome, std::string rmt, 
		std::string msg)
{
	Mensagem msgConv;
	std::map<std::string, Mensagem>::iterator itp = peoples_msg.find(nome);
	if(itp == peoples_msg.end())
	{
		msgConv.id = 0; 
		msgConv.msg = msg;
		msgConv.user = rmt;
		peoples_msg.insert(std::make_pair<std::string, Mensagem>(nome, msgConv));
		return true;
	}
	else
	{
		return false;
	}
	

}