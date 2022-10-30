// Importação das bibliotecas utilizadas no arquivo
#include<stdio.h> // fflush() printf()
#include<string.h> // strcpy()
#include <windows.h> // Sleep()

// Inclui o cabeçalho com todos os cabeçalhos dos métodos utilizados no programa
#include "../headers/headers_programa.h"

// definição das cores utilizadas neste método
#define VERDE 2
#define VERMELHO_CLARO 12
#define BRANCO 15

int sistemaLogin(const int tamanhoMaxUsuario, const int tamanhoMaxSenha){
    // Inicialização das variáveis
    char auxUsuario[tamanhoMaxUsuario];
    const char* usuario;
    char auxSenha[tamanhoMaxSenha];
    const char* senha;
    int resultadoLogin;

    do{
        clearScreen(); // método clearScreen externo
        fflush(stdin); // limpeza do buffer de entrada
        setColor(VERDE); // altera a cor da fonte do terminal para VERDE com o método setColor externo
        printf("************************************");
        printf("\n*******BEM VINDO AO SISTEMA*********");
        printf("\n**************LOGIN*****************");
        printf("\n************************************\n");
        setColor(BRANCO); // altera a cor da fonte do terminal para BRANCO com o método setColor externo

        strcpy(auxUsuario, getUsuario(tamanhoMaxUsuario)); // recebe usuario e armazena em auxUsuario
        usuario = auxUsuario; // insere o valor do usuário informado para a variável const char* usuário

        strcpy(auxSenha, getSenha(tamanhoMaxSenha)); // recebe a senha e armazena em auxSenha
        senha = auxSenha; // insere o valor da senha informada para a variável const char* senha

        resultadoLogin = login(usuario, tamanhoMaxUsuario, senha, tamanhoMaxSenha); // Tenta realizar o Login
        /*
        Caso usuario/senha inválido
        */
        if(resultadoLogin != 0){
            printfColorido("\n\nUsuário/Senha inválidos, tente novamente\n\n", VERMELHO_CLARO);
            Sleep(500); // aguarda 0,5s para a mensagem poder ser lida antes do clearScreen
        }
    }while(resultadoLogin != 0); // repete o loop caso usuario/senha inválidos

    return 0;
}

