// Importa��o das bibliotecas utilizadas no arquivo
#include<string.h> // strlen()


int validacaoNome(const char* nome){
    // Varre o nome letra por letra
    for(int i=0; i<strlen(nome); i++){
        // verifica se cont�m alggum n�mero de 0 a 9 em alguma letra
        if(nome[i]>='0' && nome[i]<='9'){
            return 1; // retorna 1 caso contenha n�meros (erro)
        }
    }
    return 0; // retorna 0 caso n�o contenha n�meros (OK)
}
