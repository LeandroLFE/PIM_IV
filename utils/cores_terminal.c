#include<stdio.h>
#include <windows.h>

#include "../headers/headers_programa.h"


// Tabela de cores
#define PRETO 0
#define AZUL 1
#define VERDE 2
#define CIANO 3
#define VERMELHO 4
#define MAGENTA 5
#define MARROM 6
#define CINZA_CLARO 7
#define CINZA_ESCURO 8
#define AZUL_CLARO 9
#define VERDE_CLARO 10
#define CIANO_CLARO 11
#define VERMELHO_CLARO 12
#define MAGENTA_CLARO 13
#define AMARELO 14
#define BRANCO 15


 void setColor(int ForgC){
     /*
        https://www.codewithc.com/change-text-color-in-codeblocks-console-window/
     */

     WORD wColor;
     //This handle is needed to get the current background attribute

     HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
     CONSOLE_SCREEN_BUFFER_INFO csbi;
     //csbi is used for wAttributes word

     if(GetConsoleScreenBufferInfo(hStdOut, &csbi))
     {
          //To mask out all but the background attribute, and to add the color
          wColor = (csbi.wAttributes & 0xF0) + (ForgC & 0x0F);
          SetConsoleTextAttribute(hStdOut, wColor);
     }
}
