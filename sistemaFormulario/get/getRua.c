// Importação das bibliotecas utilizadas no arquivo
#include<stdio.h> // printf()
#include<string.h> // strcpy() strcmp()

// Inclui o cabeçalho com todos os cabeçalhos dos métodos utilizados no programav
#include "../../headers/headers_programa.h"

// definição das cores utilizadas neste método
#define VERMELHO_CLARO 12


const char* getRua(const int tamanhoMaxRua){
    // Inicialização das variáveis
    char rua[tamanhoMaxRua];
    const char* retorno;
    do{ // Loop
        printf("\nRua: ");
        // recebe o valor da rua do método trimEspacosEmBrancoGetS e armazena dentro da variável rua
        strcpy(rua, trimEspacosEmBrancoGetS(tamanhoMaxRua));
         /* Caso a rua não tenha sido informada, informa o usuario de acordo */
        if(strcmp(rua, "")==0){
            printfColorido("\nRua não informada, tente novamente\n", VERMELHO_CLARO);
        }
    }while(strcmp(rua, "")==0); // repete o loop até que seja informada uma rua
    retorno = rua;
    // retorna a rua inserida
    return retorno;
}
