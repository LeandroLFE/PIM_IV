// Importação das bibliotecas utilizadas no arquivo
#include<stdio.h> // printf()
#include<string.h> // strcpy()

// Inclui o cabeçalho com todos os cabeçalhos dos métodos utilizados no programa
#include "../../headers/headers_programa.h"

// definição das cores utilizadas neste método
#define VERMELHO_CLARO 12


const char* getComplemento(const int tamanhoMaxComplemento){
    // Inicialização das variáveis
    char complemento[tamanhoMaxComplemento];
    const char* retorno;

    printf("\nComplemento (Opcional): ");
     // recebe o valor do complemento do método trimEspacosEmBrancoGetS e armazena dentro da variável complemento
    strcpy(complemento, trimEspacosEmBrancoGetS(tamanhoMaxComplemento));

    retorno = complemento;
    // retorna o complemento
    return retorno;
}
