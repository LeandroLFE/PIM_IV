// Importação das bibliotecas utilizadas no arquivo
#include<ctype.h> //isdigit()
#include<stdio.h>
#include<stdlib.h> // itoa()
#include<string.h> // strlen()

// Inclui o cabeçalho com todos os cabeçalhos dos métodos utilizados no programa
#include "../../headers/headers_programa.h"


int validacaoCPF(const char* CPF, const int tamanhoCPF){
    // Inicialização das variáveis
    int digito1;
    int digito2;
    int somaDigito1 = 0;
    int somaDigito2 = 0;
    int restoDivisaoDigito1;
    int restoDivisaoDigito2;
    char digitoComparador1[2];
    char digitoComparador2[2];

    // verifica se o tamanho do CPF informado está de acordo com o tamanho correto,
    // retorna 1 caso não esteja
    if(strlen(CPF) != tamanhoCPF){
        return 1;
    }

    /*
        Cálculo do dígito verificador do CPF:

        - 1º dígito: (somatório dos 9 primeiros dígitos * os números de 10 até 2) % 11
        - 2º dígito: (somatório dos 10 primeiros dígitos * os números de 11 até 2) % 11

        Caso o resto da divisão seja 0 ou 1, então este será o dígito,
        Caso contrário, o dígito será 11 - resto_da_divisão
    */

    // Varre cada dígito do CPF informado
    for(int i=0, j=10, k = 11, digitoNumerico=0; i<tamanhoCPF; i++, j--, k--){
        // Caso o número lido não seja um número, retorna 2
        if(!isdigit(CPF[i])){
            return 2;
        }
        // Realiza o somatório do 1º ao 9º dígito para os digitos 1 e 2
        else if(i< tamanhoCPF - 2){
            digitoNumerico = (int)CPF[i]-'0'; // converte o character informado para número, subtraindo na tabela ASCII
            somaDigito1+= digitoNumerico*j; // somatório do dígito 1 * (10 ... 2)
            somaDigito2+= digitoNumerico*k; // somatório do dígito 2 * (11 ....3)
        }
        // Acrescenta o 10º dígito para a conta do somatório do digito 2
        else if(i< tamanhoCPF - 1){
            digitoNumerico = (int)CPF[i]-'0'; // converte o character informado para número, subtraindo na tabela ASCII
            somaDigito2+= digitoNumerico*k; // somatório do dígito 2 * 2
        }
    }

    restoDivisaoDigito1 = somaDigito1 % tamanhoCPF; // calcula o resto da divisão inteira do somatório1 pelo tamanho do CPF
    /*
        Caso o resto seja 0 ou 1, o digito será 0,
         Caso contrário, o dígito será o tamanho do CPF - resto_da_divisão
    */
    if(restoDivisaoDigito1 < 2){
        digito1 = 0;
    } else{
        digito1 = tamanhoCPF - restoDivisaoDigito1;
    }

    restoDivisaoDigito2 = somaDigito2 % tamanhoCPF; // calcula o resto da divisão inteira do somatório1 pelo tamanho do CPF
    /*
        Caso o resto seja 0 ou 1, o digito será 0,
         Caso contrário, o dígito será o tamanho do CPF - resto_da_divisão
    */
    if(restoDivisaoDigito2 < 2){
        digito2 = 0;
    } else{
        digito2 = tamanhoCPF - restoDivisaoDigito2;
    }

    itoa(digito1, digitoComparador1, 10); //Converte o dígito 1 numérico para texto
    itoa(digito2, digitoComparador2, 10); //Converte o dígito 2 numérico para texto

    /*
        Compara os dígitos do CPF informado vs o Calculado, retorna 3 caso não sejam iguais
    */
    if(digitoComparador1[0] != CPF[tamanhoCPF-2] || digitoComparador2[0] != CPF[tamanhoCPF-1]){
        return 3;
    }

    /*
        Verifica se já existe um arquivo com este CPF, caso tenha, retorna o erro 4
    */
    if(verificaSeArquivoJaExiste(CPF) != 0){
        return 4;
    }

    // retorna 0 caso o CPF esteja validado
    return 0;
}
