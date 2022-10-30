// Importação das bibliotecas utilizadas no arquivo
#include<stdio.h> // printf()
#include<string.h> // strcpy() strlwr()

// Inclui o cabeçalho com todos os cabeçalhos dos métodos utilizados no programa
#include "../../headers/headers_programa.h"

// definição das cores utilizadas neste método
#define VERMELHO_CLARO 12


const char* getEmail(const int tamanhoMaxEmail, const int ajusteTamanhoStr){
    // Inicialização das variáveis
    char email[tamanhoMaxEmail+ajusteTamanhoStr];
    const char* retorno;
    int validaEmail;
    do{ // Loop
        printf("\nEmail: ");
        // recebe o valor do email do método trimEspacosEmBrancoGetS e armazena dentro da variável email
        strcpy(email, trimEspacosEmBrancoGetS(tamanhoMaxEmail+ajusteTamanhoStr));
        // valida se o email está no formato texto@texto.texto(.textoAlternativo)
        validaEmail = validacaoEmail(strlwr(email), tamanhoMaxEmail);
        // Caso seja um email inválido, informa ao usuário de acordo
        if(validaEmail != 0){
            printfColorido("\nEmail inválido, formato: texto@texto.texto(.textoAlternativo), tente novamente\n", VERMELHO_CLARO);
        }
    }while(validaEmail != 0); // repete o loop caso email esteja inválido
    retorno = email;
    // retorna o email inserido após validado
    return retorno;
}
