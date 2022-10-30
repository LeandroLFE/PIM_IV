// Importa��o das bibliotecas utilizadas no arquivo
#include<stdio.h> // printf()
#include<string.h> // strcpy()

// Inclui o cabe�alho com todos os cabe�alhos dos m�todos utilizados no programa
#include "../../headers/headers_programa.h"

// defini��o das cores utilizadas neste m�todo
#define VERMELHO_CLARO 12


const char* getDataNascimento(const int tamanhoData, const int ajusteTamanhoStr){
    // Inicializa��o das vari�veis
    char data[tamanhoData+ajusteTamanhoStr];
    const char* retorno;
    int validaData;

    do{ // Loop
        printf("\nData de Nascimento: ");
        // recebe o valor da data de nascimento do m�todo trimEspacosEmBrancoGetS e armazena dentro da vari�vel data
        strcpy(data, trimEspacosEmBrancoGetS(tamanhoData+ajusteTamanhoStr));
        /*
            valida se a data informada � valida:
            - tamanho 8 characters
            - composta apenas por n�meros
            - n�meros positivos
            - data informada n�o superior a data atual, com ano n�o inferior a 150 anos antes do ano atual
            - mes informado entre 01 e 12
            - dia informado n�o superior a quantidade de dias poss�veis do m�s, inclusive quando fevereiro possui 29 dias
            - retorna um numero positivo (idade) caso OK
            - retorna um numero negativo caso NOK, informando o usu�rio de acordo
        */
        validaData = validacaoDataNascimento(data, tamanhoData);
        if(validaData < 0){
            switch(validaData){
            case -4:
                printfColorido("\nData inv�lida, a data informada n�o pode ser superior a data atual, tente novamente\n", VERMELHO_CLARO);
                break;
            case -5:
                printfColorido("\nO ano informado tamb�m n�o pode ser 150 anos antes do ano atual, tente novamente\n", VERMELHO_CLARO);
                break;
            case -6:
                printfColorido("\nM�s inv�lido, tente novamente\n", VERMELHO_CLARO);
                break;
            case -7:
                printfColorido("\nDia informado n�o pode ser superior ao n�mero de dias que o m�s pode conter, tente novamente\n", VERMELHO_CLARO);
                break;
            default:
                printfColorido("\nData inv�lida, formato: ddmmaaaa, apenas n�meros positivos, tente novamente\n", VERMELHO_CLARO);
            }
        }
    }while(validaData < 0); // repete o loop de obter uma nova data de nascimento enquanto este estiver inv�lida

    retorno = data;
    // retorna a data de nascimento inserida ap�s validada
    return retorno;
}
