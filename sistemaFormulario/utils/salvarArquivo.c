#include<locale.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#include "../../headers/headers_programa.h"

int salvarArquivoPaciente(const char* nome, const char* cpf, const char* telefone, const char* rua,
                          const char* numero, const char* complemento, const char* bairro, const char* cidade, const char* estado,
                          const char* cep, const char* dataNascimento, const char* email, const char* dataDiagnostico,
                          const char* comorbidades){
    FILE* pArquivo = NULL;
    char nomeArquivo[50] = "./arquivos/saida/pacientes/";
    strcat(nomeArquivo, cpf);
    strcat(nomeArquivo, ".txt");

    char buffer[200];

    pArquivo = fopen(nomeArquivo, "w");

    if(pArquivo == NULL){
        return 1;
    }

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

    fclose(pArquivo);

    return 0;
}
