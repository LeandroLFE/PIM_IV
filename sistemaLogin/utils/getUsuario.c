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
            printf("\n%sUsuario nao informado, tente novamente%s\n", colorir('v'), colorir('r'));
        }
    }while(strcmp(usuario, "")==0);
    retorno = usuario;
    return retorno;
}
