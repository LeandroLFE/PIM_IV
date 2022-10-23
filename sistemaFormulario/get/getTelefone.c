#include<stdio.h>
#include<string.h>

#include "../../headers/headers_programa.h"

//cores
#define VERMELHO_CLARO 12

const char* getTelefone(const int tamanhoTelefone, const int ajusteTamanhoStr){

  char telefone[tamanhoTelefone];
    const char* retorno;
    int validaTelefone;
    do{
        printf("\nTelefone: ");
        strcpy(telefone, trimEspacosEmBrancoGetS(tamanhoTelefone+ajusteTamanhoStr));
        validaTelefone = validacaoTelefone(telefone, tamanhoTelefone);
        if(validaTelefone != 0){
            printfColorido("\nTelefone invalido, formato: DDD com 2 digitos + 9XXXXXXXX tente novamente\n", VERMELHO_CLARO);
        }
    }while(validaTelefone != 0);
    retorno = telefone;
    return retorno;
}
