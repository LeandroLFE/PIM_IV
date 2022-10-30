// Importa��o das bibliotecas utilizadas no arquivo
#include<stdio.h> // printf()
#include<string.h> // strcpy()

// Inclui o cabe�alho com todos os cabe�alhos dos m�todos utilizados no programa
#include "../../headers/headers_programa.h"

// defini��o das cores utilizadas neste m�todo
#define VERMELHO_CLARO 12


const char* getComplemento(const int tamanhoMaxComplemento){
    // Inicializa��o das vari�veis
    char complemento[tamanhoMaxComplemento];
    const char* retorno;

    printf("\nComplemento (Opcional): ");
     // recebe o valor do complemento do m�todo trimEspacosEmBrancoGetS e armazena dentro da vari�vel complemento
    strcpy(complemento, trimEspacosEmBrancoGetS(tamanhoMaxComplemento));

    retorno = complemento;
    // retorna o complemento
    return retorno;
}
