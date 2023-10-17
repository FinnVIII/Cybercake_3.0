#include <stdio.h>
#include <windows.h>
#include <stdlib.h>
#define _WIN32_WINNT 0x0500
#define _WIN32_WINNT 0x0500
#include "menu.h"

main(){
    int esc;
    system("cls");
    HWND hWnd = GetConsoleWindow();
    SetWindowPos( hWnd, 0, 340, 100, 100, 0, SWP_NOSIZE | SWP_NOZORDER );
    system("MODE con cols=82 lines=15 ");

    criarTeto();
    criarLaterais(TAMANHO,"                               Sobre a Cybercake");
    criarRodape(TAMANHO);

    criarTeto();
    criarLaterais2(TAMANHO," ");
    criarLaterais2(TAMANHO,"        A Cybercake se trata de um sistema desenvolvido por estudantes");
    criarLaterais2(TAMANHO,"       do SENAI para cadastro de clientes e produtos feito especialmente");
    criarLaterais2(TAMANHO,"   para confeitarias, mas que pode ser adaptada para outros tipos de empresas.");
    criarLaterais2(TAMANHO," ");
    criarLaterais2(TAMANHO,"    Agradecemos ao nosso Professor Cesar Stati pela oportunidade e incentivo");
    criarLaterais2(TAMANHO,"   no desenvolvimento desse projeto e pelo conhecimento que nos foi passado.");
    criarLaterais2(TAMANHO," ");
    criarLaterais2(TAMANHO," [0] Voltar");
    criarRodape(TAMANHO);
    scanf("%d",&esc);
    if(esc==0){
        system("menu.exe");
        return(0);
    }
}
