#include<locale.h>
#include<stdio.h>

#define BRANCO 15


void printfColorido(const char* texto, int cor){

    setlocale(LC_ALL, "Portuguese_Brazil.1252");
    setColor(cor);
    printf("%s", texto);
    setColor(BRANCO);
    setlocale(LC_ALL, "C");
}
