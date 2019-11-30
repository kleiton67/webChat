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

std::vector<std::string> split(const std::string& s, char delimiter)
{
   std::vector<std::string> tokens;
   std::string token;
   std::istringstream tokenStream(s);
   while (std::getline(tokenStream, token, delimiter))
   {
      tokens.push_back(token);
   }
   return tokens;
}

bool CtrlCliente::addMsgPeople(std::string nome, std::string rmt, 
		std::string msg)
{
	pthread_mutex_lock(& restrict_access);
	Mensagem msgConv;	
	std::map<std::string, std::vector<Mensagem> >::iterator 
			itp = peoples_msg.find(nome);
	
	//Senao encontrou a pessoa, cadastra-la
	if(itp == peoples_msg.end())
	{
		msgConv.id = 0; 
		msgConv.msg = msg;
		msgConv.user = rmt;
		std::vector<Mensagem> conjMsg;
		conjMsg.push_back(msgConv);
		peoples_msg.insert(std::pair<std::string, std::vector<Mensagem> >
				(nome, conjMsg));
		
		pthread_mutex_unlock(&restrict_access);
		return true;
	}
	//se ela ja existe adicionar a pessoa
	else if(itp!=peoples_msg.end())
	{
		msgConv.id = peoples_msg.end()->second.end()->id+1; 
		msgConv.msg = msg;
		msgConv.user = rmt;
		itp = peoples_msg.end();
		itp->second.push_back(msgConv);
		pthread_mutex_unlock(&restrict_access);
		return true;
	}
	pthread_mutex_unlock(&restrict_access);
}

bool CtrlCliente::addMsgGrupo(std::string grp, std::string rmt, 
			std::string msg)
{
	pthread_mutex_lock(& restrict_access);
	Mensagem msgConv;	
	std::map<std::string, std::vector<Mensagem> >::iterator 
			itg = grupo_msg.find(grp);
	//Senao encontrou o grupo, cadastra-lo
	if(itg == peoples_msg.end())
	{
		msgConv.id = 0; 
		msgConv.msg = msg;
		msgConv.user = rmt;
		std::vector<Mensagem> conjMsg;
		conjMsg.push_back(msgConv);
		grupo_msg.insert(std::pair<std::string, std::vector<Mensagem> >
				(grp, conjMsg));
		pthread_mutex_unlock(&restrict_access);
		return true;
	}
	//se ele ja existe adicionar a mensgem da pessoa
	else if(itg!=peoples_msg.end())
	{
		msgConv.id = grupo_msg.end()->second.end()->id+1; 
		msgConv.msg = msg;
		msgConv.user = rmt;
		itg = grupo_msg.end();
		itg->second.push_back(msgConv);
		pthread_mutex_unlock(&restrict_access);
		return true;
	}
	pthread_mutex_unlock(&restrict_access);
}

bool CtrlCliente::rmPeople(std::string nome)
{
	pthread_mutex_lock(& restrict_access);
	std::map<std::string, std::vector<Mensagem> >::iterator 
			itp = peoples_msg.find(nome);
	
	//Senao encontrou a pessoa, cadastra-la
	if(itp == peoples_msg.end())
	{
		pthread_mutex_unlock(&restrict_access);
		return false;
	}
	else
	{
		pthread_mutex_unlock(&restrict_access);
		peoples_msg.erase(itp);
		return true;
	}
}

bool CtrlCliente::rmGrupo(std::string grupo)
{
	pthread_mutex_lock(& restrict_access);
	std::map<std::string, std::vector<Mensagem> >::iterator 
			itp = grupo_msg.find(grupo);
	
	//Senao encontrou a pessoa, cadastra-la
	if(itp == grupo_msg.end())
	{
		pthread_mutex_unlock(&restrict_access);
		return false;
	}
	else
	{
		grupo_msg.erase(itp);
		pthread_mutex_unlock(&restrict_access);
		return true;
	}
}

void CtrlCliente::updatePeopleOn(std::string listPeoples)
{
	pthread_mutex_lock(& restrict_access);
	peopleOn.erase(peopleOn.begin(), peopleOn.end());

	peopleOn = split(listPeoples, DELIMITER);
	pthread_mutex_unlock(&restrict_access);
}

void CtrlCliente::updateGrupo(std::string listGroup)
{
	pthread_mutex_lock(& restrict_access);
	groupOn.erase(groupOn.begin(), groupOn.end());

	groupOn = split(listGroup, DELIMITER);
	pthread_mutex_unlock(&restrict_access);
}

bool CtrlCliente::userIsOn(std::string user)
{
	std::vector<std::string>:: iterator it = find(peopleOn.begin(), 
		peopleOn.end(), user);
	if(it != peopleOn.end())
		return false;
	else
		{
			/* code */
			return true;
		}
}

bool CtrlCliente::groupIsOn(std::string grp)
{
	std::vector<std::string>:: iterator it = find(groupOn.begin(), 
		groupOn.end(), grp);
	if(it != groupOn.end())
		return false;
	else
		{
			/* code */
			return true;
		}
}

std::vector<std::string> CtrlCliente::getUsersOn()
{
	return peopleOn;
}

std::vector<std::string> CtrlCliente::getGroup()
{
	return groupOn;
}

std::vector<Mensagem> CtrlCliente::getMessages(std::string user)
{
	std::map <std::string, std::vector<Mensagem> >::iterator it;
	it = peoples_msg.find(user);
	if(it != peoples_msg.end())
		return it->second;
	else
	{
		it = grupo_msg.find(user);
		if(it != grupo_msg.end())
		return it->second;
	}
	return std::vector<Mensagem> ();
}