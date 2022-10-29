#include<locale.h>
#include<stdio.h>
#include<string.h>

#include "../../headers/headers_programa.h"

//cores
#define VERMELHO_CLARO 12

const char* getNumero(const int tamanhoMaxNumero, const int ajusteTamanhoStr){
    char textoNumero[tamanhoMaxNumero+ajusteTamanhoStr];
    const char* retorno;
    int validaNumero;

    do{
        setlocale(LC_ALL, "Portuguese_Brazil.1252");
        printf("\nNúmero: ");
        setlocale(LC_ALL, "C");

        strcpy(textoNumero, trimEspacosEmBrancoGetS(tamanhoMaxNumero+ajusteTamanhoStr));
        validaNumero = validacaoNumero(textoNumero, tamanhoMaxNumero);
        if(validaNumero < 1){
            printfColorido("\nNúmero inválido, somente números positivos até 999999, tente novamente\n", VERMELHO_CLARO);
        }
    }while(validaNumero < 1);

    retorno = textoNumero;
    return retorno;
}
