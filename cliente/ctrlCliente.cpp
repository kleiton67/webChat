/*
    KLEYTON LEITE

    IMPLEMENTAÇÃO DO HEADER PARA CONTROLE DE CLIENTE

    Implementação
*/
#include "ctrlCliente.h"

using namespace connection;

void CtrlCliente::addPeople(std::vector<std::string> peoples)
{
	//Verificar se na estrutura tem elementos que nao estão na nova
	std::map <std::string, std::vector<std::string> >::iterator itpm;
	itpm = peoples_msg.begin();

	std::vector<std::string>::iterator itp;

	std::vector<std::map <std::string, std::vector
			<std::string> >::iterator> rm_pm;
	
	for(;itpm!=peoples_msg.end();itpm++)
	{
		itp = find(peoples.begin(), peoples.end(), itpm->first);
		if(itp==peoples.end())
			rm_pm.push_back(itpm);
	}

	//Excluir elementos que nao se encontrar no vetor
	std::vector<std::map <std::string, std::vector
			<std::string> >::iterator> :: iterator itr;
	itr = rm_pm.begin();
	for(;itr!=rm_pm.end(); itr++)
	{
		peoples_msg.erase(*itr);
	}

	itp = peoples.begin();
	itpm = peoples_msg.begin();
	std::vector <std::string> texto;

	for(;itp!=peoples.end(); itp++)
	{
		itpm = peoples_msg.find(*itp);
		if(itpm==peoples_msg.end())
		{
			peoples_msg.insert(std::pair<std::string, std::vector<std::string> >
						(*itp, texto));
		}
	}

}

bool CtrlCliente::delPeople(std::string user)
{
	std::map <std::string, std::vector<std::string> >::iterator itp;
	itp = peoples_msg.find(user);
	if(itp==peoples_msg.end())
		return false;
	peoples_msg.erase(itp);
	return true;
}



std::vector<std::string> CtrlCliente::getListPeoples()
{
	std::vector<std::string> pearson;

}