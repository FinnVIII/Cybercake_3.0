#include <stdio.h>
#include <string.h>
#include <windows.h>
#define _WIN32_WINNT 0x0500
#define _WIN32_WINNT 0x0500

main(){
    system("cls");
    system("MODE con cols=110 lines=37 ");
    HWND hWnd = GetConsoleWindow();
    SetWindowPos( hWnd, 0, 250, 50, 100, 0, SWP_NOSIZE | SWP_NOZORDER );

        typedef struct node {
        char codigo[101],nome[101],cpf[101],telefone[101],nascimento[101];
        } Cli;
        int edit,o=0,i,linha;
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

        FILE *file;
        file = fopen("data_cli.txt", "w+");

        printf("Qual linha deseja excluir?\n");
        scanf("%d",&edit);
        i=0;
        for (i = 0; i < linha; i++){
            for (int p = 0; p < strlen(cliinfo[i].nome); ++p) {
                if (cliinfo[i].nome[p] == ' ') {
                    cliinfo[i].nome[p + 0] = '_';
                }
            }
        }
        i=0;
        while (o<edit-1){
            fprintf(file,"%s %s %s %s %s",cliinfo[i].codigo,cliinfo[i].nome,cliinfo[i].cpf,cliinfo[i].telefone,cliinfo[i].nascimento);
            if (o!= edit-2){
                fprintf(file,"\n");
            }
            i++;
            o++;
        }

        for (i = edit; i <= linha-2; i++){
            fprintf(file,"\n%s %s %s %s %s",cliinfo[i].codigo,cliinfo[i].nome,cliinfo[i].cpf,cliinfo[i].telefone,cliinfo[i].nascimento);
        }
        fclose(file);
        system("menu_clientes");
        return(0);
}
