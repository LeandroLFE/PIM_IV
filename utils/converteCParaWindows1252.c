// Importação das bibliotecas utilizadas no arquivo
#include<string.h> // strlen()

const char* converteCParaWindows1252(const char* entrada){
    /*
        Método que converte acentos de encoding "C" para o encoding "Windows 1252",
        utilizando conversão do representante numerico de cada letra com acento
    */

    //Inicialização das variáveis
    char auxEntrada[strlen(entrada)];
    const char* retorno;
    int i = 0;

    // varre o texto de entrada letra a letra
    // até encontrar uma quebra de linha '\n' = 10
    // ou o character nulo '\0' = 0
    for(; entrada[i] != 10 && entrada[i] != 0;i++){
        // alimenta a string auxEntrada com cada letra da string de entrada
        auxEntrada[i] = entrada[i];
        switch(entrada[i]){
        /*
            Caso encontre uma letra que corresponda a um acento no encoding "C",
            substitui pelo correspondente no encoding "windows 1252"
        */
        case -128: // Ç
            auxEntrada[i] = -57;
            break;

        case -127: // ü
            auxEntrada[i] = -4;
            break;

        case -126: // é
            auxEntrada[i] = -23;
            break;

        case -123: // à
            auxEntrada[i] = -32;
            break;

        case -121: // ç
            auxEntrada[i] = -25;
            break;

        case -120: // ê
            auxEntrada[i] = -22;
            break;

        case -112: // É
            auxEntrada[i] = -55;
            break;

        case -109: // ô
            auxEntrada[i] = -12;
            break;

        case -102: // Ü
            auxEntrada[i] = -36;
            break;

        case -96: // á
            auxEntrada[i] = -31;
            break;

        case -95: // í
            auxEntrada[i] = -19;
            break;

        case -94: // ó
            auxEntrada[i] = -13;
            break;

        case -93: // ú
            auxEntrada[i] = -6;
            break;

        case -75: // Á
            auxEntrada[i] = -63;
            break;

        case -73: // À
            auxEntrada[i] = -64;
            break;

        case -58: // ã
            auxEntrada[i] = -29;
            break;

        case -57: // Ã
            auxEntrada[i] = -61;
            break;

        case -46: // Ê
            auxEntrada[i] = -54;
            break;

        case -42: // Í
            auxEntrada[i] = -51;
            break;

        case -32: // Ó
            auxEntrada[i] = -45;
            break;

        case -30: // Ô
            auxEntrada[i] = -44;
            break;

        case -28: // õ
            auxEntrada[i] = -11;
            break;

        case -27: // Õ
            auxEntrada[i] = -43;
            break;

        case -23: // Ú
            auxEntrada[i] = -38;
            break;
        }
    }
    // Adiciona o character nulo ao final da string
    auxEntrada[i] = 0;

    retorno = auxEntrada;
    // retorna string com acentos convertidos
    return retorno;

}

