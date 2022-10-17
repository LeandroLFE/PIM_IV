#include<stdio.h>
#include<string.h>
#include <windows.h>

#include "../headers/headers_programa.h"

int sistemaLogin(const int tamanhoMaxUsuario, const int tamanhoMaxSenha){
    char auxUsuario[tamanhoMaxUsuario];
    const char* usuario;
    char auxSenha[tamanhoMaxSenha];
    const char* senha;
    int resultadoLogin;
    HANDLE hStdout;

    hStdout = GetStdHandle(STD_OUTPUT_HANDLE);

    do{
        printf("************************************");
        printf("\n*******BEM VINDO AO SISTEMA*********");
        printf("\n************************************\n");

        strcpy(auxUsuario, getUsuario(tamanhoMaxUsuario));
        usuario = auxUsuario;

        strcpy(auxSenha, getSenha(tamanhoMaxSenha));
        senha = auxSenha;

        resultadoLogin = login(usuario, tamanhoMaxUsuario, senha, tamanhoMaxSenha);
        if(resultadoLogin != 0){
            printf("\n\nUsuario/Senha invalidos, tente novamente\n\n");
            Sleep(450);
            clearScreen(hStdout);
        }
    }while(resultadoLogin != 0);

    return 0;
}

