#include<stdio.h>
#include<string.h>

#include "../../headers/headers_programa.h"

//cores
#define VERMELHO_CLARO 12

const char* getNome(const int tamanhoMaxNome){

    char nome[tamanhoMaxNome];
    const char* retorno;

    do{
        printf("\nNome: ");
        strcpy(nome, trimEspacosEmBrancoGetS(tamanhoMaxNome));
        if(strcmp(nome, "")==0){
            printfColorido("\nNome nao informado, tente novamente\n", VERMELHO_CLARO);
        }
    }while(strcmp(nome, "")==0);

    retorno = nome;
    return retorno;
}
