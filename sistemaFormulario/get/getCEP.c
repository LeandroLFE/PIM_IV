// Importa��o das bibliotecas utilizadas no arquivo
#include<stdio.h> // printf()
#include<string.h> // strcpy()

// Inclui o cabe�alho com todos os cabe�alhos dos m�todos utilizados no programa
#include "../../headers/headers_programa.h"

// defini��o das cores utilizadas neste m�todo
#define VERMELHO_CLARO 12


const char* getCEP(const int tamanhoCEP, const int ajusteTamanhoStr){
    // Inicializa��o das vari�veis
    char CEP[tamanhoCEP+ajusteTamanhoStr];
    const char* retorno;
    int validaCEP;

    do{ // Loop
        printf("\nCEP: ");
        // recebe o valor do CEP do m�todo trimEspacosEmBrancoGetS e armazena dentro da vari�vel CEP
        strcpy(CEP, trimEspacosEmBrancoGetS(tamanhoCEP+ajusteTamanhoStr));
        // valida se o CEP com tamanho correto e cont�m apenas n�meros
        validaCEP = validacaoCEP(CEP, tamanhoCEP);
         /*
            Caso o CEP esteja inv�lido receber� um n�mero diferente de zero
            e informa ao usu�rio de acordo
        */
        if(validaCEP != 0){
            printfColorido("\nCEP inv�lido, apenas n�meros, tente novamente\n", VERMELHO_CLARO);
        }
    }while(validaCEP != 0); // repete o loop de obter um novo CEP enquanto este estiver inv�lido
    retorno = CEP;
    // retorna o CEP inserido ap�s validado
    return retorno;
}
