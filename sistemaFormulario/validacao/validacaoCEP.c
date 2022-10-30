// defini��o das cores utilizadas neste m�todo
#include<ctype.h> // isdigit()
#include<stdio.h>
#include<stdlib.h>
#include<string.h> // strlen()


int validacaoCEP(const char* CEP, const int tamanhoCEP){
    /*
        verifica se o tamanho do CEP informado est� de acordo com o tamanho correto,
        retorna 1 caso n�o esteja
    */
    if(strlen(CEP) != tamanhoCEP){
        return 1;
    }
    /*
        Varre cada d�gito do CEP informado
    */
    for(int i=0; i<tamanhoCEP; i++){
        // Caso o digito lido n�o seja um n�mero, retorna 2
        if(!isdigit(CEP[i])){
            return 2;
        }
    }

    // retorna 0 caso o CEP esteja validado
    return 0;
}
