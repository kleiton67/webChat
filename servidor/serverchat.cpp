

#include "serverchat.h"


bool IsUnexpectedCharacters(char c)
{
    switch(c)
    {
    case '(':
    case ')':
    case '-':
    case '\0':
    case caractereDep: 
        return true;
    default:
        return false;
    }
}
using namespace connection;

std::string arrumaString(std::string str)
{
        str.erase(std::remove_if(str.begin(), str.end(),
             &IsUnexpectedCharacters), str.end());
        return str;
}

ServerChat::ServerChat(Controle *control){
    this->control = control;
    logfile = std::fstream("log.txt", std::ofstream::app);
}

ServerChat::ServerChat(Controle *control, int socket){
    this->control = control;
    sock = socket;
}

ServerChat::~ServerChat()
{
    cmn.~Comunication();

    delete control;
}

bool ServerChat::setSocket(int socket){
    this->sock = socket;
}

bool ServerChat::login(Word word){
    pthread_mutex_lock(&accessControl);
    if(control->userLogin(arrumaString(word.getDestinatario()), 
        arrumaString(arrumaString(word.getDado())), sock))
        {
            pthread_mutex_unlock(&accessControl);
            return true;
        }
    else
    {
        pthread_mutex_unlock(&accessControl);
        return false;
    }
}

bool ServerChat::logout(Word word){
    if(ctr.userOnline(arrumaString(word.getRemetente())) != -1){
        pthread_mutex_lock(&accessControl);
        if(control->userLogof(arrumaString(word.getRemetente())))
        {
            pthread_mutex_unlock(&accessControl);
            return true;
        }
    }
    return false;
}

bool ServerChat::erro(Word word){
    log("Erro : " + arrumaString(word.getCommand()) + 
        "com mensagem: " + arrumaString(word.getDado()));
}

bool ServerChat::inserirUser(Word word){
    if(ctr.userOnline(arrumaString(word.getRemetente())) ==-1){
        pthread_mutex_lock(&accessControl);
        ctr.userAdd(arrumaString(word.getRemetente()),arrumaString(word.getDado()));
        pthread_mutex_unlock(&accessControl);
    }
}

bool ServerChat::delUser(Word word){
    if(ctr.verifyUser(arrumaString(word.getRemetente()))){
        pthread_mutex_lock(&accessControl);
        ctr.delUser(arrumaString(word.getRemetente()),arrumaString(word.getDado()));
        pthread_mutex_unlock(&accessControl);
    }
}
bool ServerChat::inserirGrupo(Word word){
    pthread_mutex_lock(&accessControl);
    ctr.newGroup(arrumaString(word.getRemetente()),arrumaString(word.getDestinatario()),arrumaString(word.getDado()));
    pthread_mutex_unlock(&accessControl);
}
bool ServerChat::delGrupo(Word word){
    pthread_mutex_lock(&accessControl);
    ctr.delGroup(arrumaString(word.getRemetente()),arrumaString(word.getDestinatario()),arrumaString(word.getDado()));
    pthread_mutex_unlock(&accessControl);
}
bool ServerChat::userSend(Word word){
    std::string str;
    str.append(arrumaString(word.getRemetente()));

    std::transform(str.begin(), str.end(), str.begin(), ::toupper);
    str.erase(std::remove_if(str.begin(), str.end(),
            &IsUnexpectedCharacters), str.end());
            
    cmn.forward(word,ctr.userOnline(arrumaString(word.getRemetente())));
    
}
bool ServerChat::grupoSend(Word word){
    std::vector<int> listaUsers;    

    listaUsers = ctr.usersGroup(arrumaString(word.getDestinatario()));
    std::vector<int>::iterator itr;
    for(itr = listaUsers.begin();itr != listaUsers.end();itr++){
        cmn.forward(word,*itr);
    }  
    
}

bool ServerChat::search(Word word){
    std::vector< std::string > pessoas = ctr.listUserOn();
    if(pessoas.size()!=0)
    {
        //Inserir ponto e virgula
        std::vector<std::string>::iterator it = pessoas.begin();
        std::string sPeoples;
        for(; it!=pessoas.end(); it++ )
        {
            it->append(";");
            sPeoples += *it;
        }
        cmn.sentCompleteData(word.getRemetente(), word.getRemetente(), word.getCommand(), 
        sPeoples);
        return true;
    }   
    else
    {
        return false;
    }
    
}

void ServerChat::comando()
{
    Word palavra;
    //Envia respostas para o cliente conectado
    palavra = cmn.receiveWord();
    std::string aux;
    aux = palavra.getCommand();
    std::transform(aux.begin(), aux.end(), aux.begin(), ::toupper);
    aux.erase(std::remove_if(aux.begin(), aux.end(),
                        &IsUnexpectedCharacters), aux.end());
    std::cout << "Cliente :" << palavra.getRemetente() <<
            "solicitou " << aux << "\n";
    if(aux == loginM)
    {
        
        if(login(palavra))
        {
            cmn.sentData(" ", palavra.getRemetente(), okM, false, " ");
        }
        else
        {
            cmn.sentData(" ", palavra.getRemetente(), erroM, false, " ");
        }
        
    }
    if(aux == i_userM)
    {
        if(inserirUser(palavra))
        {
            cmn.sentData(" ", palavra.getRemetente(), okM, false, " ");
        }
        else
        {
            cmn.sentData(" ", palavra.getRemetente(), erroM, false, " ");
        }
    }
    if(aux == d_userM)
    {
        if(delUser(palavra))
        {
            cmn.sentData(" ", palavra.getRemetente(), okM, false, " ");
        }
        else
        {
            cmn.sentData(" ", palavra.getRemetente(), erroM, false, " ");
        }
    }
    if(aux == i_grupoM)
    {
        if(inserirGrupo(palavra))
        {
            cmn.sentData(" ", palavra.getRemetente(), okM, false, " ");
        }
        else
        {
            cmn.sentData(" ", palavra.getRemetente(), erroM, false, " ");
        }
    }
    if(aux == d_grupoM)
    {
        if(delGrupo(palavra))
        {
            cmn.sentData(" ", palavra.getRemetente(), okM, false, " ");
        }
        else
        {
            cmn.sentData(" ", palavra.getRemetente(), erroM, false, " ");
        }
    }
    if(aux == g_sendM)
    {
        grupoSend(palavra);
    }
    if(aux == u_sendM)
    {
        userSend(palavra);
    }
    if(aux == logoutM)
    {
        logout(palavra);
    }
}

void ServerChat::log(std::string msg)
{
    logfile << msg << "\n";
}