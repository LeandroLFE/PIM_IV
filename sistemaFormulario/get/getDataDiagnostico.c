// Importa��o das bibliotecas utilizadas no arquivo
#include<locale.h> // setlocale
#include<stdio.h> // printf()
#include<string.h> // strcpy()

// Inclui o cabe�alho com todos os cabe�alhos dos m�todos utilizados no programa
#include "../../headers/headers_programa.h"

// defini��o das cores utilizadas neste m�todo
#define VERMELHO_CLARO 12


const char* getDataDiagnostico(const int tamanhoData, const int ajusteTamanhoStr, const char* dataNascimento){
    char dataDiagnostico[tamanhoData+ajusteTamanhoStr];
    const char* retorno;
    int validaData;
    do{
        setlocale(LC_ALL, "Portuguese_Brazil.1252");
        printf("\nData de Diagn�stico: ");
        setlocale(LC_ALL, "C");

        strcpy(dataDiagnostico, trimEspacosEmBrancoGetS(tamanhoData+ajusteTamanhoStr));
        validaData = validacaoDataDiagnostico(dataDiagnostico, tamanhoData, dataNascimento);
        if(validaData < 0){
            printfColorido("\nData inv�lida, formato: ddmmaaaa, tente novamente\n", VERMELHO_CLARO);
        }
    }while(validaData < 0);
    retorno = dataDiagnostico;
    return retorno;
}
