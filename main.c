#include<stdio.h>
#include<string.h>

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
            printf("\nUsuario/Senha invalidos, tente novamente\n");
        }
    }while(resultadoLogin != 0);

    printf("\n\nLogin realizado com sucesso!\n");

    return 0;
}
