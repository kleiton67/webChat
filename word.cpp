/*
    KLEYTON LEITE

    IMPLEMENTAÇÃO DO PROTOCOLO DE COMUNICAÇÃO

*/

#include "word.h"

using namespace connection;

Word::Word()
{
    version = "1";
}

Word::~Word()
{}

void  Word::setVersion(std::string version)
{
    this->version =  version;

}

/*
    Parametros:
    word:palavra a ser gerada
    v: veersao da aplicacao
    rmt: remtente
    dest: destinatario
    cmd:comando
    control: indicica fim da mensagem
    msg: mensagem a ser colocada no campo data
    byytes: tamanho da mensagem
*/
void Word::makeWordchar(char* word, char v, const char* rmt, const char*dest,
 const char* cmd, const char* control, const char* msg, int bytes)
{
    //Tamanho apenas do dado
    memset(word, caractereDep, bytes);
    char * tam;
    tam = setTamanho((short)bytes);
    //Versao da aplicacao
    word[0] = v;
    //Remetente
    for(int i = 1; i<=30; i++)
    {
       word[i] = rmt[i-1];
    }
    //Destinatario
    for(int i = 31; i<=60; i++)
    {
       word[i] = dest[i-31];
    }
    //Comando
    for(int i = 61; i<=67; i++)
    {
       word[i] = cmd[i-61];
    }
    //control
    word[68] = control[0];
    word[69] = control[1];
    //Tamanho
    word[70] = tam[0];
    word[71] = tam[1];
    word[72] = tam[2];
    word[73] = tam[3];
    //Mensagem
    for(int i = TAM_CAB; i<bytes+TAM_CAB; i++)
    {
       word[i] = msg[i-TAM_CAB];
    }
}


bool Word::nextMessage(std::string msg)
{
    //std::cout << "nextMessage\n";
    if (msg.compare(10,2,"NM")==0)
    {
        //std::cout << "nextMessage: Há mensagem!!!\n";
        return true;
    }
    if (msg.compare(10,2,"FM") == 0)
    {
        //std::cout << "nextMessage: Não Há mensagem!!!\n";        
        return false;
    }
    else
    {
        return false;
    }
}

bool Word::nextMessage(char * msg)
{
    if(msg[10]=='N' && msg[11] == 'M'){
        //std::cout << "NM: Ha mais mensagens!!!\n";
        return true;
    }
    else
    {
        //std::cout << "NM: Nao Ha mais mensagens!!!\n";
        return false;
    }
    
}

std::string Word::getCommand(std::string msg)
{
    std::string aux("     ");
    if(msg.size() < 5)
    {
        std::cout << "Mensagem vazia!!! - getCommand\n";
    }
    else
    {
        aux = msg.substr(1,5);
    }
    
    return aux;
}

std::string Word::getData(std::string msg)
{
    if(msg.size() > 12){
        int tamanho = 0;
        tamanho = getTamanho(msg);
        return msg.substr(12, tamanho);
    }
    else
        return " ";
}

/*
    data: dados da mensagem recebida
    palavra: recebido pelo socket
*/
void Word::getData(char* data, char * palavra)
{

    int tamanho = getTamanho(palavra);
    for(int i = 0;i<tamanho; i++)
    {
            data[i] = palavra[i+TAM_CAB];
    }
}

int Word::getTamanho(std::string msg)
{
    return msg[70]*1000+msg[71]*100+msg[72]*10+msg[73];
}

int Word::getTamanho(char* msg)
{
    int tamanho;
    tamanho = ((int)msg[70]-48)*1000+((int)msg[71]-48)*100+((int)msg[72]-48)*10+
            ((int)msg[73]-48);
    return tamanho;
}

char * Word::setTamanho(short tam)
{
    char *aux = new char[5];
    sprintf(aux, "%.4d", tam);
    return aux;
}

void Word::print(char *vetor, int tam)
{
    printf("Impressao do vetor: \n");
    for (int i = 0 ; i < tam; i++)
    {
        printf("%c\n", vetor[i]);
    }
    printf("Fim da impressao do vetor\n");
}
