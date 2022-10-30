// Importação das bibliotecas utilizadas no arquivo
#include<locale.h> // setlocale()
#include<stdio.h> // printf()
#include<string.h> // strcpy()

// Inclui o cabeçalho com todos os cabeçalhos dos métodos utilizados no programa
#include "../../headers/headers_programa.h"

// definição das cores utilizadas neste método
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
            switch(validaData){
            case -4:
                printfColorido("\nData inválida, a data informada não pode ser superior a data atual, tente novamente\n", VERMELHO_CLARO);
                break;
            case -5:
                printfColorido("\nO ano informado também não pode ser 150 anos antes do ano atual, tente novamente\n", VERMELHO_CLARO);
                break;
            case -6:
                printfColorido("\nMês inválido, tente novamente\n", VERMELHO_CLARO);
                break;
            case -7:
                printfColorido("\nDia informado não pode ser superior ao número de dias que o mês pode conter, tente novamente\n", VERMELHO_CLARO);
                break;
            case -8:
                printfColorido("\nA data de diagnóstico não pode ser antes da data de nascimento, tente novamente\n", VERMELHO_CLARO);
                break;
            default:
                printfColorido("\nData inválida, formato: ddmmaaaa, apenas números positivos, tente novamente\n", VERMELHO_CLARO);
            }
        }
    }while(validaData < 0);
    retorno = dataDiagnostico;
    return retorno;
}
