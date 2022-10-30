// Importa��o das bibliotecas utilizadas no arquivo
#include<stdio.h> // printf()
#include<string.h> // strcpy() strlwr()

// Inclui o cabe�alho com todos os cabe�alhos dos m�todos utilizados no programa
#include "../../headers/headers_programa.h"

// defini��o das cores utilizadas neste m�todo
#define VERMELHO_CLARO 12


const char* getEmail(const int tamanhoMaxEmail, const int ajusteTamanhoStr){
    // Inicializa��o das vari�veis
    char email[tamanhoMaxEmail+ajusteTamanhoStr];
    const char* retorno;
    int validaEmail;
    do{ // Loop
        printf("\nEmail: ");
        // recebe o valor do email do m�todo trimEspacosEmBrancoGetS e armazena dentro da vari�vel email
        strcpy(email, trimEspacosEmBrancoGetS(tamanhoMaxEmail+ajusteTamanhoStr));
        // valida se o email est� no formato texto@texto.texto(.textoAlternativo)
        validaEmail = validacaoEmail(strlwr(email), tamanhoMaxEmail);
        // Caso seja um email inv�lido, informa ao usu�rio de acordo
        if(validaEmail != 0){
            printfColorido("\nEmail inv�lido, formato: texto@texto.texto(.textoAlternativo), tente novamente\n", VERMELHO_CLARO);
        }
    }while(validaEmail != 0); // repete o loop caso email esteja inv�lido
    retorno = email;
    // retorna o email inserido ap�s validado
    return retorno;
}
