#ifndef MENU_H_INCLUDED
#define MENU_H_INCLUDED

#define TAMANHO 80

void criarTeto(){
    int i;
    printf("%c",201);
    for(i=0;i<TAMANHO;i++){
        printf("%c",205);
    }
    printf("%c\n",187);
}

void criarRodape(int tamX){
    int i;
    printf("%c",200);
    for(i=0;i<TAMANHO;i++){
        printf("%c",205);
    }
    printf("%c\n",188);
}

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

void criarLaterais2(int tamX, char str[]){
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
        printf("%s",str);
        while(contaLetras<tamX){
            printf("%c",32);
            contaLetras++;
        }
        printf("%c\n",186);
    }


#endif // MENU_H_INCLUDED
