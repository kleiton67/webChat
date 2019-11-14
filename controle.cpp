/*
    KLEYTON LEITE

	IMPLEMENTAÇÃO PARA O HEADER	
    HEADER PARA CONTROLE

*/

#include "controle.h"

using namespace connection;

std::string Controle::getNameForward(std::string word)
{
	char * dest;
	std::string destino;
	destino.append(getDestinatario(word.c_str()));
	return destino;
}