#include<ctype.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int validacaoTelefone(const char* telefone, const int tamanhoTelefone){
    if(strlen(telefone) != tamanhoTelefone){
        return 1;
    }
    for(int i=0; i<tamanhoTelefone; i++){
        if(!isdigit(telefone[i])){
            return 2;
        }
        if(i<2 && telefone[i] == '0'){
            return 3;
        }
        if(i==2 && telefone[i] != '9'){
            return 4;
        }
    }
    return 0;
}
