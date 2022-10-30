// Importa��o das bibliotecas utilizadas no arquivo
#include<stdio.h> // printf()
#include<string.h> // strcpy() strcmp()

// Inclui o cabe�alho com todos os cabe�alhos dos m�todos utilizados no programa
#include "../../headers/headers_programa.h"

// defini��o das cores utilizadas neste m�todo
#define VERMELHO_CLARO 12


const char* getNome(const int tamanhoMaxNome){
    // Inicializa��o das vari�veis
    char nome[tamanhoMaxNome];
    const char* retorno;
    int validaNome = 1;

    do{ // Loop
        printf("\nNome: ");
        // recebe o valor do nome do m�todo trimEspacosEmBrancoGetS e armazena dentro da vari�vel nome
        strcpy(nome, trimEspacosEmBrancoGetS(tamanhoMaxNome));
        /* Caso o nome esteja vazio */
        if(strcmp(nome, "")==0){
            printfColorido("\nNome n�o informado, tente novamente\n", VERMELHO_CLARO);
        }
        // valida se o nome n�o cont�m n�meros
        validaNome = validacaoNome(nome);
        // Caso contenha n�meros, informa ao usu�rio de acordo
        if(validaNome != 0){
            printfColorido("\nNome inv�lido, n�o pode conter n�meros, tente novamente\n", VERMELHO_CLARO);
        }
    }while(strcmp(nome, "")==0 || validaNome != 0); // repete o loop caso nome esteja inv�lido

    retorno = nome;
    // retorna o nome inserido ap�s validado
    return retorno;
}
