// Importa��o das bibliotecas utilizadas no arquivo
#include<ctype.h> // isdigit()
#include<stdio.h>
#include<stdlib.h>
#include<string.h> // strlen()


int validacaoTelefone(const char* telefone, const int tamanhoTelefone){
    /*
        verifica se o tamanho do telefone informado est� de acordo com o tamanho correto,
        retorna 1 caso n�o esteja
    */
    if(strlen(telefone) != tamanhoTelefone){
        return 1;
    }
    /*
        Varre cada d�gito do telefone informado
    */
    for(int i=0; i<tamanhoTelefone; i++){
        // Caso o digito lido n�o seja um n�mero, retorna 2
        if(!isdigit(telefone[i])){
            return 2;
        }
        // Caso o DDD (�ndice 0 ou 1) contenha '0', retorna 3, porque n�o deve ter '0'
        if(i<2 && telefone[i] == '0'){
            return 3;
        }
    }

    // retorna 0 caso o telefone esteja validado
    return 0;
}
