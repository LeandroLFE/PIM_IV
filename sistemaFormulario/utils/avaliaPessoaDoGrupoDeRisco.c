// Importa��o das bibliotecas utilizadas no arquivo
#include<string.h> // strcmp() strlwr()

int avaliaPessoaDoGrupoDeRisco(const char* dataNascimento, const char* comorbidades){

    /*
        M�todo que avalia e se o paciente for do grupo de risco:
        maiores de 65 com comorbidades
    */
    int idade = calculaIdade(dataNascimento); // Calcula a idade a partir da data de nascimento

    /*
        Caso o paciente tenha 65 anos ou menos
        Ou n�o possua comorbidades
        retorna -1 por n�o pertencer ao grupo de risco
        retorna a idade caso fa�a parte
    */

    if(idade <= 65 || strcmp(comorbidades, "") == 0 || strcmp(strlwr(comorbidades), "nao") == 0 || strcmp(strlwr(comorbidades), "n�o") == 0){
        return -1;
    }
    return idade;
}
