#include<stdio.h>
#include<string.h>

#include "../../headers/headers_programa.h"

//cores
#define VERMELHO_CLARO 12

const char* getComorbidades(const int tamanhoMaxComorbidades){

    char comorbidades[tamanhoMaxComorbidades];
    const char* retorno;

    printf("\nComorbidades: ");
    strcpy(comorbidades, trimEspacosEmBrancoGetS(tamanhoMaxComorbidades));

    retorno = comorbidades;
    return retorno;
}
