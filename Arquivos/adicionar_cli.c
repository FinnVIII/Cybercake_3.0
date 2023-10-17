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
    file=fopen("data_cli.txt","a+");
    char codigo[101],nome[101],cpf[101],telefone[101],nascimento[101];
                fflush(stdin);
                printf("Código do cliente (Max de 6 caracteres): ");
                gets(codigo);fflush(stdin);
                printf("Nome do cliente (Max de 29 caracteres): ");
                gets(nome);fflush(stdin);
                printf("CPF/CNPJ do cliente (Max de 18 caracteres): ");
                gets(cpf);fflush(stdin);
                printf("Telefone do cliente (Max de 14 caracteres): ");
                gets(telefone);fflush(stdin);
                printf("Data de nascimento do cliente (Max de 18 caracteres): ");
                gets(nascimento);fflush(stdin);

                fprintf(file,"\n%s ",codigo);

                for (int q = 0; q < strlen(nome); ++q) {
                    if (nome[q] == ' ') {
                        nome[q] = '_';
                    }
                    fprintf(file,"%c",nome[q]);
                }

                fprintf(file," %s ",cpf);
                fprintf(file,"%s",telefone);
                fprintf(file," %s",nascimento);
                fclose(file);

    system("menu_clientes");
    return(0);
}
