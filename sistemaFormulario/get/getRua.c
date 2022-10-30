// Importa��o das bibliotecas utilizadas no arquivo
#include<stdio.h> // printf()
#include<string.h> // strcpy() strcmp()

// Inclui o cabe�alho com todos os cabe�alhos dos m�todos utilizados no programav
#include "../../headers/headers_programa.h"

// defini��o das cores utilizadas neste m�todo
#define VERMELHO_CLARO 12


const char* getRua(const int tamanhoMaxRua){
    // Inicializa��o das vari�veis
    char rua[tamanhoMaxRua];
    const char* retorno;
    do{ // Loop
        printf("\nRua: ");
        // recebe o valor da rua do m�todo trimEspacosEmBrancoGetS e armazena dentro da vari�vel rua
        strcpy(rua, trimEspacosEmBrancoGetS(tamanhoMaxRua));
         /* Caso a rua n�o tenha sido informada, informa o usuario de acordo */
        if(strcmp(rua, "")==0){
            printfColorido("\nRua n�o informada, tente novamente\n", VERMELHO_CLARO);
        }
    }while(strcmp(rua, "")==0); // repete o loop at� que seja informada uma rua
    retorno = rua;
    // retorna a rua inserida
    return retorno;
}
