// Importa��o das bibliotecas utilizadas no arquivo
#include<locale.h> //setlocale
#include<stdio.h> // fopen() fprint() fputc() fclose()
#include<stdlib.h> // itoa()
#include<string.h> // strcat()

// Inclui o cabe�alho com todos os cabe�alhos dos m�todos utilizados no programa
#include "../../headers/headers_programa.h"

// defini��o das cores utilizadas neste m�todo
#define CIANO 3


int salvarArquivoGrupoDeRisco(const char* cpf, const char* cep, const char* dataNascimento, const char* comorbidades){

    /*
        M�todo que salva um arquivo cpf.txt com o CEP e a idade da pessoa em grupo de risco,
        grupo de risco s�o pessoas com mais de 65 anos e comorbidades
        Retorna 1 caso a pessoa n�o seja do grupo de risco
        Um n�mero negativo caso ocorra erro
        E 0 caso tenha salvo com sucesso
    */

    // Inicializa��o das vari�veis
    int idade = avaliaPessoaDoGrupoDeRisco(dataNascimento, comorbidades);
    char idadeTexto[5]; //vari�vel para armazenar a idade em texto
    FILE* pArquivo = NULL; // ponteiro para o arquivo
    char nomeArquivo[50] = "./arquivos/saida/grupo_de_risco/"; // montagem do nome do arquivo: local onde ser� salvo
    strcat(nomeArquivo, cpf); // montagem do nome do arquivo: nome do arquivo (cpf)
    strcat(nomeArquivo, ".txt"); // montagem do nome do arquivo: extens�o (.txt)


    // Se o paciente n�o � do grupo de risco, retorna 1
    if(idade < 0){
        return 1;
    }

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
