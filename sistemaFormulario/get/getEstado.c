// Importação das bibliotecas utilizadas no arquivo
#include<stdio.h> // printf()
#include<string.h> // strcpy() strupr()

// Inclui o cabeçalho com todos os cabeçalhos dos métodos utilizados no programa
#include "../../headers/headers_programa.h"

// definição das cores utilizadas neste método
#define VERMELHO_CLARO 12


const char* getEstado(const int tamanhoEstado, const int ajusteTamanhoStr){
    // Inicialização das variáveis
    char estado[tamanhoEstado+ajusteTamanhoStr];
    const char* retorno;
    int validaEstado;
    do{ // Loop
        printf("\nEstado: ");
        // recebe o valor do estado do método trimEspacosEmBrancoGetS e armazena dentro da variável estado
        strcpy(estado, trimEspacosEmBrancoGetS(tamanhoEstado+ajusteTamanhoStr));
        // valida se o estado informado é uma das siglas dos estados brasileiros de 2 dígitos
        validaEstado = validacaoEstado(strupr(estado), tamanhoEstado);
        // Caso não seja um estado válido, informa o usuário de acordo
        if(validaEstado != 0){
            printfColorido("\nEstado inválido, formato com 2 digitos dentre os estados brasileiros, tente novamente\n", VERMELHO_CLARO);
        }
    }while(validaEstado != 0); // repete o loop de obter um novo estado enquanto este estiver inválido
    retorno = estado;
    // retorna o estado inserido após validado
    return retorno;
}
