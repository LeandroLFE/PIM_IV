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
            switch(validaEmail){
            case 1: case 2: case 3:
                printfColorido("\nEmail inv�lido antes do @. � permitido texto come�ado e terminado com letras/n�meros", VERMELHO_CLARO);
                printfColorido("\nEntre elas pode conter characteres especiais como: { #, !, %, ', &, +, *, -, /, =, ?, ^, `, ., {, |, }, ~, $ }", VERMELHO_CLARO);
                printfColorido("\nTente novamente\n", VERMELHO_CLARO);
                break;
            case 4:
                printfColorido("\nEmail inv�lido, ou '@' n�o encontrado ou n�o possui mais characteres dispon�veis ap�s o '@'. Tente novamente\n", VERMELHO_CLARO);
                break;
            case 5: case 6:
                printfColorido("\nEmail inv�lido no texto ap�s o '@'. � permitido apenas letras. Tente novamente\n", VERMELHO_CLARO);
                break;
            case 7:
                printfColorido("\nEmail inv�lido, ponto '.' n�o encontrado no texto ap�s o @, tente novamente\n", VERMELHO_CLARO);
                break;
            case 8:
                printfColorido("\nEmail inv�lido, n�o encontrado texto ap�s o '.'. Tente novamente\n", VERMELHO_CLARO);
                break;
            case 9:
                printfColorido("\nEmail inv�lido no texto ap�s o ponto '.'. � permitido apenas letras, opcionalmente pode conter um segundo ponto '.'. Tente novamente\n", VERMELHO_CLARO);
                break;
            case 10: case 11:
                printfColorido("\nEmail inv�lido no texto ap�s o segundo ponto '.'. � permitido apenas letras. Tente novamente\n", VERMELHO_CLARO);
                break;
            default:
                printfColorido("\nEmail inv�lido, formato: texto@texto.texto(.textoAlternativo), tente novamente\n", VERMELHO_CLARO);
            }
        }
    }while(validaEmail != 0); // repete o loop caso email esteja inv�lido
    retorno = strlwr(email);
    // retorna o email inserido ap�s validado
    return retorno;
}
