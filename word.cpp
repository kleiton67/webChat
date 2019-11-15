/*
    KLEYTON LEITE

    IMPLEMENTAÇÃO DO PROTOCOLO DE COMUNICAÇÃO

*/

#include "word.h"

using namespace connection;

char * Word::setTamanho()
{
    char *aux = new char[5];
    sprintf(aux, "%.4d", tamanho);
    return aux;
}

int getTam(const char * tam)
{
    return((int)tam[0]-48)*1000+((int)tam[1]-48)*100+((int)tam[2]-48)*10+
            ((int)tam[3]-48);
}

void Word::setRmt(const char * rmt)
{
    remetente = new char[30];
    memset(remetente, caractereDep, 30);
    for(int i = 0; i < 30&&rmt[i]!='\0'; i++)
    {
        remetente[i] = rmt[i];
    }
}

void Word::setDest(const char * dest)
{
    destinatario = new char[30];
    memset(destinatario, caractereDep, 30);
    for(int i = 0; i < 30&&dest[i]!='\0'; i++)
    {
        destinatario[i] = dest[i];
    }
}

void Word::setCmd(const char * cmd)
{
    comando = new char[7];
    memset(comando, caractereDep, 7);
    for(int i = 0; i < 7&&cmd[i]!='\0'; i++)
    {
        comando[i] = cmd[i];
    }
}

void Word::setCtrl(const char * ctrl)
{
    controle = new char[2];
    memset(destinatario, caractereDep, 2);
    for(int i = 0; i < 2&&ctrl[i]!='\0'; i++)
    {
        destinatario[i] = ctrl[i];
    }
}

Word::Word()
{

}

Word::~Word()
{
    delete remetente;
    delete destinatario;
    delete comando;
    delete controle;
    delete dado;
}


bool Word::nextMessage()
{
    if(controle[0]=='N' && controle[1] == 'M'){
        //std::cout << "NM: Ha mais mensagens!!!\n";
        return true;
    }
    else
    {
        //std::cout << "NM: Nao Ha mais mensagens!!!\n";
        return false;
    }
    
}

int Word::getTamanho()
{
    return tamanho;
}

char * Word::getCommand()
{
    return comando;
}

bool Word::setDado(const char* dado, int tam)
{

    this->dado = new char[TAM_DATA];
    memset(this->dado, caractereDep, 30);
    for(int i = 0; i < TAM_DATA&&dado[i]!='\0'; i++)
    {
        this->dado[i] = dado[i];
    }
    tamanho = tam;

    return true;
}

const char * Word::getDado()
{

    return dado;
}

bool Word::setCabecalho(char version, const char * rmt, const char * dest,
                const char * cmd, const char * ctrl)
{
    if((rmt!=NULL)&&(dest!=NULL)&&(cmd!=NULL)&&(ctrl!=NULL))
    {    
        this->versao = version;
        setRmt(rmt);
        setDest(dest);
        setCmd(cmd);
        setCtrl(ctrl);
    }
    else
    {
        return false;
    }

    return true;  
}

char * Word::getDestinatario()
{
    return destinatario;
}
/*
    Parametros
    word:palavra a ser gerada
    v: versao da aplicacao
    rmt: remetente
    dest: destinatario
    cmd:comando
    control: indicica fim da mensagem
    msg: mensagem a ser colocada no campo data
    byytes: tamanho da mensagem
*/
char * Word::getWord()
{
    char * word = new char[TAM_DATA+TAM_CAB];
    //Tamanho apenas do dado
    memset(word, caractereDep, TAM_CAB+TAM_DATA);
    char * tam;
    tam = setTamanho();
    //Versao da aplicacao
    word[0] = versao;
    //Remetente
    for(int i = 1; i<=30; i++)
    {
       word[i] = remetente[i-1];
    }
    //Destinatario
    for(int i = 31; i<=60; i++)
    {
       word[i] = destinatario[i-31];
    }
    //Comando
    for(int i = 61; i<=67; i++)
    {
       word[i] = comando[i-61];
    }
    //control
    word[68] = controle[0];
    word[69] = controle[1];
    //Tamanho
    word[70] = tam[0];
    word[71] = tam[1];
    word[72] = tam[2];
    word[73] = tam[3];
    //Mensagem
    for(int i = TAM_CAB; i<TAM_DATA+TAM_CAB; i++)
    {
       word[i] = dado[i-TAM_CAB];
    }
}

void Word::setWord(char * palavra)
{
    //Tamanho apenas do dado
    char * rmt = new char[30];
    char * dest = new char[30];
    char * cmd = new char[7];
    char * ctrl = new char[2];
    char * tam = new char[4];
    //Versao da aplicacao
    versao = palavra[0];
    //Remetente
    for(int i = 1; i<=30; i++)
    {
       rmt[i-1] = palavra[i];
    }
    //Destinatario
    for(int i = 31; i<=60; i++)
    {
       dest[i-31] = palavra[i];
    }
    //Comando
    for(int i = 61; i<=67; i++)
    {
       cmd[i-61] = palavra[i];
    }
    //control
    ctrl[0] = palavra[68];
    ctrl[1] = palavra[69];

    //Tamanho: obter tamanho por char
    tam[0] = palavra[70];
    tam[1] = palavra[71];
    tam[2] = palavra[72];
    tam[3] = palavra[73];
    //Mensagem
    for(int i = TAM_CAB; i<TAM_DATA+TAM_CAB; i++)
    {
        dado[i-TAM_CAB] = palavra[i];
    }
    remetente = rmt;
    destinatario = dest;
    comando = cmd;
    controle = ctrl;
    tamanho = getTam(tam);
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