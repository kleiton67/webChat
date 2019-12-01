/*
    KLEYTON LEITE

    CONSTRUCAO DE SERVIDOR COM PTHREADS EM C++

    main.cpp
*/

#include <iostream>
#include <cstring>
#include <fstream>
#include "server.h"
#include <time.h> //manipulação de data
#include "serverchat.h" //cuida dos clientes conectados

#define PORTCMT  30100

using namespace connection;

void *serveCliente(void* param)
{
    ParamThread * parametros = new _Params;
    parametros = (_Params*) param;

    ServerChat connectCliente(parametros->controle, 
        parametros->socketClient);
    //Cuida da conexão com o cliente
    std::cout << "ServeClient: Socket do cliente: " << parametros->socketClient 
    << "\n";
    while(true)
        if(!connectCliente.comando())
            break;
    return (void*)NULL;
}   

int main()
{
    ServerT servidor("127.0.0.1", PORTCMT);

    servidor.initServer(20);

    while(true)
    {
        //Criar ponteiro para objeto do tipo controle
        //passar para as threads por referencia
        servidor.multiClient(serveCliente);
    }
 
    return 0;   
}


