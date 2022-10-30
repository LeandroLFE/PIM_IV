// Importa��o das bibliotecas utilizadas no arquivo
#include<locale.h> // setlocale()
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
            switch(validaData){
            case -4:
                printfColorido("\nData inv�lida, a data informada n�o pode ser superior a data atual, tente novamente\n", VERMELHO_CLARO);
                break;
            case -5:
                printfColorido("\nO ano informado tamb�m n�o pode ser 150 anos antes do ano atual, tente novamente\n", VERMELHO_CLARO);
                break;
            case -6:
                printfColorido("\nM�s inv�lido, tente novamente\n", VERMELHO_CLARO);
                break;
            case -7:
                printfColorido("\nDia informado n�o pode ser superior ao n�mero de dias que o m�s pode conter, tente novamente\n", VERMELHO_CLARO);
                break;
            case -8:
                printfColorido("\nA data de diagn�stico n�o pode ser antes da data de nascimento, tente novamente\n", VERMELHO_CLARO);
                break;
            default:
                printfColorido("\nData inv�lida, formato: ddmmaaaa, apenas n�meros positivos, tente novamente\n", VERMELHO_CLARO);
            }
        }
    }while(validaData < 0);
    retorno = dataDiagnostico;
    return retorno;
}
