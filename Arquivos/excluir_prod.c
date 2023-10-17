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
        char codigo[101],nome[101],marca[101],descricao[101],valor[101];
        } Prod;
        int edit,o=0,i,linha;
        Prod prodinfo[100];
        FILE *file1;
        file1 = fopen("data_prod.txt", "r+");
        i=0;
        linha=1;
        while (file1){
            fscanf(file1, " %100s %100s %100s %100s %100s",&prodinfo[i].codigo,&prodinfo[i].nome,&prodinfo[i].marca,&prodinfo[i].descricao,&prodinfo[i].valor);
            i++;
            linha++;
            if(feof(file1)) {
                break ;
            }
        }
        fclose(file1);

        FILE *file;
        file = fopen("data_prod.txt", "w+");

        printf("Qual linha deseja excluir?\n");
        scanf("%d",&edit);
        i=0;
        for (i = 0; i < linha; i++){
            for (int p = 0; p < strlen(prodinfo[i].nome); ++p) {
                if (prodinfo[i].nome[p] == ' ') {
                    prodinfo[i].nome[p + 0] = '_';
                }
            }
        }
        i=0;
        while (o<edit-1){
            fprintf(file,"%s %s %s %s %s",prodinfo[i].codigo,prodinfo[i].nome,prodinfo[i].marca,prodinfo[i].descricao,prodinfo[i].valor);
            if (o!= edit-2){
                fprintf(file,"\n");
            }
            i++;
            o++;
        }

        for (i = edit; i <= linha-2; i++){
            fprintf(file,"\n%s %s %s %s %s",prodinfo[i].codigo,prodinfo[i].nome,prodinfo[i].marca,prodinfo[i].descricao,prodinfo[i].valor);
        }
        fclose(file);
        system("menu_produtos");
        return(0);
}
