// Importação das bibliotecas utilizadas no arquivo
#include<string.h> //strlen() strcmp()


int validacaoEstado(const char* estado, const int tamanhoEstado){

    //Inicialização das variáveis
    const char* lista_estados[] = {"AC","AL","AP","AM","BA","CE","DF","ES","GO",
                                "MA","MT","MS","MG","PA","PB","PR","PE","PI",
                                "RJ","RN","RS","RO","RR","SC","SP","SE","TO"}; // Lista com as siglas dos 26 estados brasileiros + DF

    // obtem tamanho da lista matematicamente, através do método sizeof
    /*
        o método sizeof retorna o tamanho de uma variável * a quantidade de elementos caso seja um array,
        neste caso, para obter o tamanho da lista divide-se o tamanho da lista inteiro pelo tamanho de 1 elemento
    */
    int tamanho_lista = sizeof(lista_estados)/sizeof(lista_estados[0]);

    // verifica se o tamanho do estado informado está de acordo com o tamanho correto (2),
    // retorna 1 caso não esteja
    if(strlen(estado) != tamanhoEstado){
        return 1;
    }

    // Varre a lista de estados previamente feita
    for(int i=0; i<tamanho_lista; i++){
        /*
            verifica se existe um estado com texto igual ao estado informado,
            retorna 0 caso encontre
        */
        if(strcmp(estado, lista_estados[i]) == 0){
            return 0;
        }
    }

    // Retorna 2 caso o estado informado não tenha sido encontrado na lista
    return 2;
}
