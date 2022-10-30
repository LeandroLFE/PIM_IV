// Inclui o cabeçalho com todos os cabeçalhos dos métodos utilizados no programa
#include<locale.h> //setlocale
#include<stdio.h> // fopen() fprint() fputc() fclose()
#include<stdlib.h> // itoa()
#include<string.h> // strcmp() strcat()

// Inclui o cabeçalho com todos os cabeçalhos dos métodos utilizados no programa
#include "../../headers/headers_programa.h"

// definição das cores utilizadas neste método
#define CIANO 3


int salvarArquivoGrupoDeRisco(const char* cpf, const char* cep, const char* dataNascimento, const char* comorbidades){

    /*
        Método que avalia e salva se o paciente for do grupo de risco:
        maiores de 65 com comorbidades
    */

    char idadeTexto[5]; //variávvel para armazenar a idade em texto
    int idade = calculaIdade(dataNascimento); // Calcula a idade a partir da data de nascimento

    /*
        Caso o paciente tenha 65 anos ou menos
        Ou não possua comorbidades
        retorna 1 para o sistema saber que não foi salvo,
        mas também não é um erro
    */
    if(idade <= 65 || strcmp(comorbidades, "") == 0 || strcmp(strlwr(comorbidades), "nao") == 0 || strcmp(strlwr(comorbidades), "não") == 0){
        return 1;
    }


    FILE* pArquivo = NULL; // ponteiro para o arquivo
    char nomeArquivo[50] = "./arquivos/saida/grupo_de_risco/"; // montagem do nome do arquivo: local onde será salvo
    strcat(nomeArquivo, cpf); // montagem do nome do arquivo: nome do arquivo (cpf)
    strcat(nomeArquivo, ".txt"); // montagem do nome do arquivo: extensão (.txt)

    // Caso o programa tenha chegado até aqui é garantido que o paciente é do grupo de risco,
    // informa ao usuário
    printfColorido("\nSalvando Paciente do Grupo de Risco....\n", CIANO);

    pArquivo = fopen(nomeArquivo, "w"); // abre o arquivo em modo de gravação

    // caso o arquivo não tenha sido aberto por algum motivo,
    // o ponteiro retornará NULL, então retorna -1 para saber que foi um erro ( < 0)
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

    // fecha a conexão com o arquivo
    fclose(pArquivo);

    // retorna 0 para o sistema saber que foi salvo com sucesso
    return 0;
}
