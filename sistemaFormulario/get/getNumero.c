#include<stdio.h>
#include<string.h>

#include "../../headers/headers_programa.h"

//cores
#define VERMELHO_CLARO 12

const int getNumero(const int tamanhoMaxNumero, const int ajusteTamanhoStr){
    int numero;
    int validaNumero;
    char textoNumero[tamanhoMaxNumero+ajusteTamanhoStr];

    do{
        printf("\nNúmero: ");
        strcpy(textoNumero, trimEspacosEmBrancoGetS(tamanhoMaxNumero+ajusteTamanhoStr));
        numero = validacaoNumero(textoNumero, tamanhoMaxNumero);
        if(numero < 1){
            printfColorido("\nNúmero inválido, somente números positivos até 999999, tente novamente\n", VERMELHO_CLARO);
        }
    }while(numero < 1);

    return numero;
}
