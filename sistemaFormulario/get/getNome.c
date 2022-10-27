#include<stdio.h>
#include<string.h>

#include "../../headers/headers_programa.h"

//cores
#define VERMELHO_CLARO 12

const char* getNome(const int tamanhoMaxNome){

    char nome[tamanhoMaxNome];
    const char* retorno;
    int validaNome = 1;

    do{
        printf("\nNome: ");
        strcpy(nome, trimEspacosEmBrancoGetS(tamanhoMaxNome));
        if(strcmp(nome, "")==0){
            printfColorido("\nNome n�o informado, tente novamente\n", VERMELHO_CLARO);
        }
        validaNome = validacaoNome(nome);
        if(validaNome != 0){
            printfColorido("\nNome inv�lido, n�o pode conter n�meros, tente novamente\n", VERMELHO_CLARO);
        }

    }while(strcmp(nome, "")==0 || validaNome != 0);

    retorno = nome;
    return retorno;
}
