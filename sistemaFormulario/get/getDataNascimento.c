#include<stdio.h>
#include<string.h>

#include "../../headers/headers_programa.h"

//cores
#define VERMELHO_CLARO 12

const char* getDataNascimento(const int tamanhoData, const int ajusteTamanhoStr){

    char data[tamanhoData+ajusteTamanhoStr];
    const char* retorno;
    int validaData;
    do{
        printf("\nData de Nascimento: ");
        strcpy(data, trimEspacosEmBrancoGetS(tamanhoData+ajusteTamanhoStr));
        validaData = validacaoDataNascimento(data, tamanhoData);
        if(validaData < 0){
            printfColorido("\nData inválida, formato: ddmmaaaa, tente novamente\n", VERMELHO_CLARO);
        }
    }while(validaData < 0);
    retorno = data;
    return retorno;
}
