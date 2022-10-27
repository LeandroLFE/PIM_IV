#include<locale.h>
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

    int lTrimIndex = -1;

    fgets(stringInicial, tamanhoMaxUsuario, stdin);

    stringInicial[strlen(stringInicial)-1] = NULL_CHARACTER;

    int rTrimIndex = strlen(stringInicial);

    if(strcmp(stringInicial, "")==0){
        return "";
    }

    for(int i=0; i<strlen(stringInicial); i++){
        if(stringInicial[i] != ESPACO){
            break;
        }
        lTrimIndex = i;
    }

    if(lTrimIndex+1 == rTrimIndex){
        return "";
    }

    for(int i=rTrimIndex-1; i>=lTrimIndex+1; i--){
        if(stringInicial[i] != ESPACO){
            break;
        }
        rTrimIndex = i;
    }

    if(lTrimIndex+1>=rTrimIndex){
        return "";
    }

    for(int i=lTrimIndex+1; i<rTrimIndex; i++){
        novaString[i-lTrimIndex-1] = stringInicial[i];
    }
    novaString[rTrimIndex-(lTrimIndex+1)] = NULL_CHARACTER;
    retorno = novaString;
    fflush(stdin);
    return retorno;
}
