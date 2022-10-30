// Importação das bibliotecas utilizadas no arquivo
#include<stdio.h> // printf()
#include<string.h> // strcpy() strcmp()

// Inclui o cabeçalho com todos os cabeçalhos dos métodos utilizados no programa
#include "../../headers/headers_programa.h"

// definição das cores utilizadas neste método
#define VERMELHO_CLARO 12


const char* getCidade(const int tamanhoMaxCidade){
    // Inicialização das variáveis
    char cidade[tamanhoMaxCidade];
    const char* retorno;

    do{ // Loop
        printf("\nCidade: ");
        // recebe o valor da cidade do método trimEspacosEmBrancoGetS e armazena dentro da variável cidade
        strcpy(cidade, trimEspacosEmBrancoGetS(tamanhoMaxCidade));
         /* Caso a cidade não tenha sido informada, informa o usuario de acordo */
        if(strcmp(cidade, "")==0){
            printfColorido("\nCidade não informada, tente novamente\n", VERMELHO_CLARO);
        }
    }while(strcmp(cidade, "")==0); // repete o loop até que seja informada uma cidade

    retorno = cidade;
    // retorna a cidade inserida
    return retorno;
}
