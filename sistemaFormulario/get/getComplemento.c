#include<stdio.h>
#include<string.h>

#include "../../headers/headers_programa.h"

//cores
#define VERMELHO_CLARO 12

const char* getComplemento(const int tamanhoMaxComplemento){

    char complemento[tamanhoMaxComplemento];
    const char* retorno;

    printf("\nComplemento (Opcional): ");
    strcpy(complemento, trimEspacosEmBrancoGetS(tamanhoMaxComplemento));

    retorno = complemento;
    return retorno;
}
