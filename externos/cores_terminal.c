#include<stdio.h>
#include <windows.h>

#include "../headers/headers_programa.h"


 void setColor(int ForgC){
     /*
        Método externo para setar a cor do terminal do codeblocks no windows, retirado do site
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
