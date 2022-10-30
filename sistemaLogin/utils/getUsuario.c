// Importa��o das bibliotecas utilizadas no arquivo
#include<locale.h> // setlocale()
#include<stdio.h> // printf()
#include<string.h> // strcpy() strcmp()

// Inclui o cabe�alho com todos os cabe�alhos dos m�todos utilizados no programa
#include "../../headers/headers_programa.h"

// defini��o das cores utilizadas neste m�todo
#define VERMELHO_CLARO 12


const char* getUsuario(const int tamanhoMaxUsuario){
    // Inicializa��o das vari�vevis
    char usuario[tamanhoMaxUsuario];
    const char* retorno;
    // Estrutura de repeti��o do...while para leitura do usu�rio
    do{
        // Altera o locale pata Portugu�s para aceitar o acento em usu�rio
        setlocale(LC_ALL, "Portuguese_Brazil.1252");
        // Exibe mensagem ao usu�rio
        printf("\n%s", "Informe seu usu�rio: ");
        // Altera o locale de volta para "C"
        setlocale(LC_ALL, "C");
        // recebe o valor do usu�rio do m�todo trimEspacosEmBrancoGetS e armazena dentro da vari�vel usu�rio
        strcpy(usuario, trimEspacosEmBrancoGetS(tamanhoMaxUsuario));
        // compara se a vari�vel usu�rio vale uma string vazia
        if(strcmp(usuario, "")==0){
            printfColorido("\nUsu�rio n�o informado, tente novamente\n", VERMELHO_CLARO);
        }
    }while(strcmp(usuario, "")==0); // retorna ao in�cio do loop caso a vari�vel usu�rio esteja vazia
    retorno = usuario;
    // retorna a string usuario
    return retorno;
}
