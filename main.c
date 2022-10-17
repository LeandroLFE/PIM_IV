#include<stdio.h>
#include<stdlib.h>

#include "headers/headers_programa.h"

#define TAMANHO_MAX_USUARIO 15
#define TAMANHO_MAX_SENHA 15

int main(void){
    int login;

    login = sistemaLogin(TAMANHO_MAX_USUARIO, TAMANHO_MAX_SENHA);

    if(login != 0){
        printf("\nUm erro ocorreu, contate o administrador\n");
        exit(-2);
    }

    printf("\n\nLogin realizado com sucesso!\n");

    return 0;
}
