#include<ctype.h>
#include<math.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

const int validacaoNumero(const char* textoNumero, const int tamanhoMaxNumero){
    int numero;

    if(strlen(textoNumero) < 1 || strlen(textoNumero) > tamanhoMaxNumero){
        return -1;
    }

    for(int i=0; i<strlen(textoNumero); i++){
        if(!isdigit(textoNumero[i])){
            return -2;
        }
    }

    numero = atoi(textoNumero);

    if(numero < 1 || numero >= pow(10, tamanhoMaxNumero)){
        return -3;
    }

    return numero;
}
