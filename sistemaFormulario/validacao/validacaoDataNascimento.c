// Importação das bibliotecas utilizadas no arquivo
#include<ctype.h> // isdigit()
#include<stdio.h>
#include<stdlib.h>
#include<string.h> // strlen()

// Inclui o cabeçalho com todos os cabeçalhos dos métodos utilizados no programa
#include "../../headers/headers_programa.h"


int validacaoDataNascimento(const char* dataNascimento, const int tamanhoData){
    /*
        verifica se o tamanho da data de nascimento informada está de acordo com o tamanho correto,
        retorna -1 caso não esteja
    */
    if(strlen(dataNascimento) != tamanhoData){
        return -1;
    }

    // Varre a data de nascimento informada digito a digito
    for(int i=0; i<tamanhoData; i++){
        // Caso o digito lido não seja um número, retorna -2
        if(!isdigit(dataNascimento[i])){
            return -2;
        }
    }
    // Retorna um número positivo com a idade da data informada ou um número negativo caso invalidada
    return calculaIdade(dataNascimento);
}
