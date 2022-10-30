// Importação das bibliotecas utilizadas no arquivo
#include<locale.h> //setlocale
#include<stdio.h> // fopen() fprint() fputc() fclose()
#include<stdlib.h> // itoa()
#include<string.h> // strcat()

// Inclui o cabeçalho com todos os cabeçalhos dos métodos utilizados no programa
#include "../../headers/headers_programa.h"

// definição das cores utilizadas neste método
#define CIANO 3


int salvarArquivoGrupoDeRisco(const char* cpf, const char* cep, const char* dataNascimento, const char* comorbidades){

    /*
        Método que salva um arquivo cpf.txt com o CEP e a idade da pessoa em grupo de risco,
        grupo de risco são pessoas com mais de 65 anos e comorbidades
        Retorna 1 caso a pessoa não seja do grupo de risco
        Um número negativo caso ocorra erro
        E 0 caso tenha salvo com sucesso
    */

    // Inicialização das variáveis
    int idade = avaliaPessoaDoGrupoDeRisco(dataNascimento, comorbidades);
    char idadeTexto[5]; //variável para armazenar a idade em texto
    FILE* pArquivo = NULL; // ponteiro para o arquivo
    char nomeArquivo[50] = "./arquivos/saida/grupo_de_risco/"; // montagem do nome do arquivo: local onde será salvo
    strcat(nomeArquivo, cpf); // montagem do nome do arquivo: nome do arquivo (cpf)
    strcat(nomeArquivo, ".txt"); // montagem do nome do arquivo: extensão (.txt)


    // Se o paciente não é do grupo de risco, retorna 1
    if(idade < 0){
        return 1;
    }

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
