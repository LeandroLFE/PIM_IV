// Inclui o cabe�alho com todos os cabe�alhos dos m�todos utilizados no programa
#include<locale.h> //setlocale
#include<stdio.h> // fopen() fprint() fputc() fclose()
#include<stdlib.h> // itoa()
#include<string.h> // strcmp() strcat()

// Inclui o cabe�alho com todos os cabe�alhos dos m�todos utilizados no programa
#include "../../headers/headers_programa.h"

// defini��o das cores utilizadas neste m�todo
#define CIANO 3


int salvarArquivoGrupoDeRisco(const char* cpf, const char* cep, const char* dataNascimento, const char* comorbidades){

    /*
        M�todo que avalia e salva se o paciente for do grupo de risco:
        maiores de 65 com comorbidades
    */

    char idadeTexto[5]; //vari�vvel para armazenar a idade em texto
    int idade = calculaIdade(dataNascimento); // Calcula a idade a partir da data de nascimento

    /*
        Caso o paciente tenha 65 anos ou menos
        Ou n�o possua comorbidades
        retorna 1 para o sistema saber que n�o foi salvo,
        mas tamb�m n�o � um erro
    */
    if(idade <= 65 || strcmp(comorbidades, "") == 0 || strcmp(strlwr(comorbidades), "nao") == 0 || strcmp(strlwr(comorbidades), "n�o") == 0){
        return 1;
    }


    FILE* pArquivo = NULL; // ponteiro para o arquivo
    char nomeArquivo[50] = "./arquivos/saida/grupo_de_risco/"; // montagem do nome do arquivo: local onde ser� salvo
    strcat(nomeArquivo, cpf); // montagem do nome do arquivo: nome do arquivo (cpf)
    strcat(nomeArquivo, ".txt"); // montagem do nome do arquivo: extens�o (.txt)

    // Caso o programa tenha chegado at� aqui � garantido que o paciente � do grupo de risco,
    // informa ao usu�rio
    printfColorido("\nSalvando Paciente do Grupo de Risco....\n", CIANO);

    pArquivo = fopen(nomeArquivo, "w"); // abre o arquivo em modo de grava��o

    // caso o arquivo n�o tenha sido aberto por algum motivo,
    // o ponteiro retornar� NULL, ent�o retorna -1 para saber que foi um erro ( < 0)
    if(pArquivo == NULL){
        return -1;
    }

    // converte idade para texto em formato decimal
    itoa(idade, idadeTexto, 10);

    // escreve o CEP ao arquivo
    fprintf(pArquivo, cep);

    // insere uma quebra de linha '\n'
    fputc('\n', pArquivo);

    // insere a idade convertida em texto no arquivo
    fprintf(pArquivo, idadeTexto);

    // fecha a conex�o com o arquivo
    fclose(pArquivo);

    // retorna 0 para o sistema saber que foi salvo com sucesso
    return 0;
}
