// Importa��o das bibliotecas utilizadas no arquivo
#include<locale.h> // setlocale()
#include<stdio.h>  // fopen() fprintf() fputc() fclose()
#include<string.h> // strcat() strcpy()

// Inclui o cabe�alho com todos os cabe�alhos dos m�todos utilizados no programa
#include "../../headers/headers_programa.h"


int salvarArquivoPaciente(const char* nome, const char* cpf, const char* telefone, const char* rua,
                          const char* numero, const char* complemento, const char* bairro, const char* cidade, const char* estado,
                          const char* cep, const char* dataNascimento, const char* email, const char* dataDiagnostico,
                          const char* comorbidades){


    /*
        M�todo que salva o arquivo txt de cada paciente
    */

    FILE* pArquivo = NULL; // cria ponteiro de um arquivo
    char nomeArquivo[50] = "./arquivos/saida/pacientes/"; // montagem do nome do arquivo: local onde ser� salvo
    strcat(nomeArquivo, cpf); // montagem do nome do arquivo: nome do arquivo (cpf)
    strcat(nomeArquivo, ".txt"); // montagem do nome do arquivo: extens�o (.txt)

    char buffer[200]; // buffer para receber valores convertidos do encoding "C" para "Windows.1252"

    pArquivo = fopen(nomeArquivo, "w"); // abre o arquivo em modo de grava��o

    // caso o arquivo n�o tenha sido aberto com sucesso valer� NULL,
    // ai retorna 1 porque n�o foi poss�vel gerar o arquivo para salvar
    if(pArquivo == NULL){
        return 1;
    }

    /*
        Escreve cada dado do formulario com uma quebra de linha '\n' entre eles

        Detalhe para o m�todo converteCParaWindows1252
        utilizado para converter acentos do encoding "C" para o encoding "Windows.1252"
        para exibir corretamente no bloco de notas
    */

    strcpy(buffer, converteCParaWindows1252(nome));
    fprintf(pArquivo, buffer);

    fputc('\n', pArquivo);

    fprintf(pArquivo, cpf);

    fputc('\n', pArquivo);

    fprintf(pArquivo, telefone);

    fputc('\n', pArquivo);

    strcpy(buffer, converteCParaWindows1252(rua));
    fprintf(pArquivo, buffer);

    fputc('\n', pArquivo);

    fprintf(pArquivo, numero);

    fputc('\n', pArquivo);

    strcpy(buffer, converteCParaWindows1252(complemento));
    fprintf(pArquivo, buffer);

    fputc('\n', pArquivo);

    strcpy(buffer, converteCParaWindows1252(bairro));
    fprintf(pArquivo, buffer);

    fputc('\n', pArquivo);

    strcpy(buffer, converteCParaWindows1252(cidade));
    fprintf(pArquivo, buffer);

    fputc('\n', pArquivo);

    fprintf(pArquivo, estado);

    fputc('\n', pArquivo);

    fprintf(pArquivo, cep);

    fputc('\n', pArquivo);

    fprintf(pArquivo, dataNascimento);

    fputc('\n', pArquivo);

    strcpy(buffer, converteCParaWindows1252(email));
    fprintf(pArquivo, buffer);

    fputc('\n', pArquivo);

    fprintf(pArquivo, dataDiagnostico);

    fputc('\n', pArquivo);

    strcpy(buffer, converteCParaWindows1252(comorbidades));
    fprintf(pArquivo, buffer);

    fclose(pArquivo); // fecha a conex�o com o arquivo

    return 0; // retorna 0 para informar que foi salvo com sucesso
}
