// Importa��o das bibliotecas utilizadas no arquivo
#include<stdio.h> // printf()
#include<string.h> // strcpy() strupr()

// Inclui o cabe�alho com todos os cabe�alhos dos m�todos utilizados no programa
#include "../../headers/headers_programa.h"

// defini��o das cores utilizadas neste m�todo
#define VERMELHO_CLARO 12


const char* getEstado(const int tamanhoEstado, const int ajusteTamanhoStr){
    // Inicializa��o das vari�veis
    char estado[tamanhoEstado+ajusteTamanhoStr];
    const char* retorno;
    int validaEstado;
    do{ // Loop
        printf("\nEstado: ");
        // recebe o valor do estado do m�todo trimEspacosEmBrancoGetS e armazena dentro da vari�vel estado
        strcpy(estado, trimEspacosEmBrancoGetS(tamanhoEstado+ajusteTamanhoStr));
        // valida se o estado informado � uma das siglas dos estados brasileiros de 2 d�gitos
        validaEstado = validacaoEstado(strupr(estado), tamanhoEstado);
        // Caso n�o seja um estado v�lido, informa o usu�rio de acordo
        if(validaEstado != 0){
            printfColorido("\nEstado inv�lido, formato com 2 digitos dentre os estados brasileiros, tente novamente\n", VERMELHO_CLARO);
        }
    }while(validaEstado != 0); // repete o loop de obter um novo estado enquanto este estiver inv�lido
    retorno = estado;
    // retorna o estado inserido ap�s validado
    return retorno;
}
