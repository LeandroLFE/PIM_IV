// Importa��o das bibliotecas utilizadas no arquivo
#include<ctype.h> // isdigit()
#include<stdio.h>
#include<stdlib.h>
#include<string.h> // strlen()

// Inclui o cabe�alho com todos os cabe�alhos dos m�todos utilizados no programa
#include "../../headers/headers_programa.h"


int validacaoDataNascimento(const char* dataNascimento, const int tamanhoData){
    /*
        verifica se o tamanho da data de nascimento informada est� de acordo com o tamanho correto,
        retorna -1 caso n�o esteja
    */
    if(strlen(dataNascimento) != tamanhoData){
        return -1;
    }

    // Varre a data de nascimento informada digito a digito
    for(int i=0; i<tamanhoData; i++){
        // Caso o digito lido n�o seja um n�mero, retorna -2
        if(!isdigit(dataNascimento[i])){
            return -2;
        }
    }
    // Retorna um n�mero positivo com a idade da data informada ou um n�mero negativo caso invalidada
    return calculaIdade(dataNascimento);
}
