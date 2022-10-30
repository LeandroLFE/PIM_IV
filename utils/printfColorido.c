// Importação das bibliotecas utilizadas no arquivo
#include<locale.h> //setlocale()
#include<stdio.h> // printf()

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


void printfColorido(const char* texto, int cor){
    /*
        método para realizar um printf decorado com alguma cor escolhida conforme tabela acima
    */

    setlocale(LC_ALL, "Portuguese_Brazil.1252"); // como o texto pode conter acentos, converte o texto para encoding windows 1252
    setColor(cor); // modifica a cor do terminal através do método externo setColor
    printf("%s", texto); // imprime o texto com a cor desejada
    setColor(BRANCO); // retorna a cor para o padrão do projeto, branco
    setlocale(LC_ALL, "C"); // modifica o locale de volta para "C"
}
