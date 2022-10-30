// Importa��o das bibliotecas utilizadas no arquivo
#include<conio.h> // _getch() _putch()
#include<stdio.h> // printf() exit()
#include<stdlib.h>
#include<windows.h> // Beep()

// Inclui o cabe�alho com todos os cabe�alhos dos m�todos utilizados no programa
#include "../../headers/headers_programa.h"


// define constantes para facilitar a leitura dos characteres
#define BACKSPACE 8
#define CTRLC 3
#define ENTER 13
#define NULL_CHARACTER '\0'

// defini��o das cores utilizadas neste m�todo
#define VERMELHO_CLARO 12


const char* getSenha(const int tamanhoMaxSenha){
    // Inicializa��o das vari�veis
    char senha[tamanhoMaxSenha+1]; // adiciona mais 1 character � senha para realizar a opera��o da linha 33
    char caracterSenhaAtual = 0;
    const char *retorno;

    printf("\nInforme sua senha: ");
    senha[0] = NULL_CHARACTER;

    // Loop para inser��o da senha
    for(int indiceSenha=0; indiceSenha<tamanhoMaxSenha && caracterSenhaAtual != ENTER && caracterSenhaAtual != CTRLC; indiceSenha++){
        caracterSenhaAtual = _getch(); // Leitura silenciosa de um character, armazenando na vari�vel characterSenhaAtual
        senha[indiceSenha+1] = NULL_CHARACTER; // Inclui um character de finaliza��o da string uma posi��o ap�s o character inserido
        /*
            verifica se o character informado n�o � ENTER, BACKSPACE OU CTRLC
        */
        if(caracterSenhaAtual != ENTER && caracterSenhaAtual != BACKSPACE && caracterSenhaAtual != CTRLC){
            // verifica se n�o � poss�vel adicionar mais letras � senha
            if(indiceSenha + 1 == tamanhoMaxSenha){
                // subtrai 1 do �ndice
                indiceSenha--;
                // faz um pequeno Beep
                Beep(400, 1);
                // continua o Loop
                continue;
            } else{
                // adiciona character � senha
                senha[indiceSenha] = caracterSenhaAtual;
                // apresenta um * para o usu�rio
                _putch('*');
                // continua o Loop
                continue;
            }
        }
        /*
            caso o character seja um BACKSPACE
        */
        else if(caracterSenhaAtual == BACKSPACE){
            senha[indiceSenha] = NULL_CHARACTER; // substitui o character da senha atual por um \0
            indiceSenha--; // reduz 1 do �ndice da senha
            /*
                Caso o �ndice da senha n�o seja menor do que 0
            */
            if(indiceSenha>=0){
                // Inser��o de um BACKSPACE mo terminal
                _putch(BACKSPACE);
                _putch(NULL_CHARACTER);
                _putch(BACKSPACE);
                // reduz mais 1 do �ndice
                indiceSenha--;
            } else{
                // Como o indice � menor do que 0, n�o h� o primeiro BACKSPACE
                _putch(NULL_CHARACTER);
                _putch(BACKSPACE);
                // aviso sonoro para o usu�rio
                Beep(400, 1);
            }
        /*
            Caso o character seja CTRL + C
        */
        } else if(caracterSenhaAtual == CTRLC){
            printfColorido("\n\nAbortando programa......\n\n", VERMELHO_CLARO);
            // finaliza a execu��o do programa
            exit(1);
        }
    }
    retorno = senha;
    // Retorna a senha informada na vari�vel retorno
    return retorno;
}
