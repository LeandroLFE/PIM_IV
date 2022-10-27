#include<stdio.h>
#include<string.h>

#include "../../headers/headers_programa.h"

//cores
#define VERMELHO_CLARO 12

const char* getRua(const int tamanhoMaxRua){

    char rua[tamanhoMaxRua];
    const char* retorno;
    do{
        printf("\nRua: ");
        strcpy(rua, trimEspacosEmBrancoGetS(tamanhoMaxRua));
        if(strcmp(rua, "")==0){
            printfColorido("\nRua invalida, tente novamente\n", VERMELHO_CLARO);
        }
    }while(strcmp(rua, "")==0);
    retorno = rua;
    return retorno;
}
