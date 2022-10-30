// Importa��o das bibliotecas utilizadas no arquivo
#include<stdio.h> // printf()
#include<string.h> // strcpy() strcmp()

// Inclui o cabe�alho com todos os cabe�alhos dos m�todos utilizados no programa
#include "../../headers/headers_programa.h"

// defini��o das cores utilizadas neste m�todo
#define VERMELHO_CLARO 12


const char* getBairro(const int tamanhoMaxBairro){
    // Inicializa��o das vari�veis
    char bairro[tamanhoMaxBairro];
    const char* retorno;

    do{ // Loop
        printf("\nBairro: ");
        // recebe o valor do bairro do m�todo trimEspacosEmBrancoGetS e armazena dentro da vari�vel bairro
        strcpy(bairro, trimEspacosEmBrancoGetS(tamanhoMaxBairro));
        /* Caso o bairro n�o tenha sido informado, informa o usuario de acordo */
        if(strcmp(bairro, "")==0){
            printfColorido("\nBairro n�o informado, tente novamente\n", VERMELHO_CLARO);
        }
    }while(strcmp(bairro, "")==0); // repete o loop at� que seja informado um bairro

    retorno = bairro;
    // retorna o bairro inserido
    return retorno;
}
