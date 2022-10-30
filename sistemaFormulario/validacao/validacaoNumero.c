// Importação das bibliotecas utilizadas no arquivo
#include<ctype.h> // isdigit()
#include<math.h> // pow()
#include<stdlib.h> // atoi()
#include<string.h> // strlen()


const int validacaoNumero(const char* textoNumero, const int tamanhoMaxNumero){
    // Declaracao da variavel numero que conterá o valor número do textoNumero
    int numero;

    // caso textoNumero esteja vazio ou com mais de um determinado numero de digitos, retorna -1
    if(strlen(textoNumero) < 1 || strlen(textoNumero) > tamanhoMaxNumero){
        return -1;
    }

    // varre o textoNumero digito a digito
    for(int i=0; i<strlen(textoNumero); i++){
        // Caso o digito lido não seja um número, retorna -2
        if(!isdigit(textoNumero[i])){
            return -2;
        }
    }
    // Converte o textoNumero para numero (int)
    numero = atoi(textoNumero);

    // caso o numero seja < 1 ou >= 10**tamanhoMaxNumero, retorna -3
    if(numero < 1 || numero >= pow(10, tamanhoMaxNumero)){
        return -3;
    }

    // retorna o textoNumero convertido para numero inteiro
    return numero;
}
