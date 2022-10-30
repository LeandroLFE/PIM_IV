// Importa��o das bibliotecas utilizadas no arquivo
#include<ctype.h> //isdigit()
#include<stdio.h>
#include<stdlib.h> // itoa()
#include<string.h> // strlen()

// Inclui o cabe�alho com todos os cabe�alhos dos m�todos utilizados no programa
#include "../../headers/headers_programa.h"


int validacaoCPF(const char* CPF, const int tamanhoCPF){
    // Inicializa��o das vari�veis
    int digito1;
    int digito2;
    int somaDigito1 = 0;
    int somaDigito2 = 0;
    int restoDivisaoDigito1;
    int restoDivisaoDigito2;
    char digitoComparador1[2];
    char digitoComparador2[2];

    // verifica se o tamanho do CPF informado est� de acordo com o tamanho correto,
    // retorna 1 caso n�o esteja
    if(strlen(CPF) != tamanhoCPF){
        return 1;
    }

    /*
        C�lculo do d�gito verificador do CPF:

        - 1� d�gito: (somat�rio dos 9 primeiros d�gitos * os n�meros de 10 at� 2) % 11
        - 2� d�gito: (somat�rio dos 10 primeiros d�gitos * os n�meros de 11 at� 2) % 11

        Caso o resto da divis�o seja 0 ou 1, ent�o este ser� o d�gito,
        Caso contr�rio, o d�gito ser� 11 - resto_da_divis�o
    */

    // Varre cada d�gito do CPF informado
    for(int i=0, j=10, k = 11, digitoNumerico=0; i<tamanhoCPF; i++, j--, k--){
        // Caso o n�mero lido n�o seja um n�mero, retorna 2
        if(!isdigit(CPF[i])){
            return 2;
        }
        // Realiza o somat�rio do 1� ao 9� d�gito para os digitos 1 e 2
        else if(i< tamanhoCPF - 2){
            digitoNumerico = (int)CPF[i]-'0'; // converte o character informado para n�mero, subtraindo na tabela ASCII
            somaDigito1+= digitoNumerico*j; // somat�rio do d�gito 1 * (10 ... 2)
            somaDigito2+= digitoNumerico*k; // somat�rio do d�gito 2 * (11 ....3)
        }
        // Acrescenta o 10� d�gito para a conta do somat�rio do digito 2
        else if(i< tamanhoCPF - 1){
            digitoNumerico = (int)CPF[i]-'0'; // converte o character informado para n�mero, subtraindo na tabela ASCII
            somaDigito2+= digitoNumerico*k; // somat�rio do d�gito 2 * 2
        }
    }

    restoDivisaoDigito1 = somaDigito1 % tamanhoCPF; // calcula o resto da divis�o inteira do somat�rio1 pelo tamanho do CPF
    /*
        Caso o resto seja 0 ou 1, o digito ser� 0,
         Caso contr�rio, o d�gito ser� o tamanho do CPF - resto_da_divis�o
    */
    if(restoDivisaoDigito1 < 2){
        digito1 = 0;
    } else{
        digito1 = tamanhoCPF - restoDivisaoDigito1;
    }

    restoDivisaoDigito2 = somaDigito2 % tamanhoCPF; // calcula o resto da divis�o inteira do somat�rio1 pelo tamanho do CPF
    /*
        Caso o resto seja 0 ou 1, o digito ser� 0,
         Caso contr�rio, o d�gito ser� o tamanho do CPF - resto_da_divis�o
    */
    if(restoDivisaoDigito2 < 2){
        digito2 = 0;
    } else{
        digito2 = tamanhoCPF - restoDivisaoDigito2;
    }

    itoa(digito1, digitoComparador1, 10); //Converte o d�gito 1 num�rico para texto
    itoa(digito2, digitoComparador2, 10); //Converte o d�gito 2 num�rico para texto

    /*
        Compara os d�gitos do CPF informado vs o Calculado, retorna 3 caso n�o sejam iguais
    */
    if(digitoComparador1[0] != CPF[tamanhoCPF-2] || digitoComparador2[0] != CPF[tamanhoCPF-1]){
        return 3;
    }

    /*
        Verifica se j� existe um arquivo com este CPF, caso tenha, retorna o erro 4
    */
    if(verificaSeArquivoJaExiste(CPF) != 0){
        return 4;
    }

    // retorna 0 caso o CPF esteja validado
    return 0;
}
