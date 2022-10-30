// Importação das bibliotecas utilizadas no arquivo
#include<stdio.h> // printf()
#include<string.h> // strcpy()

// Inclui o cabeçalho com todos os cabeçalhos dos métodos utilizados no programa
#include "../../headers/headers_programa.h"

// definição das cores utilizadas neste método
#define VERMELHO_CLARO 12


const char* getDataNascimento(const int tamanhoData, const int ajusteTamanhoStr){
    // Inicialização das variáveis
    char data[tamanhoData+ajusteTamanhoStr];
    const char* retorno;
    int validaData;

    do{ // Loop
        printf("\nData de Nascimento: ");
        // recebe o valor da data de nascimento do método trimEspacosEmBrancoGetS e armazena dentro da variável data
        strcpy(data, trimEspacosEmBrancoGetS(tamanhoData+ajusteTamanhoStr));
        /*
            valida se a data informada é valida:
            - tamanho 8 characters
            - composta apenas por números
            - números positivos
            - data informada não superior a data atual, com ano não inferior a 150 anos antes do ano atual
            - mes informado entre 01 e 12
            - dia informado não superior a quantidade de dias possíveis do mês, inclusive quando fevereiro possui 29 dias
            - retorna um numero positivo (idade) caso OK
            - retorna um numero negativo caso NOK, informando o usuário de acordo
        */
        validaData = validacaoDataNascimento(data, tamanhoData);
        if(validaData < 0){
            printfColorido("\nData inválida, formato: ddmmaaaa, tente novamente\n", VERMELHO_CLARO);
        }
    }while(validaData < 0); // repete o loop de obter uma nova data de nascimento enquanto este estiver inválida

    retorno = data;
    // retorna a data de nascimento inserida após validada
    return retorno;
}
