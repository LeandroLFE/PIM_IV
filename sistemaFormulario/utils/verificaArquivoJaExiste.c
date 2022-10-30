// Importação das bibliotecas utilizadas no arquivo
#include<stdio.h> // fopen() fclose()
#include<string.h> // strcat()


int verificaSeArquivoJaExiste(const char* cpf){
     /*
        Método que tenta abrir um arquivo com um cpf informado,
        se conseguir, retorna 1 porque o paciente já foi cadastrado,
        se não conseguir, retorna 0 (OK)
    */


    FILE* pArquivo; // cria ponteiro de um arquivo
    char nomeArquivo[50] = "./arquivos/saida/pacientes/"; // montagem do nome do arquivo: local onde ficam salvos
    strcat(nomeArquivo, cpf); // montagem do nome do arquivo: nome do arquivo (cpf)
    strcat(nomeArquivo, ".txt"); // montagem do nome do arquivo: extensão (.txt)

    pArquivo = fopen(nomeArquivo, "r"); // tenta abrir o arquivo em modo de leitura

    /*
        Retorna 0 caso o arquivo não tenha sido encontrado,
        possiblitando salvar um arquivo do paciente com este cpf
    */
    if(pArquivo == NULL){
        return 0;
    }

    // caso o arquivo tenha sido aberto, fecha-o
    fclose(pArquivo);

    // retorna 1 porque o paciente já foi cadastrado
    return 1;
}
