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
    typedef struct node {
        char codigo[101],nome[101],cpf[101],telefone[101],nascimento[101];
    } Cli;
    int edit,o=0,i,linha;
    char codigo[100],nome[100],cpf[100],telefone[100],nascimento[100];
    Cli cliinfo[9];

        FILE *file1;
        file1 = fopen("data_cli.txt", "r+");
        i=0;
        linha=1;
        while (file1){
            fscanf(file1, " %100s %100s %100s %100s %100s",&cliinfo[i].codigo,&cliinfo[i].nome,&cliinfo[i].cpf,&cliinfo[i].telefone,&cliinfo[i].nascimento);
            i++;
            linha++;
            if(feof(file1)) {
                break ;
            }
        }
        fclose(file1);

        FILE *file2;
        file2 = fopen("data_cli.txt", "w");

        printf("Qual linha deseja substituir?\n");
        scanf("%d",&edit);
        i=0;
        printf("linha %d\n",edit);
        for (i = 0; i < linha; i++){
            for (int p = 0; p < strlen(cliinfo[i].nome); ++p) {
                if (cliinfo[i].nome[p] == ' ') {
                    cliinfo[i].nome[p + 0] = '_';
                }
            }
        }
        i=0;

        while (o<edit-1){
            fprintf(file2,"%s %s %s %s %s",cliinfo[i].codigo,cliinfo[i].nome,cliinfo[i].cpf,cliinfo[i].telefone,cliinfo[i].nascimento);
            if (o!= edit-2){
                fprintf(file2,"\n");
            }
            i++;
            o++;
        }
        printf("Insira as novas informações:\n");
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

        fprintf(file2,"\n%s ",codigo);

        for (int q = 0; q < strlen(nome); ++q) {
            if (nome[q] == ' ') {
                nome[q] = '_';
            }
            fprintf(file2,"%c",nome[q]);
        }
        fprintf(file2," %s ",cpf);
        fprintf(file2,"%s",telefone);
        fprintf(file2," %s",nascimento);
        for (i = edit; i <= linha-2; i++){
        fprintf(file2,"\n%s %s %s %s %s",cliinfo[i].codigo,cliinfo[i].nome,cliinfo[i].cpf,cliinfo[i].telefone,cliinfo[i].nascimento);
        }
        fclose(file2);
        system("menu_clientes");
        return(0);
}
