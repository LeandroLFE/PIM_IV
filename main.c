#include<stdio.h>
#include<stdlib.h>

#include "headers/headers_programa.h"

#define TAMANHO_MAX_USUARIO 50
#define TAMANHO_MAX_SENHA 128

int main(void){
    int login;

    login = sistemaLogin(TAMANHO_MAX_USUARIO, TAMANHO_MAX_SENHA);
    
    if(login != 0){
        printf("\n\n%sUsuario/Senha invalidos, tente novamente%s\n\n", colorir('v'), colorir('r'));
    }
    
    printf("\n\n%sLogin realizado com sucesso!%s\n", colorir('c'), colorir('r'));

    return 0;
}
