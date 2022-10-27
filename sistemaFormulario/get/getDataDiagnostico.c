#include<locale.h>
#include<stdio.h>
#include<string.h>

#include "../../headers/headers_programa.h"

//cores
#define VERMELHO_CLARO 12

const char* getDataDiagnostico(const int tamanhoData, const int ajusteTamanhoStr, const char* dataNascimento){
    char dataDiagnostico[tamanhoData+ajusteTamanhoStr];
    const char* retorno;
    int validaData;
    do{
        setlocale(LC_ALL, "Portuguese_Brazil.1252");
        printf("\nData de Diagnóstico: ");
        setlocale(LC_ALL, "C");

        strcpy(dataDiagnostico, trimEspacosEmBrancoGetS(tamanhoData+ajusteTamanhoStr));
        validaData = validacaoDataDiagnostico(dataDiagnostico, tamanhoData, dataNascimento);
        if(validaData < 0){
            printfColorido("\nData inválida, formato: ddmmaaaa, tente novamente\n", VERMELHO_CLARO);
        }
    }while(validaData < 0);
    retorno = dataDiagnostico;
    return retorno;
}
