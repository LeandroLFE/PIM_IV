#include<stdio.h>
#include<string.h>
#include <windows.h>

#include "../headers/headers_programa.h"

//cores
#define VERMELHO_CLARO 12
#define BRANCO 15

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
        printf("\n**************LOGIN*****************");
        printf("\n************************************\n");

        strcpy(auxUsuario, getUsuario(tamanhoMaxUsuario));
        usuario = auxUsuario;

        strcpy(auxSenha, getSenha(tamanhoMaxSenha));
        senha = auxSenha;

        resultadoLogin = login(usuario, tamanhoMaxUsuario, senha, tamanhoMaxSenha);
        if(resultadoLogin != 0){
            printfColorido("\n\nUsuario/Senha invalidos, tente novamente\n\n", VERMELHO_CLARO);
            Sleep(500);
            clearScreen(hStdout);
        }
    }while(resultadoLogin != 0);

    return 0;
}

