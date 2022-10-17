#include<stdio.h>
#include<string.h>

#include "../../headers/headers_programa.h"

const char* getUsuario(const int tamanhoMaxUsuario){
    const char* usuario;
    do{
        printf("\nInforme seu usuario: ");
        usuario = trimEspacosEmBrancoGetS(tamanhoMaxUsuario);
        if(strcmp(usuario, "")==0){
            printf("\n%sUsuario nao informado, tente novamente%s\n", colorir('v'), colorir('r'));
        }
    }while(strcmp(usuario, "")==0);

    return usuario;
}
