#ifndef BIBLIO_CLI_H_INCLUDED
#define BIBLIO_CLI_H_INCLUDED

#define Tamanho_Titu 99
#define Tamanho_TCli 99
#define Tamanho_Sair 10


 typedef struct node {
    char codigo[101],nome[101],cpf[101],telefone[101],nascimento[101];
} Cli;
    char codigo[101],nome[101],cpf[101],telefone[101],nascimento[101];
    Cli cliinfo[9];

/// - [4 voids, controla o tamanho e informações da tabela] -
void PrintSpaces (int cont){ /// [Void usado dentro do "PrintLinhas" para arrumar a tabulação de cada coluna e linha]
    for(int i=0;i<cont;i++){
        printf(" ");
    }
}

void PrintLimites1 (int tam){ /// [Cria os caracteres limitadores na parte superior ou "teto" da tabela e titulos]
    printf("%c",201);
    for(int i=0;i<tam;i++){
        printf("%c",205);
    }
    printf("%c\n",187);
}

void PrintLimites2 (int tam){ /// [Cria os caracteres limitadores na parte inferior ou "rodapé" da tabela e titulos]
    printf("%c",200);
    for(int i=0;i<tam;i++){
        printf("%c",205);
    }
    printf("%c\n",188);
}

void PrintLinhas (int linha){ /// [Cria os caracteres limitadores de cada coluna "|", lê e imprime as informações de cada categoria]
    int i=0, linhas=0;
    int StrCod[50],CalCod[50], StrNom[50],CalNom[50], StrCpf[50],CalCpf[50], StrTel[50],CalTel[50], StrDat[50],CalDat[50];

    for(int i=0;i<linha;i++){
    linhas++;
            for (int p = 0; p < strlen(cliinfo[i].nome); ++p) {
            if (cliinfo[i].nome[p] == '_') {
                cliinfo[i].nome[p + 0] = ' ';
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
    StrCod[i] = strlen(cliinfo[i].codigo);
    CalCod[i] = 7 - StrCod[i];
    printf(" ");
    printf("%s",cliinfo[i].codigo);
    PrintSpaces(CalCod[i]);
    printf("%c",186);
    /// ----------------------- Nome
    StrNom[i] = strlen(cliinfo[i].nome);
    CalNom[i] = 30 - StrNom[i];
    printf(" ");
    printf("%s",cliinfo[i].nome);
    PrintSpaces(CalNom[i]);
    printf("%c",186);
    /// ----------------------- Cpf
    StrCpf[i] = strlen(cliinfo[i].cpf);
    CalCpf[i] = 19 - StrCpf[i];
    printf(" ");
    printf("%s",cliinfo[i].cpf);
    PrintSpaces(CalCpf[i]);
    printf("%c",186);
    /// ----------------------- Tele
    StrTel[i] = strlen(cliinfo[i].telefone);
    CalTel[i] = 15 - StrTel[i];
    printf(" ");
    printf("%s",cliinfo[i].telefone);
    PrintSpaces(CalTel[i]);
    printf("%c",186);
    /// ----------------------- Data
    StrDat[i] = strlen(cliinfo[i].nascimento);
    CalDat[i] = 19 - StrDat[i];
    printf(" ");
    printf("%s",cliinfo[i].nascimento);
    PrintSpaces(CalDat[i]);
    printf("%c\n",186);
    }


}

/// - [3 voids, controla o tamanho e informações nos botões de opção] -
void PrintLimiOpc1 (int TamOpc1,int TamOpc2,int TamOpc3,int TamOpc4){ /// [Cria os caracteres limitadores na parte superior ou "teto" de cada opção]
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

void PrintLimiOpc2 (int TamOpc1,int TamOpc2,int TamOpc3,int TamOpc4){ /// [Cria os caracteres limitadores na parte inferior ou "rodapé" de cada opção]

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

void PrintOpc (){ /// [Imprime oque estara escrito em cada opção]

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

/// - [1 void, imprime a informação de qual pagina o usuario esta] -
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
        printf("%s",str);
        SetConsoleTextAttribute(colors,15);
        while(contaLetras<tamX){
            printf("%c",32);
            contaLetras++;
        }
        printf("%c\n",186);
    }

/// - [1 void, imprime as informações do 2 titulo/definição geral de cada coluna da tabela] -
void criarLaterais_Cli(int tamX, char lin[],char str[], char str1[], char str2[], char str3[], char str4[]){
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

#endif // BIBLIO_CLI_H_INCLUDED
