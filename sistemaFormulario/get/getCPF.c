// Importação das bibliotecas utilizadas no arquivo
#include<stdio.h> // printf()
#include<string.h> // strcpy()

// Inclui o cabeçalho com todos os cabeçalhos dos métodos utilizados no programa
#include "../../headers/headers_programa.h"

// definição das cores utilizadas neste método
#define VERMELHO_CLARO 12


const char* getCPF(const int tamanhoCPF, const int ajusteTamanhoStr){
    // Inicialização das variáveis
    char CPF[tamanhoCPF+ajusteTamanhoStr];
    int validaCPF;
    const char* retorno;

    do{ // Loop
        printf("\nCPF: ");
        // recebe o valor do CPF do método trimEspacosEmBrancoGetS e armazena dentro da variável CPF
        strcpy(CPF, trimEspacosEmBrancoGetS(tamanhoCPF+ajusteTamanhoStr));
        // valida se o CPF com tamanho correto, contém apenas números, digito verificador conforme cálculo e se este CPF já não foi cadastrado
        validaCPF = validacaoCPF(CPF, tamanhoCPF);
        /*
            Caso o CPF esteja inválido receberá um número diferente de zero
            e informa ao usuário de acordo
        */
        if(validaCPF != 0){
            printfColorido("\nCPF inválido, apenas numeros com digito verificador válido, tente novamente\n", VERMELHO_CLARO);
        }
    }while(validaCPF != 0); // repete o loop de obter um novo CPF enquanto este estiver inválido
    retorno = CPF;
    // retorna o CPF inserido após validado
    return retorno;
}
