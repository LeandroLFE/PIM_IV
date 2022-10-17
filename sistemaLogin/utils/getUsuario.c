#include<stdio.h>
#include<string.h>

#include "../../headers/headers_programa.h"

const char* getUsuario(const int tamanhoMaxUsuario){
    const char* usuario;
    do{
        printf("\nInforme seu usuario: ");
        usuario = trimEspacosEmBrancoGetS(tamanhoMaxUsuario);
        if(strcmp(usuario, "")==0){
            printf("\nUsuario nao informado, tente novamente\n");
        }
    }while(strcmp(usuario, "")==0);

    return usuario;
}
