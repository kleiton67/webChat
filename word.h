/*
    KLEYTON LEITE

    HEADER PARA PROTOCOLO DE COMUNICAÇÃO

    Palavra é o que enviado/recebido pelo socket
    Dado é apenas os dados das mensagens(Campo Data)
*/

#ifndef WORD_H_
#define  WORD_H_
#include <string>
#include <vector>
#include <cstring>
#include <iostream>

//tamanho do campo mensagem
#define TAM_DATA 1400
#define TAM_CAB 74
#define caractereDep ' '

namespace connection
{
    class Word{
        //Estrutura do protocolo
        /* Versao(1B)|Remetente(30B)|Destinatario(30B)|Command(7B)|Control(2B)|
         Tamanho(4B)|Data(1400)*/
        protected:
            std::string version;
            std::string command;
            void setVersion(std::string version);
            //Faz palavra com char
            void makeWordchar(char* word, char v, const char* rmt, const char*dest,
            const char* cmd, const char* control, const char* msg, int bytes);
            //Verifica se há mensagens a serem a entregues
            bool nextMessage(std::string msg);
            //Verifica se ha mensagem
            bool nextMessage(char * msg);
            //Obtem comando da palavra
            std::string getCommand(std::string msg);
            //Obtem somente mensagem
            std::string getData(std::string msg);
            //Obtem somente mensagem 
            void getData(char* data, char * palavra);
            //Obtem tamanho da mensagem
            int getTamanho(std::string msg);
            //Retorna ponteiro de char para tamanho
            char * setTamanho(short tam);
            //Retorna o tamanho da palavra
            int getTamanho(char* msg);
            //Imprime vetor
            void print(char * vetor, int tam);
        public:
            Word();
            ~Word();
    };
}

#endif
