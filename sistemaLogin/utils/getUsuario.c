#include<stdio.h>
#include<string.h>

#include "../../headers/headers_programa.h"

//cores
#define VERMELHO_CLARO 12
#define BRANCO 15

const char* getUsuario(const int tamanhoMaxUsuario){
    char usuario[tamanhoMaxUsuario];
    const char* retorno;
    do{
        printf("\nInforme seu usuario: ");
        strcpy(usuario, trimEspacosEmBrancoGetS(tamanhoMaxUsuario));
        if(strcmp(usuario, "")==0){
            setColor(VERMELHO_CLARO);
            printf("\nUsuario nao informado, tente novamente\n");
            setColor(BRANCO);
        }
    }while(strcmp(usuario, "")==0);
    retorno = usuario;
    return retorno;
}
