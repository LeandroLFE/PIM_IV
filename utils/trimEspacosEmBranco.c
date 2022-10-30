// Importação das bibliotecas utilizadas no arquivo
#include<stdio.h> // fgets() fflush()
#include<string.h> // strlen()

// define constantes para facilitar a leitura dos characteres
#define NULL_CHARACTER '\0'
#define PULA_LINHA 10
#define ENTER 13
#define ESPACO 32


const char* trimEspacosEmBrancoGetS(const int tamanhoMaxUsuario){
    // Inicialização das variáveis
    char stringInicial[tamanhoMaxUsuario];
    char novaString[tamanhoMaxUsuario];
    const char* retorno;
    int lTrimIndex = -1;
    int rTrimIndex;

    // Leitura de uma variável do tipo string
    fgets(stringInicial, tamanhoMaxUsuario, stdin);

    // substitui \n por \0
    stringInicial[strlen(stringInicial)-1] = NULL_CHARACTER;

    rTrimIndex = strlen(stringInicial);

    // verifica se a string inicial já não se encontrava vazia desde o início
    if(strcmp(stringInicial, "")==0){
        return "";
    }

    // varre a string inicial para marcar onde se encontra o primeiro character
    for(int i=0; i<strlen(stringInicial); i++){
        if(stringInicial[i] != ESPACO){
            break;
        }
        lTrimIndex = i;
    }

    // verifica se por acaso a string inteira era composta apenas por espaços
    if(lTrimIndex+1 == rTrimIndex){
        return "";
    }

    // varre a string inicial para marcar onde se encontra o último character
    for(int i=rTrimIndex-1; i>=lTrimIndex+1; i--){
        if(stringInicial[i] != ESPACO){
            break;
        }
        rTrimIndex = i;
    }

    // cria uma nova string a partir dos índices marcados
    for(int i=lTrimIndex+1; i<rTrimIndex; i++){
        novaString[i-lTrimIndex-1] = stringInicial[i];
    }

    // acrescenta o caracter nulo '\0' ao final da string
    novaString[rTrimIndex-(lTrimIndex+1)] = NULL_CHARACTER;
    // converte a novaString para const char*
    retorno = novaString;
    // limpeza do buffer de entrada (windows)
    fflush(stdin);
    return retorno;
}
