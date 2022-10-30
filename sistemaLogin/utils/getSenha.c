// Importação das bibliotecas utilizadas no arquivo
#include<conio.h> // _getch() _putch()
#include<stdio.h> // printf() exit()
#include<stdlib.h>
#include<windows.h> // Beep()

// Inclui o cabeçalho com todos os cabeçalhos dos métodos utilizados no programa
#include "../../headers/headers_programa.h"


// define constantes para facilitar a leitura dos characteres
#define BACKSPACE 8
#define CTRLC 3
#define ENTER 13
#define NULL_CHARACTER '\0'

// definição das cores utilizadas neste método
#define VERMELHO_CLARO 12


const char* getSenha(const int tamanhoMaxSenha){
    // Inicialização das variáveis
    char senha[tamanhoMaxSenha+1]; // adiciona mais 1 character à senha para realizar a operação da linha 33
    char caracterSenhaAtual = 0;
    const char *retorno;

    printf("\nInforme sua senha: ");
    senha[0] = NULL_CHARACTER;

    // Loop para inserção da senha
    for(int indiceSenha=0; indiceSenha<tamanhoMaxSenha && caracterSenhaAtual != ENTER && caracterSenhaAtual != CTRLC; indiceSenha++){
        caracterSenhaAtual = _getch(); // Leitura silenciosa de um character, armazenando na variável characterSenhaAtual
        senha[indiceSenha+1] = NULL_CHARACTER; // Inclui um character de finalização da string uma posição após o character inserido
        /*
            verifica se o character informado não é ENTER, BACKSPACE OU CTRLC
        */
        if(caracterSenhaAtual != ENTER && caracterSenhaAtual != BACKSPACE && caracterSenhaAtual != CTRLC){
            // verifica se não é possível adicionar mais letras à senha
            if(indiceSenha + 1 == tamanhoMaxSenha){
                // subtrai 1 do índice
                indiceSenha--;
                // faz um pequeno Beep
                Beep(400, 1);
                // continua o Loop
                continue;
            } else{
                // adiciona character à senha
                senha[indiceSenha] = caracterSenhaAtual;
                // apresenta um * para o usuário
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
            indiceSenha--; // reduz 1 do índice da senha
            /*
                Caso o índice da senha não seja menor do que 0
            */
            if(indiceSenha>=0){
                // Inserção de um BACKSPACE mo terminal
                _putch(BACKSPACE);
                _putch(NULL_CHARACTER);
                _putch(BACKSPACE);
                // reduz mais 1 do índice
                indiceSenha--;
            } else{
                // Como o indice é menor do que 0, não há o primeiro BACKSPACE
                _putch(NULL_CHARACTER);
                _putch(BACKSPACE);
                // aviso sonoro para o usuário
                Beep(400, 1);
            }
        /*
            Caso o character seja CTRL + C
        */
        } else if(caracterSenhaAtual == CTRLC){
            printfColorido("\n\nAbortando programa......\n\n", VERMELHO_CLARO);
            // finaliza a execução do programa
            exit(1);
        }
    }
    retorno = senha;
    // Retorna a senha informada na variável retorno
    return retorno;
}
