#include<ctype.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int validacaoCPF(const char* CPF, const int tamanhoCPF){
    int digito1;
    int digito2;
    int somaDigito1 = 0;
    int somaDigito2 = 0;
    int restoDivisaoDigito1;
    int restoDivisaoDigito2;
    char digitoComparador1[2];
    char digitoComparador2[2];

    if(strlen(CPF) != tamanhoCPF){
        return 1;
    }

    for(int i=0, j=10, k = 11, digitoNumerico=0; i<tamanhoCPF; i++, j--, k--){
        if(!isdigit(CPF[i])){
            return 2;
        } else if(i< tamanhoCPF - 2){
            digitoNumerico = (int)CPF[i]-48; // 48 representa 0 na tabela ASCII
            somaDigito1+= digitoNumerico*j;
            somaDigito2+= digitoNumerico*k;
        } else if(i< tamanhoCPF - 1){
            digitoNumerico = (int)CPF[i]-48;
            somaDigito2+= digitoNumerico*k;
        }
    }

    restoDivisaoDigito1 = somaDigito1 % tamanhoCPF;
    if(restoDivisaoDigito1 < 2){
        digito1 = 0;
    } else{
        digito1 = tamanhoCPF - restoDivisaoDigito1;
    }

    restoDivisaoDigito2 = somaDigito2 % tamanhoCPF;
    if(restoDivisaoDigito2 < 2){
        digito2 = 0;
    } else{
        digito2 = tamanhoCPF - restoDivisaoDigito2;
    }

    itoa(digito1, digitoComparador1, 10);
    itoa(digito2, digitoComparador2, 10);

    if(digitoComparador1[0] != CPF[tamanhoCPF-2] || digitoComparador2[0] != CPF[tamanhoCPF-1]){
        return 3;
    }

    if(verificaSeArquivoJaExiste(CPF) != 0){
        return 4;
    }

    return 0;
}
