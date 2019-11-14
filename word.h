/*
    KLEYTON LEITE

    HEADER PARA PROTOCOLO DE COMUNICAÇÃO

    Palavra é o que enviado/recebido pelo socket
    Dado é apenas os dados das mensagens(Campo Data)
*/

#ifndef WORD_H_
#define  WORD_H_
#include <string>
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
        private:
            char versao;
            char * remetente;
            char * destinatario;
            char * comando;
            char * controle;
            int tamanho;
            char * dado;

            //Retorna ponteiro de char para tamanho
            char * setTamanho();
            //Retorna inteiro por string
            int getTam(char *);
            //Coloca remetente conforme padrao
            void setRmt(char *);
            //Coloca destinario conforme padrao
            void setDest(char *);
            //Coloca comando conforme padrao
            void setCmd(char *);
            //Coloca controle conforme padrao
            void setCtrl(char *);

        public:
            Word();
            ~Word();
            //Verifica se ha mensagem 
            bool nextMessage();
            //Obtem tamanho da mensagem
            int getTamanho();
            //Obtem comando da palavra
            char * getCommand();
            //Guarda mensagem a ser enviada
            bool setDado(const char * );
            //Obtem somente mensagem
            const char *  getDado();
            //Guarda informacoes do cabecalho
            bool setCabecalho(char version, char * rmt, char * dest,
                char * cmd, char * ctrl);
            //Obtem nome do destinatario
            char * getDestinatario();
             //Faz palavra com char
            char * getWord();
            //Tem a palavra pronta, converte para o objeto
            void setWord(char *);
            //Imprime vetor
            void print(char * vetor, int tam);
    };
}

#endif
