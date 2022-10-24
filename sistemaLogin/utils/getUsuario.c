#include<stdio.h>
#include<string.h>

#include "../../headers/headers_programa.h"

//cores
#define VERMELHO_CLARO 12

const char* getUsuario(const int tamanhoMaxUsuario){
    char usuario[tamanhoMaxUsuario];
    const char* retorno;
    do{
        printf("\nInforme seu usuário: ");
        strcpy(usuario, trimEspacosEmBrancoGetS(tamanhoMaxUsuario));
        if(strcmp(usuario, "")==0){
            printfColorido("\nUsuário não informado, tente novamente\n", VERMELHO_CLARO);
        }
    }while(strcmp(usuario, "")==0);
    retorno = usuario;
    return retorno;
}
