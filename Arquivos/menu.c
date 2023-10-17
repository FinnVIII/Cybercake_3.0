#include <stdio.h>
#include <locale.h>
#include <windows.h>
#include <string.h>
#include <stdlib.h>
#define _WIN32_WINNT 0x0500
#define _WIN32_WINNT 0x0500
#include "menu.h"

/// ----- Titulo -----

main()
{
    int esc=10;
    char str[50];
    HANDLE colors=GetStdHandle(STD_OUTPUT_HANDLE);

    HWND hWnd = GetConsoleWindow();
    SetWindowPos( hWnd, 0, 340, 100, 100, 0, SWP_NOSIZE | SWP_NOZORDER );
    system("MODE con cols=82 lines=13 ");

/// ------ Cria a tabela de titulo e muda a cor ------
        criarTeto();
        criarLaterais(TAMANHO,"                                   Cybercake");
        criarRodape(TAMANHO);
        criarTeto();

        criarLaterais2(TAMANHO," ");
        criarLaterais2(TAMANHO,"                          [1] Menu de Produtos");
        criarLaterais2(TAMANHO,"                          [2] Tabela de clientes");
        criarLaterais2(TAMANHO,"                          [3] Sobre");
        criarLaterais2(TAMANHO," ");
        criarLaterais2(TAMANHO,"                          [0] Encerrar");
        criarLaterais2(TAMANHO," ");

        criarRodape(TAMANHO);
        scanf("%d",&esc);
        system("cls");
/// --------------------------------------------------
        if(esc==1){ ///Menu de produtos
        system("menu_produtos");
        }
        else if(esc==2){ ///Tabela de clintes
        system("menu_clientes");
        }
        else if(esc==3){ ///Sobre os desenvolvedores
        system("Sobre.exe");
        }
        else if(esc==0){ ///Encerra o programa enquanto estiver no menu inicial
                return(0);
        }
}
