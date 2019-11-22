/*
    KLEYTON LEITE

    HEADER PARA CONSTRUÇÃO DA ESTRUTURA DE DADOS
    DE PARAMETROS DAS THREADS

    structArg.h
*/

#ifndef _STRUCTARG_H
#define _STRUCTARG_H

#include <pthread.h>
#include <string>
#include <controle.h>

typedef struct _Params{
    //socket criado para o cliente
    int socketClient;
    bool active = false;
    std::string msg;
    pthread_t id;
    Controle *controle;
}ParamThread;

#endif