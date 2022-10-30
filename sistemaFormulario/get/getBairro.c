// Importação das bibliotecas utilizadas no arquivo
#include<stdio.h> // printf()
#include<string.h> // strcpy() strcmp()

// Inclui o cabeçalho com todos os cabeçalhos dos métodos utilizados no programa
#include "../../headers/headers_programa.h"

// definição das cores utilizadas neste método
#define VERMELHO_CLARO 12


const char* getBairro(const int tamanhoMaxBairro){
    // Inicialização das variáveis
    char bairro[tamanhoMaxBairro];
    const char* retorno;

    do{ // Loop
        printf("\nBairro: ");
        // recebe o valor do bairro do método trimEspacosEmBrancoGetS e armazena dentro da variável bairro
        strcpy(bairro, trimEspacosEmBrancoGetS(tamanhoMaxBairro));
        /* Caso o bairro não tenha sido informado, informa o usuario de acordo */
        if(strcmp(bairro, "")==0){
            printfColorido("\nBairro não informado, tente novamente\n", VERMELHO_CLARO);
        }
    }while(strcmp(bairro, "")==0); // repete o loop até que seja informado um bairro

    retorno = bairro;
    // retorna o bairro inserido
    return retorno;
}
