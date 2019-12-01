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

int Word::getTam(const char * tam)
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
    memset(controle, caractereDep, 2);
    for(int i = 0; i < 2&&ctrl[i]!='\0'; i++)
    {
        controle[i] = ctrl[i];
    }
}

void Word::setTamanho(const char * tam)
{
    this->tamanho = getTam(tam);
}

void Word::setTamanho(int tam)
{
    this->tamanho = tam;
}

Word::Word()
{

}

Word::Word(char versao)
{
    this->versao = versao;
}

Word::~Word()
{
    /*
    delete remetente;
    delete destinatario;
    delete comando;
    delete controle;
    delete dado;*/
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
    std::cout << "getCommand: " << comando <<"\n";
    print(comando, 7);
    return comando;
}

bool Word::setDado(const char* dado, int tam)
{

    this->dado = new char[TAM_DATA];
    this->tamanho = tam;
    memset(this->dado, caractereDep, TAM_DATA);
    for(int i = 0; i < TAM_DATA&&dado[i]!='\0'; i++)
    {
        this->dado[i] = dado[i];
    }
    //std::cout << "setDado: " << this->dado << "\n";
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

char * Word::getRemetente()
{
    return remetente;
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

   /* std::cout << "getWord: all:" << remetente << " | " 
     << destinatario << " | " << comando << " | " << controle 
     << " | " << tam << " | " << dado << "\n";*/

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
    //std::cout << "getWord: " << word << "\n";
    return word;
}

void Word::setWord(char * palavra)
{
    //Tamanho apenas do dado
    char * rmt = new char[30];
    char * dest = new char[30];
    char * cmd = new char[7];
    char * ctrl = new char[2];
    char * tam = new char[4];
    char * data = new char [TAM_DATA];

    memset(rmt, caractereDep, 30);
    memset(dest, caractereDep, 30);
    memset(cmd, caractereDep, 7);
    memset(ctrl, caractereDep, 2);
    memset(tam, caractereDep, 4);
    memset(data, caractereDep, TAM_DATA);
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
    std::cout << "Setword : Todo o cabecalho pronto\n" << "\n";
    //Mensagem
    for(int i = TAM_CAB; i<TAM_DATA+TAM_CAB; i++)
    {
        data[i-TAM_CAB] = palavra[i];
    }
    remetente = rmt;
    destinatario = dest;
    comando = cmd;
    controle = ctrl;
    tamanho = getTam(tam);
    dado = data;
    /*std::cout << "SetWord: all:" << remetente << " | " 
     << destinatario << " | " << comando << " | " << controle 
     << " | " << tam << " | " << dado << "\n";*/

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

void Word::copy(Word palavra)
{
    remetente = new char[30];
    destinatario = new char[30];
    comando = new char[7];
    controle = new char[2];
    dado = new char [TAM_DATA];

    versao = palavra.versao;
    remetente = palavra.remetente;
    destinatario = palavra.destinatario;
    comando = palavra.comando;
    controle = palavra.controle;
    tamanho = palavra.tamanho;
    dado = palavra.dado;
}