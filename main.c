#include<stdio.h>
#include<stdlib.h>
#include <locale.h>

#include "headers/headers_programa.h"

#define TAMANHO_MAX_USUARIO 15
#define TAMANHO_MAX_SENHA 15

#define TAMANHO_MAX_NOME 52
#define TAMANHO_MAX_RUA 152
#define TAMANHO_MAX_NUMERO 6
#define TAMANHO_MAX_BAIRRO_CIDADE 102
#define TAMANHO_MAX_COMPLEMENTO 72


//cores
#define CIANO 3
#define VERMELHO_CLARO 12
#define BRANCO 15

int main(void){
    int login;
    int formulario = 1;

    setlocale(LC_ALL, "portuguese");
    setColor(BRANCO);

    do{
        login = sistemaLogin(TAMANHO_MAX_USUARIO, TAMANHO_MAX_SENHA);

        printfColorido("\n\nLogin realizado com sucesso!\n\n", CIANO);

        formulario = sistemaFormulario(TAMANHO_MAX_NOME, TAMANHO_MAX_RUA, TAMANHO_MAX_NUMERO,
                                       TAMANHO_MAX_COMPLEMENTO, TAMANHO_MAX_BAIRRO_CIDADE, 50, 50);

    }while(formulario==1);

    return 0;
}
