// Importa��o das bibliotecas utilizadas no arquivo
#include<string.h> // strlen()

const char* converteCParaWindows1252(const char* entrada){
    /*
        M�todo que converte acentos de encoding "C" para o encoding "Windows 1252",
        utilizando convers�o do representante numerico de cada letra com acento
    */

    //Inicializa��o das vari�veis
    char auxEntrada[strlen(entrada)];
    const char* retorno;
    int i = 0;

    // varre o texto de entrada letra a letra
    // at� encontrar uma quebra de linha '\n' = 10
    // ou o character nulo '\0' = 0
    for(; entrada[i] != 10 && entrada[i] != 0;i++){
        // alimenta a string auxEntrada com cada letra da string de entrada
        auxEntrada[i] = entrada[i];
        switch(entrada[i]){
        /*
            Caso encontre uma letra que corresponda a um acento no encoding "C",
            substitui pelo correspondente no encoding "windows 1252"
        */
        case -128: // �
            auxEntrada[i] = -57;
            break;

        case -127: // �
            auxEntrada[i] = -4;
            break;

        case -126: // �
            auxEntrada[i] = -23;
            break;

        case -123: // �
            auxEntrada[i] = -32;
            break;

        case -121: // �
            auxEntrada[i] = -25;
            break;

        case -120: // �
            auxEntrada[i] = -22;
            break;

        case -112: // �
            auxEntrada[i] = -55;
            break;

        case -109: // �
            auxEntrada[i] = -12;
            break;

        case -102: // �
            auxEntrada[i] = -36;
            break;

        case -96: // �
            auxEntrada[i] = -31;
            break;

        case -95: // �
            auxEntrada[i] = -19;
            break;

        case -94: // �
            auxEntrada[i] = -13;
            break;

        case -93: // �
            auxEntrada[i] = -6;
            break;

        case -75: // �
            auxEntrada[i] = -63;
            break;

        case -73: // �
            auxEntrada[i] = -64;
            break;

        case -58: // �
            auxEntrada[i] = -29;
            break;

        case -57: // �
            auxEntrada[i] = -61;
            break;

        case -46: // �
            auxEntrada[i] = -54;
            break;

        case -42: // �
            auxEntrada[i] = -51;
            break;

        case -32: // �
            auxEntrada[i] = -45;
            break;

        case -30: // �
            auxEntrada[i] = -44;
            break;

        case -28: // �
            auxEntrada[i] = -11;
            break;

        case -27: // �
            auxEntrada[i] = -43;
            break;

        case -23: // �
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

