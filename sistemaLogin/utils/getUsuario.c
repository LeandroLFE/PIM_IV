// Importação das bibliotecas utilizadas no arquivo
#include<locale.h> // setlocale()
#include<stdio.h> // printf()
#include<string.h> // strcpy() strcmp()

// Inclui o cabeçalho com todos os cabeçalhos dos métodos utilizados no programa
#include "../../headers/headers_programa.h"

// definição das cores utilizadas neste método
#define VERMELHO_CLARO 12


const char* getUsuario(const int tamanhoMaxUsuario){
    // Inicialização das variávevis
    char usuario[tamanhoMaxUsuario];
    const char* retorno;
    // Estrutura de repetição do...while para leitura do usuário
    do{
        // Altera o locale pata Português para aceitar o acento em usuário
        setlocale(LC_ALL, "Portuguese_Brazil.1252");
        // Exibe mensagem ao usuário
        printf("\n%s", "Informe seu usuário: ");
        // Altera o locale de volta para "C"
        setlocale(LC_ALL, "C");
        // recebe o valor do usuário do método trimEspacosEmBrancoGetS e armazena dentro da variável usuário
        strcpy(usuario, trimEspacosEmBrancoGetS(tamanhoMaxUsuario));
        // compara se a variável usuário vale uma string vazia
        if(strcmp(usuario, "")==0){
            printfColorido("\nUsuário não informado, tente novamente\n", VERMELHO_CLARO);
        }
    }while(strcmp(usuario, "")==0); // retorna ao início do loop caso a variável usuário esteja vazia
    retorno = usuario;
    // retorna a string usuario
    return retorno;
}
