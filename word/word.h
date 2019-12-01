/*
    KLEYTON LEITE

    HEADER PARA PROTOCOLO DE COMUNICAÇÃO

    Palavra é o que enviado/recebido pelo socket
    Dado é apenas os dados das mensagens(Campo Data)
*/

#include <string>
#include <cstring>
#include <iostream>

#ifndef WORD_H_
#define  WORD_H_

//tamanho do campo mensagem
#define TAM_DATA 1400
#define TAM_CAB 74
#define caractereDep ' '

//comandos
#define loginM "LOGIN"
#define i_userM "I_USER"
#define d_userM "D_USER"
#define i_grupoM "I_GRUPO"
#define d_grupoM "D_GRUPO"
#define g_sendM "G_SEND"
#define u_sendM "U_SEND"
#define logoutM "LOGOUT"
#define erroM "ERRO"
#define okM "OK"
#define free "FREE"

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
            int getTam(const char *);
            //Coloca remetente conforme padrao
            void setRmt(const char *);
            //Coloca destinario conforme padrao
            void setDest(const char *);
            //Coloca comando conforme padrao
            void setCmd(const char *);
            //Coloca controle conforme padrao
            void setCtrl(const char *);
            //Coloca o tamanho na palavra
            void setTamanho(const char *);
            //Colocar o tamanho na palavra 
            void setTamanho(int);
              

        public:
            Word();
            Word(char );
            ~Word();
            //Verifica se ha mensagem 
            bool nextMessage();
            //Obtem tamanho da mensagem
            int getTamanho();
            //Obtem comando da palavra
            char * getCommand();
            //Guarda mensagem a ser enviada
            bool setDado(const char * , int);
            //Obtem somente mensagem
            const char *  getDado();
            //Guarda informacoes do cabecalho
            bool setCabecalho(char version,const char * rmt,const char * dest,
                const char * cmd, const char * ctrl);
            //Obtem nome do destinatario
            char * getDestinatario();
            //Obtem o remetente
            char * getRemetente();
             //Faz palavra com char
            char * getWord();
            //Tem a palavra pronta, converte para o objeto
            void setWord(char *);
            //Imprime vetor
            void print(char * vetor, int tam);

            void copy(Word);
        
           Word operator=(const Word& a)
            {
                remetente = new char[30];
                comando = new char[7];
                controle = new char[2];
                dado = new char [TAM_DATA];
                versao = a.versao;
                remetente = a.remetente;
                destinatario = a.destinatario;
                comando = a.comando;
                tamanho = a.tamanho;
                dado = a.dado;
                return *this;
            }
    };

}

#endif
