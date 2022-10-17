#include<stdio.h>
#include<string.h>

#define NULL_CHARACTER '\0'
#define ESPACO 32

const char* trimEspacosEmBrancoGetS(const int tamanhoMaxUsuario){
    char stringInicial[tamanhoMaxUsuario];
    char novaString[strlen(stringInicial)];
    const char* retorno;
    int lTrimIndex = 0;
    gets(stringInicial);
    int rTrimIndex = strlen(stringInicial)-1;

    if(strcmp(stringInicial, "")==0){
        return "";
    }

    for(int i=0; i<strlen(stringInicial); i++){
        lTrimIndex = i;
        if(stringInicial[i] != ESPACO){
            break;
        }
    }

    if(lTrimIndex == rTrimIndex){
        return "";
    }

    for(int i=rTrimIndex; i>=lTrimIndex; i--){
        if(stringInicial[i] != ESPACO){
            rTrimIndex = i;
            break;
        }
    }

    if(lTrimIndex>=rTrimIndex){
        return "";
    }

    for(int i=lTrimIndex; i<=rTrimIndex; i++){
        novaString[i-lTrimIndex] = stringInicial[i];
    }
    novaString[rTrimIndex-lTrimIndex+1] = NULL_CHARACTER;
    fflush(stdin);
    retorno = novaString;
    return retorno;
}
