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
        char codigo[101],nome[101],marca[101],descricao[101],valor[101];
    } Prod;
    int edit,o=0,i,linha;
    char codigo[100],nome[100],marca[100],descricao[100],valor[100];
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

        FILE *file2;
        file2 = fopen("data_prod.txt", "w");

        printf("Qual linha deseja substituir?\n");
        scanf("%d",&edit);
        i=0;
        printf("linha %d\n",edit);
        for (i = 0; i < linha; i++){
            for (int p = 0; p < strlen(prodinfo[i].nome); ++p) {
                if (prodinfo[i].nome[p] == ' ') {
                    prodinfo[i].nome[p + 0] = '_';
                }
            }
        }
        i=0;

        while (o<edit-1){
            fprintf(file2,"%s %s %s %s %s",prodinfo[i].codigo,prodinfo[i].nome,prodinfo[i].marca,prodinfo[i].descricao,prodinfo[i].valor);
            if (o!= edit-2){
                fprintf(file2,"\n");
            }
            i++;
            o++;
        }
        printf("Insira as novas informações:\n");
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

        fprintf(file2,"\n%s ",codigo);

        for (int q = 0; q < strlen(nome); ++q) {
            if (nome[q] == ' ') {
                nome[q] = '_';
            }
            fprintf(file2,"%c",nome[q]);
        }
        fprintf(file2," %s ",marca);
        fprintf(file2,"%s",descricao);
        fprintf(file2," %s",valor);
        for (i = edit; i <= linha-2; i++){
        fprintf(file2,"\n%s %s %s %s %s",prodinfo[i].codigo,prodinfo[i].nome,prodinfo[i].marca,prodinfo[i].descricao,prodinfo[i].valor);
        }
        fclose(file2);
        system("menu_produtos");
        return(0);
}
