#include <stdio.h>
#include <locale.h>
#include <conio.h>
#include <windows.h>
#include <string.h>
#include <stdlib.h>
#define _WIN32_WINNT 0x0500
#define _WIN32_WINNT 0x0500
#include "Biblio_Pro.h"



main(){
        int esc1,esc2,flag_tab=1,flag_add,flag_edi,flag_exc;;
        char str[50];


        HWND hWnd = GetConsoleWindow();

        FILE *file;
        while(flag_tab){
        system("MODE con cols=120 lines=37 ");
        flag_tab=1;flag_add=0;flag_edi=0;flag_exc=0;
        SetWindowPos( hWnd, 0, 220, 100, 100, 0, SWP_NOSIZE | SWP_NOZORDER );

        int i = 0,linha=0;
        file = fopen("data_prod.txt", "a+");

        while (file){
            fscanf(file, " %100s %100s %100s %100s %100s",&prodinfo[i].codigo,&prodinfo[i].nome,&prodinfo[i].marca,&prodinfo[i].descricao,&prodinfo[i].valor);
            i++;
            linha++;
            if(feof(file)) {
                break ;
            }
        }

        PrintLimites1();
        criarLaterais(Tamanho_Titu,"                                              Tabela de Produtos");
        PrintLimites2();

        PrintLimites1();
        criarLaterais_Cli(Tamanho_TCli," Linha "," Codigo ","              Nome             ","    Marca    ","                  Descricao                  ","  Valor  ");
        PrintLimites2();

        PrintLimites1();
        PrintLinhas(linha);
        PrintLimites2();

        PrintLimiOpc1(12,9,12,13);
        PrintOpc();
        PrintLimiOpc2(12,9,12,13);

        printf("\n");
        scanf("%d",&esc1);
        system("cls");

        switch(esc1){
            case 0:
                system("Menu");
                return(0);
                break;
            case 1:
                flag_add=1;
                while(flag_add){

                system("MODE con cols=20 lines=6 ");
                SetWindowPos( hWnd, 0, 600, 300, 100, 0, SWP_NOSIZE | SWP_NOZORDER );

                PrintTeto_Alerta(17);
                PrintAlerta();
                PrintBase_Alerta(17);

                scanf("%d",&esc2);
                if(esc2==1){
                    flag_add=0;
                }
                else if(esc2==2){
                    system("adicionar_prod");
                    return(0);
                }
                else{
                    system("cls");
                    PrintTeto_Alerta(17);
                    PrintERROR();
                    PrintBase_Alerta(17);
                    sleep(2);
                    flag_add=0;
                }

                }/// - flag_add
                break;
            case 2:
                flag_edi=1;
                while(flag_edi){

                system("MODE con cols=20 lines=6 ");
                SetWindowPos( hWnd, 0, 600, 300, 100, 0, SWP_NOSIZE | SWP_NOZORDER );;

                PrintTeto_Alerta(17);
                PrintAlerta();
                PrintBase_Alerta(17);

                scanf("%d",&esc2);
                if(esc2==1){
                    flag_edi=0;
                }
                else if(esc2==2){
                    system("editar_prod");
                    return(0);
                }
                else{
                    system("cls");
                    PrintTeto_Alerta(17);
                    PrintERROR();
                    PrintBase_Alerta(17);
                    sleep(2);
                    flag_edi=0;
                }

                }/// - flag_edi
                break;
            case 3:
                flag_exc=1;
                while(flag_exc){

                system("MODE con cols=20 lines=6 ");
                SetWindowPos( hWnd, 0, 600, 300, 100, 0, SWP_NOSIZE | SWP_NOZORDER );

                PrintTeto_Alerta(17);
                PrintAlerta();
                PrintBase_Alerta(17);

                scanf("%d",&esc2);
                if(esc2==1){
                    flag_exc=0;
                }
                else if(esc2==2){
                    system("excluir_prod");
                    return(0);
                }
                else{
                    system("cls");
                    PrintTeto_Alerta(17);
                    PrintERROR();
                    PrintBase_Alerta(17);
                    sleep(2);
                    flag_exc=0;
                }

                }/// - flag_exc
                break;
        }

    }///- while tabela


        fclose(file);

}
