// Importa��o das bibliotecas utilizadas no arquivo
#include<stdio.h> // printf()
#include<string.h> // strcpy()

// Inclui o cabe�alho com todos os cabe�alhos dos m�todos utilizados no programa
#include "../../headers/headers_programa.h"

// defini��o das cores utilizadas neste m�todo
#define VERMELHO_CLARO 12


const char* getComorbidades(const int tamanhoMaxComorbidades){
    // Inicializa��o das vari�veis
    char comorbidades[tamanhoMaxComorbidades];
    const char* retorno;

    printf("\nComorbidades: ");
     // recebe o valor das comorbidades do m�todo trimEspacosEmBrancoGetS e armazena dentro da vari�vel comorbidades
    strcpy(comorbidades, trimEspacosEmBrancoGetS(tamanhoMaxComorbidades));

    retorno = comorbidades;
    // retorna as comorbidades
    return retorno;
}
