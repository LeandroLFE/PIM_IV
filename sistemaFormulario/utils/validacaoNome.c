#include<ctype.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<wchar.h>

int validacaoNome(const char* nome){

    for(int i=0; i<strlen(nome); i++){
        if(nome[i]>='0' && nome[i]<='9'){
            return 1;
        }
    }

    return 0;
}
