#include<ctype.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#include "../../headers/headers_programa.h"


int validacaoData(const char* data, const int tamanhoData){
    if(strlen(data) != tamanhoData){
        return -1;
    }
    for(int i=0; i<tamanhoData; i++){
        if(!isdigit(data[i])){
            return -2;
        }
    }

    return calculaIdade(data);
}
