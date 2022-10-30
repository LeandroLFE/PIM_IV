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
            switch(validaEmail){
            case 1: case 2: case 3:
                printfColorido("\nEmail inválido antes do @. É permitido texto começado e terminado com letras/números", VERMELHO_CLARO);
                printfColorido("\nEntre elas pode conter characteres especiais como: { #, !, %, ', &, +, *, -, /, =, ?, ^, `, ., {, |, }, ~, $ }", VERMELHO_CLARO);
                printfColorido("\nTente novamente\n", VERMELHO_CLARO);
                break;
            case 4:
                printfColorido("\nEmail inválido, ou '@' não encontrado ou não possui mais characteres disponíveis após o '@'. Tente novamente\n", VERMELHO_CLARO);
                break;
            case 5: case 6:
                printfColorido("\nEmail inválido no texto após o '@'. É permitido apenas letras. Tente novamente\n", VERMELHO_CLARO);
                break;
            case 7:
                printfColorido("\nEmail inválido, ponto '.' não encontrado no texto após o @, tente novamente\n", VERMELHO_CLARO);
                break;
            case 8:
                printfColorido("\nEmail inválido, não encontrado texto após o '.'. Tente novamente\n", VERMELHO_CLARO);
                break;
            case 9:
                printfColorido("\nEmail inválido no texto após o ponto '.'. É permitido apenas letras, opcionalmente pode conter um segundo ponto '.'. Tente novamente\n", VERMELHO_CLARO);
                break;
            case 10: case 11:
                printfColorido("\nEmail inválido no texto após o segundo ponto '.'. É permitido apenas letras. Tente novamente\n", VERMELHO_CLARO);
                break;
            default:
                printfColorido("\nEmail inválido, formato: texto@texto.texto(.textoAlternativo), tente novamente\n", VERMELHO_CLARO);
            }
        }
    }while(validaEmail != 0); // repete o loop caso email esteja inválido
    retorno = strlwr(email);
    // retorna o email inserido após validado
    return retorno;
}
