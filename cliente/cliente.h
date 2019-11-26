/*
    KLEYTON LEITE

    HEADER PARA CLIENTE

*/

#ifndef CLIENTE_H_
#define CLIENTE_H_

#include <string>
#include "../comunication/comunication.h"
#include "controle.h"
#include "ctrlCliente.h"
#include "../word/word.h"
#include "../servidor/serverchat.cpp"

namespace connection
{
    class Cliente{
        private:
            Comunication cmn;
            std::string name;
            CtrlCliente controle;

            const char * loginM = "LOGIN";
            const char * i_userM = "I_USER";
            const char * d_userM = "D_USER";
            const char * i_grupoM = "I_GRUPO";
            const char * d_grupoM = "D_GRUPO";
            const char * g_sendM = "G_SEND";
            const char * u_sendM = "u_SEND";
            const char * s_grupoM = "S_GRUPO";
            const char * logoutM = "LOGOUT";

        public:
            /*
                sockett a ser conectado
            */
            Cliente(int);
            ~Cliente();

            /*
                Fazer login do usuario
                string: nome usuario
                string: senha usuario
            */
            bool login(std::string, std::string);
            /*
                Fazer logout
                string: usuario a ser desconectado
            */
            bool logout();
            /*
                Trata as mensagens de erros
                Mensagem de erro
            */
            bool erro(std::string);
            /*
                Insere usuario no servidor
                string: nome usuario
                string: senha usuario
            */
            bool inserirUser(std::string, std::string);
            /*
                Deleta usuariodo servidor
                string: nome usuario
                string: senha usuario
            */
            bool delUser(std::string, std::string);
            /*
                Insere grupo no servidor
                string: nome do grupo
                string: nome do admin
                string: senha do admin
            */
            bool inserirGrupo(std::string, std::string, std::string);
            /*
                Deleta grupo do servidor
                string: nome do grupo
                string: nome admin
                string: senha admin
            */
            bool delGrupo(std::string, std::string, std::string);
            /*
                Envia mensagem para outro usuario
                string: nome do destinatário
                string: mensagem
            */
            bool userSend(std::string, std::string);
            /*
                Envia mensagem para um grupo
                string: nome do grupo
                string: mensagem a ser enviada
            */
            bool grupoSend(std::string, std::string);
            /*
                Atualiza lista de usuarios
                string: nome do usuario
            */
            bool updateU(std::string);
            /*
                Atualiza lista de grupos
                string:  nome do grupo
            */
            bool updateG(std::string);
            /*
                Ouve conexao do servidor
            */
            void ouveConexao();
            /*
                Recebe mensagens de usuario
                string: nome usuario
                string: mensagem
             */
            void receiveMsgU(std::string, std::string);

            /*
                Recebe mensagem de grupos
                string: nome do usuario
                string: nome do grupo
                string: mensagem do usuario
             */
            void receiveMsgG(std::string, std::string, std::string);

    };
}

#endif