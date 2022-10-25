#include<stdio.h>
#include<string.h>

#define NULL_CHARACTER '\0'
#define PULA_LINHA 10
#define ENTER 13
#define ESPACO 32

const char* trimEspacosEmBrancoGetS(const int tamanhoMaxUsuario){
    char stringInicial[tamanhoMaxUsuario];
    char novaString[tamanhoMaxUsuario];
    const char* retorno;

    int lTrimIndex = 0;

    fgets(stringInicial, tamanhoMaxUsuario, stdin);

    stringInicial[strlen(stringInicial)-1] = NULL_CHARACTER;

    int rTrimIndex = strlen(stringInicial);

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

    for(int i=rTrimIndex-1; i>=lTrimIndex; i--){
        if(stringInicial[i] != ESPACO){
            rTrimIndex = i+1;
            break;
        }
    }

    if(lTrimIndex>=rTrimIndex){
        return "";
    }

    for(int i=lTrimIndex; i<rTrimIndex; i++){
        novaString[i-lTrimIndex] = stringInicial[i];
    }
    novaString[rTrimIndex-lTrimIndex] = NULL_CHARACTER;
    fflush(stdin);
    retorno = novaString;
    return retorno;
}
