// Importação das bibliotecas utilizadas no arquivo
#include<string.h> // strcmp() strlwr()

// Inclui o cabeçalho com todos os cabeçalhos dos métodos utilizados no programa
#include "../../headers/headers_programa.h"

int avaliaPessoaDoGrupoDeRisco(const char* dataNascimento, const char* comorbidades){

    /*
        Método que avalia e se o paciente for do grupo de risco:
        maiores de 65 OU com comorbidades
    */
    int idade = calculaIdade(dataNascimento); // Calcula a idade a partir da data de nascimento

    /*
        Caso o paciente tenha 65 anos ou menos
        E não possua comorbidades
        retorna -1 por não pertencer ao grupo de risco
        retorna a idade caso faça parte
    */

    if(idade <= 65 && (strcmp(comorbidades, "") == 0 || strcmp(strlwr(comorbidades), "nao") == 0 || strcmp(strlwr(comorbidades), "não") == 0)){
        return -1;
    }
    return idade;
}
