// Importação das bibliotecas utilizadas no arquivo
#include<stdio.h> // printf()
#include<string.h> // strcpy()

// Inclui o cabeçalho com todos os cabeçalhos dos métodos utilizados no programa
#include "../../headers/headers_programa.h"

// definição das cores utilizadas neste método
#define VERMELHO_CLARO 12


const char* getComorbidades(const int tamanhoMaxComorbidades){
    // Inicialização das variáveis
    char comorbidades[tamanhoMaxComorbidades];
    const char* retorno;

    printf("\nComorbidades: ");
     // recebe o valor das comorbidades do método trimEspacosEmBrancoGetS e armazena dentro da variável comorbidades
    strcpy(comorbidades, trimEspacosEmBrancoGetS(tamanhoMaxComorbidades));

    retorno = comorbidades;
    // retorna as comorbidades
    return retorno;
}
