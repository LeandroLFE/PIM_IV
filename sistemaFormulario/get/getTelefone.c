// Importação das bibliotecas utilizadas no arquivo
#include<stdio.h> // printf()
#include<string.h> // strcpy()

// Inclui o cabeçalho com todos os cabeçalhos dos métodos utilizados no programa
#include "../../headers/headers_programa.h"

// definição das cores utilizadas neste método
#define VERMELHO_CLARO 12


const char* getTelefone(const int tamanhoTelefone, const int ajusteTamanhoStr){
    // Inicialização das variáveis
    char telefone[tamanhoTelefone+ajusteTamanhoStr];
    const char* retorno;
    int validaTelefone;
    do{ // Loop
        printf("\nTelefone: ");
        // recebe o valor do telefone do método trimEspacosEmBrancoGetS e armazena dentro da variável telefone
        strcpy(telefone, trimEspacosEmBrancoGetS(tamanhoTelefone+ajusteTamanhoStr));
        // valida se o telefone está do tamanho correto, contém apenas números e não contém 0 no DDD de 2 dígitos
        validaTelefone = validacaoTelefone(telefone, tamanhoTelefone);
        /*
            Caso o telefone esteja inválido receberá um número diferente de zero
            e informa ao usuário de acordo
        */
        if(validaTelefone != 0){
            printfColorido("\nTelefone inválido, formato: DDD com 2 digitos + XXXXXXXXX, tente novamente\n", VERMELHO_CLARO);
        }
    }while(validaTelefone != 0); // repete o loop de obter um novo telefone enquanto este estiver inválido
    retorno = telefone;
    // retorna o telefone inserido após validado
    return retorno;
}
