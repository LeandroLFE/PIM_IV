// Importação das bibliotecas utilizadas no arquivo
#include<locale.h> // setlocale
#include<stdio.h> // printf()
#include<string.h> // strcpy()

// Inclui o cabeçalho com todos os cabeçalhos dos métodos utilizados no programa
#include "../../headers/headers_programa.h"

// definição das cores utilizadas neste método
#define VERMELHO_CLARO 12


const char* getNumero(const int tamanhoMaxNumero, const int ajusteTamanhoStr){
    // Inicialização das variáveis
    char textoNumero[tamanhoMaxNumero+ajusteTamanhoStr];
    const char* retorno;
    int validaNumero;

    do{ // Loop
        setlocale(LC_ALL, "Portuguese_Brazil.1252"); // Altera o locale para Portugues do Brasil, encoding Windows 1252
        printf("\nNúmero: ");
        setlocale(LC_ALL, "C"); // Altera o locale para "C"
        // recebe o valor do numero do método trimEspacosEmBrancoGetS e armazena dentro da variável textoNumero
        strcpy(textoNumero, trimEspacosEmBrancoGetS(tamanhoMaxNumero+ajusteTamanhoStr));
        // valida se o numero contém apenas números inteiros positivos entre 1 e 999999
        validaNumero = validacaoNumero(textoNumero, tamanhoMaxNumero);
        /*
            Caso o numero esteja inválido receberá um número diferente de zero
            e informa ao usuário de acordo
        */
        if(validaNumero < 1){
            printfColorido("\nNúmero inválido, somente números positivos até 999999, tente novamente\n", VERMELHO_CLARO);
        }
    }while(validaNumero < 1); // repete o loop de obter um novo numero enquanto este estiver inválido
    retorno = textoNumero;
    // retorna o numero inserido após validado em formato de texto
    return retorno;
}
