// Importa��o das bibliotecas utilizadas no arquivo
#include<stdio.h> // fflush() printf()
#include<string.h> // strcpy()
#include <windows.h> // Sleep()

// Inclui o cabe�alho com todos os cabe�alhos dos m�todos utilizados no programa
#include "../headers/headers_programa.h"

// defini��o das cores utilizadas neste m�todo
#define VERDE 2
#define VERMELHO_CLARO 12
#define BRANCO 15

int sistemaLogin(const int tamanhoMaxUsuario, const int tamanhoMaxSenha){
    // Inicializa��o das vari�veis
    char auxUsuario[tamanhoMaxUsuario];
    const char* usuario;
    char auxSenha[tamanhoMaxSenha];
    const char* senha;
    int resultadoLogin;

    do{
        clearScreen(); // m�todo clearScreen externo
        fflush(stdin); // limpeza do buffer de entrada
        setColor(VERDE); // altera a cor da fonte do terminal para VERDE com o m�todo setColor externo
        printf("************************************");
        printf("\n*******BEM VINDO AO SISTEMA*********");
        printf("\n**************LOGIN*****************");
        printf("\n************************************\n");
        setColor(BRANCO); // altera a cor da fonte do terminal para BRANCO com o m�todo setColor externo

        strcpy(auxUsuario, getUsuario(tamanhoMaxUsuario)); // recebe usuario e armazena em auxUsuario
        usuario = auxUsuario; // insere o valor do usu�rio informado para a vari�vel const char* usu�rio

        strcpy(auxSenha, getSenha(tamanhoMaxSenha)); // recebe a senha e armazena em auxSenha
        senha = auxSenha; // insere o valor da senha informada para a vari�vel const char* senha

        resultadoLogin = login(usuario, tamanhoMaxUsuario, senha, tamanhoMaxSenha); // Tenta realizar o Login
        /*
        Caso usuario/senha inv�lido
        */
        if(resultadoLogin != 0){
            printfColorido("\n\nUsu�rio/Senha inv�lidos, tente novamente\n\n", VERMELHO_CLARO);
            Sleep(500); // aguarda 0,5s para a mensagem poder ser lida antes do clearScreen
        }
    }while(resultadoLogin != 0); // repete o loop caso usuario/senha inv�lidos

    return 0;
}

