// Importação das bibliotecas utilizadas no arquivo
#include<stdio.h> // printf()
#include<string.h> // strcpy()

// Inclui o cabeçalho com todos os cabeçalhos dos métodos utilizados no programa
#include "../../headers/headers_programa.h"

// definição das cores utilizadas neste método
#define VERMELHO_CLARO 12


const char* getCEP(const int tamanhoCEP, const int ajusteTamanhoStr){
    // Inicialização das variáveis
    char CEP[tamanhoCEP+ajusteTamanhoStr];
    const char* retorno;
    int validaCEP;

    do{ // Loop
        printf("\nCEP: ");
        // recebe o valor do CEP do método trimEspacosEmBrancoGetS e armazena dentro da variável CEP
        strcpy(CEP, trimEspacosEmBrancoGetS(tamanhoCEP+ajusteTamanhoStr));
        // valida se o CEP com tamanho correto e contém apenas números
        validaCEP = validacaoCEP(CEP, tamanhoCEP);
         /*
            Caso o CEP esteja inválido receberá um número diferente de zero
            e informa ao usuário de acordo
        */
        if(validaCEP != 0){
            printfColorido("\nCEP inválido, apenas números, tente novamente\n", VERMELHO_CLARO);
        }
    }while(validaCEP != 0); // repete o loop de obter um novo CEP enquanto este estiver inválido
    retorno = CEP;
    // retorna o CEP inserido após validado
    return retorno;
}
