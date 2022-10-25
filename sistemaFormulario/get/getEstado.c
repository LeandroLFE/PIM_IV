#include<stdio.h>
#include<string.h>

#include "../../headers/headers_programa.h"

//cores
#define VERMELHO_CLARO 12

const char* getEstado(const int tamanhoEstado, const int ajusteTamanhoStr){

    char estado[tamanhoEstado+ajusteTamanhoStr];
    const char* retorno;
    int validaEstado;
    do{
        printf("\nEstado: ");
        strcpy(estado, trimEspacosEmBrancoGetS(tamanhoEstado+ajusteTamanhoStr));
        validaEstado = validacaoEstado(strupr(estado), tamanhoEstado);
        if(validaEstado != 0){
            printfColorido("\nEstado inválido, formato com 2 digitos dentre os estados brasileiros, tente novamente\n", VERMELHO_CLARO);
        }
    }while(validaEstado != 0);
    retorno = estado;
    return retorno;
}
