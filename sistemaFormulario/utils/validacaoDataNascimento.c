#include<ctype.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#include "../../headers/headers_programa.h"


int validacaoDataNascimento(const char* dataNascimento, const int tamanhoData){
    if(strlen(dataNascimento) != tamanhoData){
        return -1;
    }
    for(int i=0; i<tamanhoData; i++){
        if(!isdigit(dataNascimento[i])){
            return -2;
        }
    }

    return calculaIdade(dataNascimento);
}
