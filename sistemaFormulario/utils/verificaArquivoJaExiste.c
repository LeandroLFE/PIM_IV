#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int verificaSeArquivoJaExiste(const char* cpf){
    FILE* pArquivo;
    char nomeArquivo[50] = "./arquivos/saida/pacientes/";
    strcat(nomeArquivo, cpf);
    strcat(nomeArquivo, ".txt");

    pArquivo = fopen(nomeArquivo, "r");

    if(pArquivo == NULL){
        return 0;
    }

    fclose(pArquivo);

    return 1;
}
