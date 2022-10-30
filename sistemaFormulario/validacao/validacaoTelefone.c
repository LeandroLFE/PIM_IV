// Importação das bibliotecas utilizadas no arquivo
#include<ctype.h> // isdigit()
#include<stdio.h>
#include<stdlib.h>
#include<string.h> // strlen()


int validacaoTelefone(const char* telefone, const int tamanhoTelefone){
    /*
        verifica se o tamanho do telefone informado está de acordo com o tamanho correto,
        retorna 1 caso não esteja
    */
    if(strlen(telefone) != tamanhoTelefone){
        return 1;
    }
    /*
        Varre cada dígito do telefone informado
    */
    for(int i=0; i<tamanhoTelefone; i++){
        // Caso o digito lido não seja um número, retorna 2
        if(!isdigit(telefone[i])){
            return 2;
        }
        // Caso o DDD (índice 0 ou 1) contenha '0', retorna 3, porque não deve ter '0'
        if(i<2 && telefone[i] == '0'){
            return 3;
        }
    }

    // retorna 0 caso o telefone esteja validado
    return 0;
}
