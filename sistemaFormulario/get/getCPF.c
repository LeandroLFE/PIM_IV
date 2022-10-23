#include<stdio.h>
#include<string.h>

#include "../../headers/headers_programa.h"

#define VERMELHO_CLARO 12

const char* getCPF(const int tamanhoCPF, const int ajusteTamanhoStr){
    char CPF[tamanhoCPF+ajusteTamanhoStr];
    int validaCPF;
    const char* retorno;
    do{
        printf("\nCPF: ");
        strcpy(CPF, trimEspacosEmBrancoGetS(tamanhoCPF+ajusteTamanhoStr));
        validaCPF = validacaoCPF(CPF, tamanhoCPF);
        if(validaCPF != 0){
            printfColorido("\nCPF invalido, tente novamente\n", VERMELHO_CLARO);
        }
    }while(validaCPF != 0);
    retorno = CPF;
    return retorno;
}
