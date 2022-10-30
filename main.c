// Importação das bibliotecas utilizadas no arquivo
#include<locale.h> // setlocale()
#include<stdio.h>
#include<stdlib.h>

// Inclui o cabeçalho com todos os cabeçalhos dos métodos utilizados no programa
#include "headers/headers_programa.h"


// definição do tamanho máximo dos campos que possuem máximo
#define TAMANHO_MAX_USUARIO 15
#define TAMANHO_MAX_SENHA 15

#define TAMANHO_MAX_COMORBIDADES 102
#define TAMANHO_MAX_EMAIL 66
#define TAMANHO_MAX_NOME 52
#define TAMANHO_MAX_RUA 152
#define TAMANHO_MAX_NUMERO 6
#define TAMANHO_MAX_BAIRRO_CIDADE 102
#define TAMANHO_MAX_COMPLEMENTO 72


//definição das cores utilizadas neste método
#define CIANO 3
#define VERMELHO_CLARO 12
#define BRANCO 15

int main(void){
    int formulario = 1;
    setlocale(LC_ALL, "C"); // Altera o locale para "C"
    setColor(BRANCO); // altera a cor da fonte do console para Branco

    do{
        sistemaLogin(TAMANHO_MAX_USUARIO, TAMANHO_MAX_SENHA); // Realiza o login

        printfColorido("\n\nLogin realizado com sucesso!\n\n", CIANO); // Avisa o usuário que o Login foi realizado com sucesso

        formulario = sistemaFormulario(TAMANHO_MAX_NOME, TAMANHO_MAX_RUA, TAMANHO_MAX_NUMERO,
                                       TAMANHO_MAX_COMPLEMENTO, TAMANHO_MAX_BAIRRO_CIDADE,
                                       TAMANHO_MAX_EMAIL, TAMANHO_MAX_COMORBIDADES); // Vai para o formulário

    }while(formulario==1); // Condição para continuar o Loop

    return 0;
}
