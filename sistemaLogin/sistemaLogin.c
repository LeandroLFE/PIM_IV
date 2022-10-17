#include<stdio.h>
#include<stdlib.h>
#include <windows.h>

#include "../headers/headers_programa.h"

int sistemaLogin(const int tamanhoMaxUsuario, const int tamanhoMaxSenha){
    const char* usuario;
    const char* senha;
    int resultadoLogin;
    do{
        system("cls");
        printf("************************************");
        printf("\n*******BEM VINDO AO SISTEMA*********");
        printf("\n************************************\n");

        usuario = getUsuario(tamanhoMaxUsuario);
        senha = getSenha(tamanhoMaxSenha);
        resultadoLogin = login(usuario, tamanhoMaxUsuario, senha, tamanhoMaxSenha);

        if(resultadoLogin != 0){
            printf("\n\nUsuario/Senha invalidos, tente novamente\n\n");
            Sleep(450);
        }
    }while(resultadoLogin != 0);

    return 0;
}
