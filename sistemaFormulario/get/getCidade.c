// Importa��o das bibliotecas utilizadas no arquivo
#include<stdio.h> // printf()
#include<string.h> // strcpy() strcmp()

// Inclui o cabe�alho com todos os cabe�alhos dos m�todos utilizados no programa
#include "../../headers/headers_programa.h"

// defini��o das cores utilizadas neste m�todo
#define VERMELHO_CLARO 12


const char* getCidade(const int tamanhoMaxCidade){
    // Inicializa��o das vari�veis
    char cidade[tamanhoMaxCidade];
    const char* retorno;

    do{ // Loop
        printf("\nCidade: ");
        // recebe o valor da cidade do m�todo trimEspacosEmBrancoGetS e armazena dentro da vari�vel cidade
        strcpy(cidade, trimEspacosEmBrancoGetS(tamanhoMaxCidade));
         /* Caso a cidade n�o tenha sido informada, informa o usuario de acordo */
        if(strcmp(cidade, "")==0){
            printfColorido("\nCidade n�o informada, tente novamente\n", VERMELHO_CLARO);
        }
    }while(strcmp(cidade, "")==0); // repete o loop at� que seja informada uma cidade

    retorno = cidade;
    // retorna a cidade inserida
    return retorno;
}
