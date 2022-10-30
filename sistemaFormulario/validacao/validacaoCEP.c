// definição das cores utilizadas neste método
#include<ctype.h> // isdigit()
#include<stdio.h>
#include<stdlib.h>
#include<string.h> // strlen()


int validacaoCEP(const char* CEP, const int tamanhoCEP){
    /*
        verifica se o tamanho do CEP informado está de acordo com o tamanho correto,
        retorna 1 caso não esteja
    */
    if(strlen(CEP) != tamanhoCEP){
        return 1;
    }
    /*
        Varre cada dígito do CEP informado
    */
    for(int i=0; i<tamanhoCEP; i++){
        // Caso o digito lido não seja um número, retorna 2
        if(!isdigit(CEP[i])){
            return 2;
        }
    }

    // retorna 0 caso o CEP esteja validado
    return 0;
}
