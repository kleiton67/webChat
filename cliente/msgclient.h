/*
	Estrutura para mensagens do cliente
*/

#ifndef _MSGCLIENT_
#define _MSGCLIENT_

#include <string>

typedef struct _msgClient{
	std::string user;
	std::string msg;
	int id;
	
	bool operator==(_msgClient a)
	{
		return (this->msg == a.msg) && (this->id == a.id)&&
		 (this->user == a.user);
	}
	void operator=(_msgClient a)
	{
		a.id = this->id;
		a.msg = this->msg;
		a.user = this->user;
	}
}Mensagem;

#endif