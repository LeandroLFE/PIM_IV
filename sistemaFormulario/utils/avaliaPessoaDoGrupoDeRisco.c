// Importa��o das bibliotecas utilizadas no arquivo
#include<string.h> // strcmp() strlwr()

// Inclui o cabe�alho com todos os cabe�alhos dos m�todos utilizados no programa
#include "../../headers/headers_programa.h"

int avaliaPessoaDoGrupoDeRisco(const char* dataNascimento, const char* comorbidades){

    /*
        M�todo que avalia e se o paciente for do grupo de risco:
        maiores de 65 OU com comorbidades
    */
    int idade = calculaIdade(dataNascimento); // Calcula a idade a partir da data de nascimento

    /*
        Caso o paciente tenha 65 anos ou menos
        E n�o possua comorbidades
        retorna -1 por n�o pertencer ao grupo de risco
        retorna a idade caso fa�a parte
    */

    if(idade <= 65 && (strcmp(comorbidades, "") == 0 || strcmp(strlwr(comorbidades), "nao") == 0 || strcmp(strlwr(comorbidades), "n�o") == 0)){
        return -1;
    }
    return idade;
}
