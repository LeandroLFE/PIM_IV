#include<stdio.h>
#include<stdlib.h>

#include "headers/headers_programa.h"

#define TAMANHO_MAX_USUARIO 15
#define TAMANHO_MAX_SENHA 15

//cores
#define CIANO 3
#define VERMELHO_CLARO 12
#define BRANCO 15


int main(void){
    int login;

    setColor(BRANCO);
    login = sistemaLogin(TAMANHO_MAX_USUARIO, TAMANHO_MAX_SENHA);

    if(login != 0){
        printfColorido("\n\nUsuario/Senha invalidos, tente novamente\n\n", VERMELHO_CLARO);
    }

    printfColorido("\n\nLogin realizado com sucesso!\n\n", CIANO);

    return 0;
}
