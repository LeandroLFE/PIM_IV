#include<stdio.h>
#include<string.h>

#include "../../headers/headers_programa.h"

//cores
#define VERMELHO_CLARO 12

const char* getEmail(const int tamanhoMaxEmail, const int ajusteTamanhoStr){

    char email[tamanhoMaxEmail+ajusteTamanhoStr];
    const char* retorno;
    int validaEmail;
    do{
        printf("\nEmail: ");
        strcpy(email, trimEspacosEmBrancoGetS(tamanhoMaxEmail+ajusteTamanhoStr));
        validaEmail = validacaoEmail(strlwr(email), tamanhoMaxEmail);
        if(validaEmail != 0){
            printfColorido("\nEmail inválido, formato: texto@texto.texto(.textoAlternativo), tente novamente\n", VERMELHO_CLARO);
        }
    }while(validaEmail != 0);
    retorno = email;
    return retorno;
}
