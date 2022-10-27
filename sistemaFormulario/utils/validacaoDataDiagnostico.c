#include<ctype.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#include "../../headers/headers_programa.h"


int validacaoDataDiagnostico(const char* dataDiagnostico, const int tamanhoData, const char* dataNascimento){
    int idade;

    if(strlen(dataDiagnostico) != tamanhoData){
        return -1;
    }
    for(int i=0; i<tamanhoData; i++){
        if(!isdigit(dataDiagnostico[i])){
            return -2;
        }
    }

    idade = calculaIdade(dataDiagnostico);

    if(idade < 0 ){
        return idade;
    }

    long diaDiagnostico = (dataDiagnostico[0]-'0')*10 + (dataDiagnostico[1]-'0');
    long mesDiagnostico = (dataDiagnostico[2]-'0')*10 + (dataDiagnostico[3]-'0');
    long anoDiagnostico = (dataDiagnostico[4]-'0')*1000 + (dataDiagnostico[5]-'0')*100 + (dataDiagnostico[6]-'0')*10 + (dataDiagnostico[7]-'0');

    long diaNascimento = (dataNascimento[0]-'0')*10 + (dataNascimento[1]-'0');
    long mesNascimento = (dataNascimento[2]-'0')*10 + (dataNascimento[3]-'0');
    long anoNascimento = (dataNascimento[4]-'0')*1000 + (dataNascimento[5]-'0')*100 + (dataNascimento[6]-'0')*10 + (dataNascimento[7]-'0');

    if( anoDiagnostico < anoNascimento || (anoDiagnostico == anoNascimento && mesDiagnostico < mesNascimento)
       || (anoDiagnostico == anoNascimento && mesDiagnostico == mesNascimento && diaDiagnostico < diaNascimento)){
        return -7;
    }

    return idade;
}
