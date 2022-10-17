#include<stdio.h>

#include "headers/headers_programa.h"

#define TAMANHO_MAX_USUARIO 50
#define TAMANHO_MAX_SENHA 128

int main(void){
    const char* usuario;
    const char* senha;
    int resultadoLogin;
    do{
        printf("************************************");
        printf("\n*******BEM VINDO AO SISTEMA*********");
        printf("\n************************************\n");

        usuario = getUsuario(TAMANHO_MAX_USUARIO);
        senha = getSenha(TAMANHO_MAX_SENHA);
        resultadoLogin = login(usuario, TAMANHO_MAX_USUARIO, senha, TAMANHO_MAX_SENHA);

        if(resultadoLogin != 0){
            printf("\n\n%sUsuario/Senha invalidos, tente novamente%s\n\n", colorir('v'), colorir('r'));
        }
    }while(resultadoLogin != 0);

    printf("\n\n%sLogin realizado com sucesso!%s\n", colorir('c'), colorir('r'));

    return 0;
}
