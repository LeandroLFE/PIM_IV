// Importação das bibliotecas utilizadas no arquivo
#include<ctype.h> // isdigit()
#include<stdio.h>
#include<stdlib.h>
#include<string.h> // strlen()

// Inclui o cabeçalho com todos os cabeçalhos dos métodos utilizados no programa
#include "../../headers/headers_programa.h"


int verificaDataDiagnosticoNaoInferiorADataNascimento(const char* dataDiagnostico, const char* dataNascimento){
    //Inicialização das variáveis

    //converte o dia/mes/ano da data de diagnostico em variaveis separadas
    long diaDiagnostico = (dataDiagnostico[0]-'0')*10 + (dataDiagnostico[1]-'0');
    long mesDiagnostico = (dataDiagnostico[2]-'0')*10 + (dataDiagnostico[3]-'0');
    long anoDiagnostico = (dataDiagnostico[4]-'0')*1000 + (dataDiagnostico[5]-'0')*100 + (dataDiagnostico[6]-'0')*10 + (dataDiagnostico[7]-'0');

    //converte o dia/mes/ano da data de nascimento em variaveis separadas
    long diaNascimento = (dataNascimento[0]-'0')*10 + (dataNascimento[1]-'0');
    long mesNascimento = (dataNascimento[2]-'0')*10 + (dataNascimento[3]-'0');
    long anoNascimento = (dataNascimento[4]-'0')*1000 + (dataNascimento[5]-'0')*100 + (dataNascimento[6]-'0')*10 + (dataNascimento[7]-'0');

    // verifica se data de diagnostico < data de nascimento, retornando 1 neste caso, gerando uma falha na validação
    if( anoDiagnostico < anoNascimento || (anoDiagnostico == anoNascimento && mesDiagnostico < mesNascimento)
       || (anoDiagnostico == anoNascimento && mesDiagnostico == mesNascimento && diaDiagnostico < diaNascimento)){
        return 1;
    }

    // retorna 0 caso a data de diagnostico esteja válida
    return 0;
}


int validacaoDataDiagnostico(const char* dataDiagnostico, const int tamanhoData, const char* dataNascimento){
    int idade;
    /*
        verifica se o tamanho da data de diagnostico informada está de acordo com o tamanho correto,
        retorna -1 caso não esteja
    */
    if(strlen(dataDiagnostico) != tamanhoData){
        return -1;
    }
     // Varre a data de diagnostico informada digito a digito
    for(int i=0; i<tamanhoData; i++){
        // Caso o digito lido não seja um número, retorna -2
        if(!isdigit(dataDiagnostico[i])){
            return -2;
        }
    }
    // Valida a data informada, utilizando o método calculaIdade
    idade = calculaIdade(dataDiagnostico);

    /*
        caso o retorno for um numero negativo, retorna o numero (de -3 a -6)
    */
    if(idade < 0 ){
        return idade;
    }

    /*
        caso a data de diagnostico informada seja inferior a data de nascimento, retorna -7
    */
    if(verificaDataDiagnosticoNaoInferiorADataNascimento(dataDiagnostico, dataNascimento) != 0){
        return -7;
    }

    // retorna um numero positivo >=0 na variável idade caso validada
    return idade;
}
