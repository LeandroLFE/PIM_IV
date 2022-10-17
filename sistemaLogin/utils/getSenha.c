#include<stdio.h>
#include<stdlib.h>
#include<conio.h>

#define ENTER 13
#define BACKSPACE 8
#define CTRLC 3
#define NULL_CHARACTER '\0'


const char* getSenha(const int tamanhoMaxSenha){
    char senha[tamanhoMaxSenha];
    char caracterSenhaAtual = 0;
    const char *retorno;
    int indiceSenha;

    printf("\nInforme sua senha: ");
    for(indiceSenha=0; indiceSenha<tamanhoMaxSenha && caracterSenhaAtual != ENTER && caracterSenhaAtual != CTRLC; indiceSenha++){
        caracterSenhaAtual = getch();
        if(caracterSenhaAtual != ENTER && caracterSenhaAtual != BACKSPACE && caracterSenhaAtual != CTRLC){
            senha[indiceSenha] = caracterSenhaAtual;
            putch('*');
            if(indiceSenha + 1 == tamanhoMaxSenha){
                printf("\nTamanho maximo da senha atingido, a senha ira ate aqui\n");
            }
        }
        if(caracterSenhaAtual == BACKSPACE && indiceSenha>0){
            putch(BACKSPACE);
            putch(NULL_CHARACTER);
            putch(BACKSPACE);
            indiceSenha-=2;
        } else if(caracterSenhaAtual == BACKSPACE && indiceSenha<=0){
            indiceSenha--;
        } else if(caracterSenhaAtual == CTRLC){
            printf("\n\nAbortando programa......\n");
            exit(1);
        }
    }
    senha[indiceSenha-1] = NULL_CHARACTER;
    retorno = senha;
    return retorno;
}
