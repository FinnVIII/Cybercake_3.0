#include <stdio.h>
#include <string.h>
#include <locale.h>
#include <windows.h>
#define _WIN32_WINNT 0x0500
#define _WIN32_WINNT 0x0500

main(){
    system("cls");
    system("MODE con cols=110 lines=37 ");
    HWND hWnd = GetConsoleWindow();
    SetWindowPos( hWnd, 0, 250, 50, 100, 0, SWP_NOSIZE | SWP_NOZORDER );

    setlocale(LC_ALL,"Portuguese");
    FILE*file;
    file=fopen("data_prod.txt","a+");
    char codigo[101],nome[101],marca[101],descricao[101],valor[101];
                fflush(stdin);
                printf("Código do produto (Max de 6 caracteres): ");
                gets(codigo);fflush(stdin);
                printf("Nome do produto (Max de 29 caracteres): ");
                gets(nome);fflush(stdin);
                printf("Marca do produto (Max de 11 caracteres): ");
                gets(marca);fflush(stdin);
                printf("Descricao do produto (Max de 43 caracteres): ");
                gets(descricao);fflush(stdin);
                printf("Valor do produto (Max de 6 caracteres): ");
                gets(valor);fflush(stdin);

                fprintf(file,"\n%s ",codigo);

                for (int q = 0; q < strlen(nome); ++q) {
                    if (nome[q] == ' ') {
                        nome[q] = '_';
                    }
                    fprintf(file,"%c",nome[q]);
                }


                fprintf(file," %s ",marca);
                for (int q = 0; q < strlen(descricao); ++q) {
                    if (descricao[q] == ' ') {
                        descricao[q] = '_';
                    }
                    fprintf(file,"%c",descricao[q]);
                }

                fprintf(file," %s",valor);
                fclose(file);
                system("menu_produtos");
                return(0);
}
