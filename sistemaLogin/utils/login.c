#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#include "../../headers/headers_programa.h"

#define NULL_CHARACTER '\0'

int login(char* user, const int tamanhoMaxUsuario, char* password, const int tamanhoMaxSenha){
    FILE* pArquivo;
    char usuario[tamanhoMaxUsuario];
    char senha[tamanhoMaxSenha];
    int retorno = 1;

    pArquivo = fopen("./arquivos/entrada/login.txt", "r");

    if(pArquivo == NULL){
        printf("\n%sErro ao tentar abrir arquivo, contate o administrador%s\n", colorir('v'), colorir('r'));
        exit(-1);
    }

    while(!feof(pArquivo)){
        fgets(usuario, tamanhoMaxUsuario, pArquivo);
        usuario[strlen(usuario)-1] = NULL_CHARACTER;
        fgets(senha, tamanhoMaxSenha, pArquivo);
        senha[strlen(senha)] = NULL_CHARACTER;

        if(strcmp(user, usuario)==0 && strcmp(password, senha)==0){
            retorno = 0;
            break;
        }
    }

    fclose(pArquivo);

    return retorno;

}
