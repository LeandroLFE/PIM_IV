#include<conio.h>
#include<stdio.h>
#include<stdlib.h>
#include<windows.h>


#define BACKSPACE 8
#define CTRLC 3
#define ENTER 13
#define NULL_CHARACTER '\0'


const char* getSenha(const int tamanhoMaxSenha){
    char senha[tamanhoMaxSenha+1];
    char caracterSenhaAtual = 0;
    const char *retorno;

    printf("\nInforme sua senha: ");
    senha[0] = NULL_CHARACTER;
    for(int indiceSenha=0; indiceSenha<tamanhoMaxSenha && caracterSenhaAtual != ENTER && caracterSenhaAtual != CTRLC; indiceSenha++){
        caracterSenhaAtual = _getch();
        senha[indiceSenha+1] = NULL_CHARACTER;
        if(caracterSenhaAtual != ENTER && caracterSenhaAtual != BACKSPACE && caracterSenhaAtual != CTRLC){
            if(indiceSenha + 1 == tamanhoMaxSenha){
                indiceSenha--;
                Beep(400, 1);
                continue;
            } else{
                senha[indiceSenha] = caracterSenhaAtual;
                _putch('*');
                continue;
            }
        }
        else if(caracterSenhaAtual == BACKSPACE){
            senha[indiceSenha] = NULL_CHARACTER;
            indiceSenha--;
            if(indiceSenha>=0){
                _putch(BACKSPACE);
                _putch(NULL_CHARACTER);
                _putch(BACKSPACE);
                indiceSenha--;
            } else{
                _putch(NULL_CHARACTER);
                _putch(BACKSPACE);
                Beep(400, 1);
            }
        } else if(caracterSenhaAtual == CTRLC){
            printf("\n\nAbortando programa......\n");
            exit(1);
        }
    }
    retorno = senha;
    return retorno;
}
