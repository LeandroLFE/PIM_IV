// Importa��o das bibliotecas utilizadas no arquivo
#include<stdio.h> // printf()
#include<string.h> // strcpy()

// Inclui o cabe�alho com todos os cabe�alhos dos m�todos utilizados no programa
#include "../../headers/headers_programa.h"

// defini��o das cores utilizadas neste m�todo
#define VERMELHO_CLARO 12


const char* getCPF(const int tamanhoCPF, const int ajusteTamanhoStr){
    // Inicializa��o das vari�veis
    char CPF[tamanhoCPF+ajusteTamanhoStr];
    int validaCPF;
    const char* retorno;

    do{ // Loop
        printf("\nCPF: ");
        // recebe o valor do CPF do m�todo trimEspacosEmBrancoGetS e armazena dentro da vari�vel CPF
        strcpy(CPF, trimEspacosEmBrancoGetS(tamanhoCPF+ajusteTamanhoStr));
        // valida se o CPF com tamanho correto, cont�m apenas n�meros, digito verificador conforme c�lculo e se este CPF j� n�o foi cadastrado
        validaCPF = validacaoCPF(CPF, tamanhoCPF);
        /*
            Caso o CPF esteja inv�lido receber� um n�mero diferente de zero
            e informa ao usu�rio de acordo
        */
        if(validaCPF != 0){
            printfColorido("\nCPF inv�lido, apenas numeros com digito verificador v�lido, tente novamente\n", VERMELHO_CLARO);
        }
    }while(validaCPF != 0); // repete o loop de obter um novo CPF enquanto este estiver inv�lido
    retorno = CPF;
    // retorna o CPF inserido ap�s validado
    return retorno;
}
