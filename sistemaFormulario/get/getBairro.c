#include<stdio.h>
#include<string.h>

#include "../../headers/headers_programa.h"

//cores
#define VERMELHO_CLARO 12

const char* getBairro(const int tamanhoMaxBairro){

    char bairro[tamanhoMaxBairro];
    const char* retorno;

    do{
        printf("\nBairro: ");
        strcpy(bairro, trimEspacosEmBrancoGetS(tamanhoMaxBairro));
        if(strcmp(bairro, "")==0){
            printfColorido("\nBairro não informado, tente novamente\n", VERMELHO_CLARO);
        }
    }while(strcmp(bairro, "")==0);

    retorno = bairro;
    return retorno;
}
