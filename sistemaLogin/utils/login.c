// Importa��o das bibliotecas utilizadas no arquivo
#include<stdio.h> //fopen()feof() fgets() fclose()
#include<stdlib.h> // exit()
#include<string.h> // strcmp()

// Inclui o cabe�alho com todos os cabe�alhos dos m�todos utilizados no programa
#include "../../headers/headers_programa.h"

// define constante para facilitar a leitura
#define NULL_CHARACTER '\0'

// defini��o das cores utilizadas neste m�todo
#define VERMELHO_CLARO 12

int login(const char* user, const int tamanhoMaxUsuario, const char* password, const int tamanhoMaxSenha){
    // Inicializa��o das vari�veis
    FILE* pArquivo; // ponteiro para um arquivo
    char usuario[tamanhoMaxUsuario];
    char senha[tamanhoMaxSenha];
    int retorno = 1; // retorno come�a com 1 = erro

    pArquivo = fopen("./arquivos/entrada/login.txt", "r"); // tenta abrir o arquivo no local informado, modo de leitura

    /*
    Caso o arquivo n�o seja encontrado, pArquivo valer� NULL
    */
    if(pArquivo == NULL){
        printfColorido("\nErro ao tentar abrir arquivo, contate o administrador\n", VERMELHO_CLARO);
        // Como n�o � poss�vel continuar a execu��o do programa sem ler o arquivo onde est� o usuario/senha, finaliza o programa
        exit(-1);
    }

    while(!feof(pArquivo)){ // Varre o arquivo at� o fim
        fgets(usuario, tamanhoMaxUsuario, pArquivo); // varre a linha onde est� o usu�rio, armazenando o valor em usuario
        usuario[strlen(usuario)-1] = NULL_CHARACTER; // substitui a quebra de linha pelo character \0
        fgets(senha, tamanhoMaxSenha, pArquivo); // varre a linha onde est� a senha, armazenando o valor em senha
        senha[strlen(senha)] = NULL_CHARACTER; // substitui a quebra de linha pelo character \0

        if(strcmp(user, usuario)==0 && strcmp(password, senha)==0){ // compara se o usuario e senha informados s�o v�lidos
            retorno = 0; // atribui 0 = OK para a vari�vel retorno
            break; // interrompe a execu��o do Loop While
        }
    }

    fclose(pArquivo); // Fecha a conex�o com o arquivo

    return retorno; // retorna o valor atual da vari�vel retorno

}
