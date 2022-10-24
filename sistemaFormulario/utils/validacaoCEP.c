#include<ctype.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int validacaoCEP(const char* CEP, const int tamanhoCEP){
    if(strlen(CEP) != tamanhoCEP){
        return 1;
    }
    for(int i=0; i<tamanhoCEP; i++){
        if(!isdigit(CEP[i])){
            return 2;
        }
    }
    return 0;
}
