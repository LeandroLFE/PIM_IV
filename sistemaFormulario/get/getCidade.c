#include<stdio.h>
#include<string.h>

#include "../../headers/headers_programa.h"

//cores
#define VERMELHO_CLARO 12

const char* getCidade(const int tamanhoMaxCidade){

    char cidade[tamanhoMaxCidade];
    const char* retorno;

    do{
        printf("\nCidade: ");
        strcpy(cidade, trimEspacosEmBrancoGetS(tamanhoMaxCidade));
        if(strcmp(cidade, "")==0){
            printfColorido("\nCidade não informada, tente novamente\n", VERMELHO_CLARO);
        }
    }while(strcmp(cidade, "")==0);

    retorno = cidade;
    return retorno;
}
