#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int validacaoEstado(const char* estado, const int tamanhoEstado){

    const char* lista_estados[] = {"AC","AL","AP","AM","BA","CE","DF","ES","GO",
                                "MA","MT","MS","MG","PA","PB","PR","PE","PI",
                                "RJ","RN","RS","RO","RR","SC","SP","SE","TO"};

    int tamanho_lista = sizeof(lista_estados)/sizeof(lista_estados[0]);

    if(strlen(estado) != tamanhoEstado){
        return 1;
    }
    for(int i=0; i<tamanho_lista; i++){
        if(strcmp(estado, lista_estados[i]) == 0){
            return 0;
        }
    }
    return 2;
}
