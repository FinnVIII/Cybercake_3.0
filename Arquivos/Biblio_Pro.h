#ifndef BIBLIO_PRO_H_INCLUDED
#define BIBLIO_PRO_H_INCLUDED

#define Tamanho_Titu 110
#define Tamanho_TCli 110
#define Tamanho_Sair 10
#define Tamanho 118

typedef struct node {
    char codigo[101],nome[101],marca[101],descricao[101],valor[101];
} Prod;
char codigo[101],nome[101],marca[101],descricao[101],valor[101];
    Prod prodinfo[9];

void PrintSpaces (int cont){
    for(int i=0;i<cont;i++){
        printf(" ");
    }
}

void PrintLimites1 (){
    printf("%c",201);
    for(int i=0;i<Tamanho;i++){
        printf("%c",205);
    }
    printf("%c\n",187);
}

void PrintLimites2 (){
    printf("%c",200);
    for(int i=0;i<Tamanho;i++){
        printf("%c",205);
    }
    printf("%c\n",188);
}

void PrintLinhas (int linha){
    int i=0, linhas=0;
    int StrCod[50],CalCod[50], StrNom[50],CalNom[50], StrMar[50],CalMar[50], StrDes[50],CalDes[50], StrVal[50],CalVal[50];


    for(int i=0;i<linha;i++){
    linhas++;
            for (int p = 0; p < strlen(prodinfo[i].nome); ++p) {
                if (prodinfo[i].nome[p] == '_') {
                    prodinfo[i].nome[p + 0] = ' ';
                }
            }
            for (int p = 0; p < strlen(prodinfo[i].descricao); ++p) {
                if (prodinfo[i].descricao[p] == '_') {
                    prodinfo[i].descricao[p + 0] = ' ';
                }
            }

            /// ----------------------- Lin
            printf("%c",186);
            if(linhas<10){
                printf("  ");
                printf("%d",linhas);
                printf("    ");
            }
            if(linhas>9 && linhas<100){
                printf("  ");
                printf("%d",linhas);
                printf("   ");
            }
            if(linhas>99 && linhas<1000){
                printf("  ");
                printf("%d",linhas);
                printf("  ");
            }
            /// ----------------------- Cod
            printf("%c",186);
            StrCod[i] = strlen(prodinfo[i].codigo);
            CalCod[i] = 7 - StrCod[i];
            printf(" ");
            printf("%s",prodinfo[i].codigo);
            PrintSpaces(CalCod[i]);
            printf("%c",186);
            /// ----------------------- Nome
            StrNom[i] = strlen(prodinfo[i].nome);
            CalNom[i] = 30 - StrNom[i];
            printf(" ");
            printf("%s",prodinfo[i].nome);
            PrintSpaces(CalNom[i]);
            printf("%c",186);
            /// ----------------------- Marca
            StrMar[i] = strlen(prodinfo[i].marca);
            CalMar[i] = 12 - StrMar[i];
            printf(" ");
            printf("%s",prodinfo[i].marca);
            PrintSpaces(CalMar[i]);
            printf("%c",186);
            /// ----------------------- Descrição
            StrDes[i] = strlen(prodinfo[i].descricao);
            CalDes[i] = 44 - StrDes[i];
            printf(" ");
            printf("%s",prodinfo[i].descricao);
            PrintSpaces(CalDes[i]);
            printf("%c",186);
            /// ----------------------- Valor
            StrVal[i] = strlen(prodinfo[i].valor);
            CalVal[i] = 6 - StrVal[i];
            printf(" ");
            printf("R$%s",prodinfo[i].valor);
            PrintSpaces(CalVal[i]);
            printf("%c\n",186);
    }


}
///--------- opção

void PrintLimiOpc1 (int TamOpc1,int TamOpc2,int TamOpc3,int TamOpc4){
    printf("\n%c",201);
    for(int i=0;i<TamOpc1;i++){
        printf("%c",205);
    }
    printf("%c",187);

    printf(" ");

    printf("%c",201);
    for(int i=0;i<TamOpc2;i++){
        printf("%c",205);
    }
    printf("%c",187);

    printf(" ");

    printf("%c",201);
    for(int i=0;i<TamOpc3;i++){
        printf("%c",205);
    }
    printf("%c",187);

    printf(" ");

    printf("%c",201);
    for(int i=0;i<TamOpc4;i++){
        printf("%c",205);
    }
    printf("%c\n",187);

}

