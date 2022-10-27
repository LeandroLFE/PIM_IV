#include<locale.h>
#include<stdio.h>
#include<string.h>

#include "../../headers/headers_programa.h"

//cores
#define VERMELHO_CLARO 12


const char* getUsuario(const int tamanhoMaxUsuario){
    char usuario[tamanhoMaxUsuario];
    const char* retorno;
    do{
        setlocale(LC_ALL, "Portuguese_Brazil.1252");
        printf("\n%s", "Informe seu usu�rio: ");
        setlocale(LC_ALL, "C");

        strcpy(usuario, trimEspacosEmBrancoGetS(tamanhoMaxUsuario));
        if(strcmp(usuario, "")==0){
            printfColorido("\nUsu�rio n�o informado, tente novamente\n", VERMELHO_CLARO);
        }
    }while(strcmp(usuario, "")==0);
    retorno = usuario;
    return retorno;
}
