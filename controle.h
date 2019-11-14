/*
    KLEYTON LEITE

    HEADER PARA CONTROLE

*/

#ifndef CONTROLE_H_
#define CONTROLE_H_


#include <string>
#include "word.h"
#include "comunication.h"

namespace connection{
	class Controle{
		
		protected:
			//Descoberta do nome para encaminhar pacote
			std::string getNameForward(std::string word);
		public:
			Controle(){};
			~Controle();
	};
}

#endif