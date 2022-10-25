#include<stdio.h>
#include<string.h>

#include "../../headers/headers_programa.h"

//cores
#define VERMELHO_CLARO 12

const char* getCEP(const int tamanhoCEP, const int ajusteTamanhoStr){

    char CEP[tamanhoCEP+ajusteTamanhoStr];
    const char* retorno;
    int validaCEP;
    do{
        printf("\nCEP: ");
        strcpy(CEP, trimEspacosEmBrancoGetS(tamanhoCEP+ajusteTamanhoStr));
        validaCEP = validacaoCEP(CEP, tamanhoCEP);
        if(validaCEP != 0){
            printfColorido("\nCEP inválido, apenas números, tente novamente\n", VERMELHO_CLARO);
        }
    }while(validaCEP != 0);
    retorno = CEP;
    return retorno;
}
