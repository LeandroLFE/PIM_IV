// Importação das bibliotecas utilizadas no arquivo
#include<stdio.h> //fopen()feof() fgets() fclose()
#include<stdlib.h> // exit()
#include<string.h> // strcmp()

// Inclui o cabeçalho com todos os cabeçalhos dos métodos utilizados no programa
#include "../../headers/headers_programa.h"

// define constante para facilitar a leitura
#define NULL_CHARACTER '\0'

// definição das cores utilizadas neste método
#define VERMELHO_CLARO 12

int login(const char* user, const int tamanhoMaxUsuario, const char* password, const int tamanhoMaxSenha){
    // Inicialização das variáveis
    FILE* pArquivo; // ponteiro para um arquivo
    char usuario[tamanhoMaxUsuario];
    char senha[tamanhoMaxSenha];
    int retorno = 1; // retorno começa com 1 = erro

    pArquivo = fopen("./arquivos/entrada/login.txt", "r"); // tenta abrir o arquivo no local informado, modo de leitura

    /*
    Caso o arquivo não seja encontrado, pArquivo valerá NULL
    */
    if(pArquivo == NULL){
        printfColorido("\nErro ao tentar abrir arquivo, contate o administrador\n", VERMELHO_CLARO);
        // Como não é possível continuar a execução do programa sem ler o arquivo onde está o usuario/senha, finaliza o programa
        exit(-1);
    }

    while(!feof(pArquivo)){ // Varre o arquivo até o fim
        fgets(usuario, tamanhoMaxUsuario, pArquivo); // varre a linha onde está o usuário, armazenando o valor em usuario
        usuario[strlen(usuario)-1] = NULL_CHARACTER; // substitui a quebra de linha pelo character \0
        fgets(senha, tamanhoMaxSenha, pArquivo); // varre a linha onde está a senha, armazenando o valor em senha
        senha[strlen(senha)] = NULL_CHARACTER; // substitui a quebra de linha pelo character \0

        if(strcmp(user, usuario)==0 && strcmp(password, senha)==0){ // compara se o usuario e senha informados são válidos
            retorno = 0; // atribui 0 = OK para a variável retorno
            break; // interrompe a execução do Loop While
        }
    }

    fclose(pArquivo); // Fecha a conexão com o arquivo

    return retorno; // retorna o valor atual da variável retorno

}
