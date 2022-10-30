// Importa��o das bibliotecas utilizadas no arquivo
#include<stdio.h> // fopen() fclose()
#include<string.h> // strcat()


int verificaSeArquivoJaExiste(const char* cpf){
     /*
        M�todo que tenta abrir um arquivo com um cpf informado,
        se conseguir, retorna 1 porque o paciente j� foi cadastrado,
        se n�o conseguir, retorna 0 (OK)
    */


    FILE* pArquivo; // cria ponteiro de um arquivo
    char nomeArquivo[50] = "./arquivos/saida/pacientes/"; // montagem do nome do arquivo: local onde ficam salvos
    strcat(nomeArquivo, cpf); // montagem do nome do arquivo: nome do arquivo (cpf)
    strcat(nomeArquivo, ".txt"); // montagem do nome do arquivo: extens�o (.txt)

    pArquivo = fopen(nomeArquivo, "r"); // tenta abrir o arquivo em modo de leitura

    /*
        Retorna 0 caso o arquivo n�o tenha sido encontrado,
        possiblitando salvar um arquivo do paciente com este cpf
    */
    if(pArquivo == NULL){
        return 0;
    }

    // caso o arquivo tenha sido aberto, fecha-o
    fclose(pArquivo);

    // retorna 1 porque o paciente j� foi cadastrado
    return 1;
}