void PrintLimiOpc2 (int TamOpc1,int TamOpc2,int TamOpc3,int TamOpc4){

    printf("\n%c",200);
    for(int i=0;i<TamOpc1;i++){
        printf("%c",205);
    }
    printf("%c",188);

    printf(" ");

    printf("%c",200);
    for(int i=0;i<TamOpc2;i++){
        printf("%c",205);
    }
    printf("%c",188);

    printf(" ");

    printf("%c",200);
    for(int i=0;i<TamOpc3;i++){
        printf("%c",205);
    }
    printf("%c",188);

    printf(" ");

    printf("%c",200);
    for(int i=0;i<TamOpc4;i++){
        printf("%c",205);
    }
    printf("%c",188);
}

void PrintOpc (){

    /// ----------------------- Voltar
    printf("%c",186);
    printf(" [0] Voltar ");
    printf("%c ",186);
    /// ----------------------- Adicionar
    printf("%c",186);
    printf(" [1] Add ");
    printf("%c ",186);
    /// ----------------------- Editar
    printf("%c",186);
    printf(" [2] Editar ");
    printf("%c ",186);
    /// ----------------------- Excluir
    printf("%c",186);
    printf(" [3] Excluir ");
    printf("%c",186);

}


/// ----- Titulo -----
void criarLaterais(int tamX, char str[]){
    int contaLetras=0;
    int i;
    HANDLE colors=GetStdHandle(STD_OUTPUT_HANDLE);
    for(i=0;i<tamX;i++){
        if(str[i]=='\0'){
            break;
        }
        else{
            contaLetras++;
        }
        }
        printf("%c",186);
        SetConsoleTextAttribute(colors,11);
        printf("%s        ",str);
        SetConsoleTextAttribute(colors,15);
        while(contaLetras<tamX){
            printf("%c",32);
            contaLetras++;
        }
        printf("%c\n",186);
    }

/// ----- Tabela Produtos -----
void criarLaterais_Cli(int tamX, char lin[], char str[], char str1[], char str2[], char str3[], char str4[]){
    int contaLetras=0;
    int i;
    HANDLE colors=GetStdHandle(STD_OUTPUT_HANDLE);
    for(i=0;i<tamX;i++){
        if(str[i]=='\0'){
            break;
        }
        else{
            contaLetras++;
        }
        }
        printf("%c",186);
        printf("%s",lin);
        printf("%c",186);
        printf("%s",str);
        printf("%c",186);
        printf("%s",str1);
        printf("%c",186);
        printf("%s",str2);
        printf("%c",186);
        printf("%s",str3);
        printf("%c",186);
        printf("%s",str4);
        while(contaLetras<tamX){
            //printf("%c",32);
            contaLetras++;
        }
        printf("%c\n",186);

    }

/// - []
void PrintTeto_Alerta (int tam){ /// [Cria os caracteres limitadores na parte superior ou "teto" do alerta de confirmação]
    printf("%c",201);
    for(int i=0;i<tam;i++){
        printf("%c",205);
    }
    printf("%c \n",187);
}

void PrintBase_Alerta (int tam){ /// [Cria os caracteres limitadores na parte inferior ou "rodapé" do alerta de confirmação]
    printf("%c",200);
    for(int i=0;i<tam;i++){
        printf("%c",205);
    }
    printf("%c\n",188);
}

void PrintAlerta (){ /// [Imprime oque estara escrito no alerta]
    int i=0, linhas=0;

    /// ----- Alerta -----
    printf("%c",186);
    printf("Deseja continuar?");
    printf("%c\n",186);
    printf("%c",186);
    printf("                 ");
    printf("%c\n",186);
    printf("%c",186);
    printf(" [1] NAO [2] SIM ");
    printf("%c\n",186);


}

void PrintERROR (){ /// [Imprime oque estara escrito no alerta de ERRO]
    int i=0, linhas=0;

    /// ----- Alerta -----
    printf("%c",186);
    printf("      ERROR      ");
    printf("%c\n",186);
    printf("%c",186);
    printf("                 ");
    printf("%c\n",186);
    printf("%c",186);
    printf(" Valor invalido! ");
    printf("%c\n",186);


}


#endif // BIBLIO_PRO_H_INCLUDED
