/*
    KLEYTON LEITE

    HEADER PARA COMUNICAÇÃO

    Implementação
*/

#include "comunication.h"

using namespace connection;

bool Comunication::sentData(std::string rmt, std::string dest, 
		std::string cmd, bool more, std::string msg)
{
	Word palavra;

	//Coloca tamanho no certo na string 
	// para remetente e destinatario
	if(rmt.size() <  30)
		rmt.resize(30-rmt.size(), caractereDep);
	if(dest.size() <  30)
		dest.resize(30-dest.size(), caractereDep);

    if(msg.size() <= TAM_DATA){
        if(more)
        {
			//Enviar mensagem
			palavra.setCabecalho('1', rmt.c_str(), dest.c_str(), cmd.c_str,
			"NM");

        }
        else
        {
			palavra.setCabecalho('1', rmt.c_str(), dest.c_str(), cmd.c_str,
			"FM");
        }
    }
    else
    {
        return false;
    }
	palavra.setDado(msg.c_str(), msg.size());
    write(sock, palavra.getWord, TAM_DATA+TAM_CAB);

    return true;
}


Word Comunication::receiveWord()
{
   char data[TAM_DATA+TAM_CAB];
   Word palavra;
   read(sock, data, TAM_DATA+TAM_CAB);
   palavra.setWord(data);
   return palavra;
}

bool Comunication::sentCompleteData(std::string rmt, std::string dest,
	std::string cmd, std::string msg)
{
    if(msg.size() <= TAM_DATA)
    {
        sentData(rmt, dest, cmd,false, msg);
    }
    else
    {
        //Se a mensagem for maior que o campo data
        // dividir ela
        int i = 0;
        for(; ;i++)
        {
			if((i+1)*TAM_DATA > msg.size())
				break;
           	if(!sentData(rmt, dest, cmd,false, msg.substr(i*TAM_DATA, TAM_DATA)))
				std::cout << 
				"sentCompleteData: Falha no envio da mensagem!!!\n";
        }
		if(!sentData(rmt, dest, cmd,false, msg.substr(i*TAM_DATA, 
								msg.size() - i*TAM_DATA)))
				std::cout << 
				"sentCompleteData: Falha no envio da mensagem!!!\n";

    }

    return true;
}

std::string Comunication::receiveAllMsg()
{
	std::string r_msg;
	Word palavra;

	palavra = receiveWord();



	while(palavra.nextMessage())
	{

		palavra = receiveWord();
		r_msg.append(palavra.getDado());
	}
	r_msg.append(palavra.getDado());

	return r_msg;
}


bool Comunication::receiveBinRecordFile(std::string caminho)
{
	std::fstream file(caminho, std::ios::binary|std::ios::out);
	if(file)
	{
		
		Word palavra;
		char * pal_sock = new char [TAM_CAB+TAM_DATA];
		memset(pal_sock, caractereDep, TAM_DATA+TAM_CAB);
		recv(sock, pal_sock, TAM_CAB+TAM_DATA, 0);
		palavra.setWord(pal_sock);
		while(palavra.nextMessage())
		{
			file.write(palavra.getDado, TAM_DATA);
			memset(pal_sock, caractereDep, TAM_DATA+TAM_CAB);
			recv(sock, pal_sock, TAM_CAB+TAM_DATA, 0);
		}
		int t_msg;
		//std::cout << "RcvBin: Tamanho da mensagem: " << t_msg << "\n";
		file.write(palavra.getDado, palavra.getTamanho());
		//std::cout << "RcvBin: Recebido ultimo mensagem " 
		//<< "\n";
		file.close();
		return true;
	}
	else
	{
		std::cout << "Problema ao manipular arquivo!!!\n";
		return false;
	}

}


bool Comunication::sentFileBinArq(std::string caminho, 
	std::string rmt, std::string dest, std::string cmd, bool more)
{
	int sent = 0;
	std::fstream file(caminho, std::ios::binary|std::ios::in);
	if(file){
		char buffer[TAM_DATA];
		char  temp[1];
		char *pal_sock = new char[TAM_DATA+TAM_CAB];
		Word palavra;
		while(file.tellg()!=EOF)
		{
			file.read(temp, sizeof(char));
			buffer[sent] = temp[0]; 
			sent++;
			if(sent ==TAM_DATA)
			{
				palavra.setWord(buffer);
				write(sock, palavra.getWord(), TAM_DATA+TAM_CAB);
				sent = 0;
			}
		}
		//print(palavra, 30);
		write(sock, palavra.getWord(), TAM_DATA+TAM_CAB);
		//send(sock, palavra, TAM_DATA+TAM_CAB, 0);
		//std::cout << "SentFileBin: Enviado com sucesso: " << 
		//caminho << "\n";
		return true;
	}
	else
	{
	std::cout << "SentFileBin: Problema ao abrir o arquivo " << 
		caminho << "\n";
		return false;
	}
	
}


/*
	No servidor as mensagens serão reencaminhadas, logo
	precisa saber o novo cliente  encaminhar a mensagem
	palavra: palavra que será restransmitida
	sock: identificação do socket a ser reencaminhado a mensagem
*/
std::string Comunication::forward(Word palavra, int sock)
{
	write(sock, palavra.getWord(), TAM_DATA+TAM_CAB);
}