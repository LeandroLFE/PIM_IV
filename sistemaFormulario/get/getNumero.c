// Importa��o das bibliotecas utilizadas no arquivo
#include<locale.h> // setlocale
#include<stdio.h> // printf()
#include<string.h> // strcpy()

// Inclui o cabe�alho com todos os cabe�alhos dos m�todos utilizados no programa
#include "../../headers/headers_programa.h"

// defini��o das cores utilizadas neste m�todo
#define VERMELHO_CLARO 12


const char* getNumero(const int tamanhoMaxNumero, const int ajusteTamanhoStr){
    // Inicializa��o das vari�veis
    char textoNumero[tamanhoMaxNumero+ajusteTamanhoStr];
    const char* retorno;
    int validaNumero;

    do{ // Loop
        setlocale(LC_ALL, "Portuguese_Brazil.1252"); // Altera o locale para Portugues do Brasil, encoding Windows 1252
        printf("\nN�mero: ");
        setlocale(LC_ALL, "C"); // Altera o locale para "C"
        // recebe o valor do numero do m�todo trimEspacosEmBrancoGetS e armazena dentro da vari�vel textoNumero
        strcpy(textoNumero, trimEspacosEmBrancoGetS(tamanhoMaxNumero+ajusteTamanhoStr));
        // valida se o numero cont�m apenas n�meros inteiros positivos entre 1 e 999999
        validaNumero = validacaoNumero(textoNumero, tamanhoMaxNumero);
        /*
            Caso o numero esteja inv�lido receber� um n�mero diferente de zero
            e informa ao usu�rio de acordo
        */
        if(validaNumero < 1){
            printfColorido("\nN�mero inv�lido, somente n�meros positivos at� 999999, tente novamente\n", VERMELHO_CLARO);
        }
    }while(validaNumero < 1); // repete o loop de obter um novo numero enquanto este estiver inv�lido
    retorno = textoNumero;
    // retorna o numero inserido ap�s validado em formato de texto
    return retorno;
}
