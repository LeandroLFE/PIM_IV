// Importa��o das bibliotecas utilizadas no arquivo
#include<stdio.h> // printf()
#include<string.h> // strcpy()

// Inclui o cabe�alho com todos os cabe�alhos dos m�todos utilizados no programa
#include "../../headers/headers_programa.h"

// defini��o das cores utilizadas neste m�todo
#define VERMELHO_CLARO 12


const char* getTelefone(const int tamanhoTelefone, const int ajusteTamanhoStr){
    // Inicializa��o das vari�veis
    char telefone[tamanhoTelefone+ajusteTamanhoStr];
    const char* retorno;
    int validaTelefone;
    do{ // Loop
        printf("\nTelefone: ");
        // recebe o valor do telefone do m�todo trimEspacosEmBrancoGetS e armazena dentro da vari�vel telefone
        strcpy(telefone, trimEspacosEmBrancoGetS(tamanhoTelefone+ajusteTamanhoStr));
        // valida se o telefone est� do tamanho correto, cont�m apenas n�meros e n�o cont�m 0 no DDD de 2 d�gitos
        validaTelefone = validacaoTelefone(telefone, tamanhoTelefone);
        /*
            Caso o telefone esteja inv�lido receber� um n�mero diferente de zero
            e informa ao usu�rio de acordo
        */
        if(validaTelefone != 0){
            printfColorido("\nTelefone inv�lido, formato: DDD com 2 digitos + XXXXXXXXX, tente novamente\n", VERMELHO_CLARO);
        }
    }while(validaTelefone != 0); // repete o loop de obter um novo telefone enquanto este estiver inv�lido
    retorno = telefone;
    // retorna o telefone inserido ap�s validado
    return retorno;
}
