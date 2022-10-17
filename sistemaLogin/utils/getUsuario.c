#include<stdio.h>
#include<string.h>

#include "../../headers/headers_programa.h"

const char* getUsuario(const int tamanhoMaxUsuario){
    char usuario[tamanhoMaxUsuario];
    const char* retorno;
    do{
        printf("\nInforme seu usuario: ");
        strcpy(usuario, trimEspacosEmBrancoGetS(tamanhoMaxUsuario));
        if(strcmp(usuario, "")==0){
            printf("\nUsuario nao informado, tente novamente\n");
        }
    }while(strcmp(usuario, "")==0);
    retorno = usuario;
    return retorno;
}
