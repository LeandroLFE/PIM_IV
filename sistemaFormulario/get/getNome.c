// Importação das bibliotecas utilizadas no arquivo
#include<stdio.h> // printf()
#include<string.h> // strcpy() strcmp()

// Inclui o cabeçalho com todos os cabeçalhos dos métodos utilizados no programa
#include "../../headers/headers_programa.h"

// definição das cores utilizadas neste método
#define VERMELHO_CLARO 12


const char* getNome(const int tamanhoMaxNome){
    // Inicialização das variáveis
    char nome[tamanhoMaxNome];
    const char* retorno;
    int validaNome = 1;

    do{ // Loop
        printf("\nNome: ");
        // recebe o valor do nome do método trimEspacosEmBrancoGetS e armazena dentro da variável nome
        strcpy(nome, trimEspacosEmBrancoGetS(tamanhoMaxNome));
        /* Caso o nome esteja vazio */
        if(strcmp(nome, "")==0){
            printfColorido("\nNome não informado, tente novamente\n", VERMELHO_CLARO);
        }
        // valida se o nome não contém números
        validaNome = validacaoNome(nome);
        // Caso contenha números, informa ao usuário de acordo
        if(validaNome != 0){
            printfColorido("\nNome inválido, não pode conter números, tente novamente\n", VERMELHO_CLARO);
        }
    }while(strcmp(nome, "")==0 || validaNome != 0); // repete o loop caso nome esteja inválido

    retorno = nome;
    // retorna o nome inserido após validado
    return retorno;
}
