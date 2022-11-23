// Importação das bibliotecas utilizadas no arquivo
#include<locale.h> // setlocale()
#include<stdio.h> // fflush() printf() getchar()
#include<string.h> // strcpy()
#include<windows.h> // Sleep()

// Inclui o cabeçalho com todos os cabeçalhos dos métodos utilizados no programa
#include "../headers/headers_programa.h"

/*
    Definição do tamanho dos campos que possuem tamanho fixo
*/

// Ajuste para compor as variáveis e ser possível testar se elas possuem mais characters do que deveria
#define AJUSTE_TAMANHO_STR 3 // aumenta a capacidade de cada variável do tipo texto para evitar bugs por overflow
#define TAMANHO_CEP 8 // XXXXXXXX - apenas números
#define TAMANHO_CPF 11 // XXXXXXXXXXX - apenas números
#define TAMANHO_ESTADO 2 // Estado de 2 digitos dentre os estados brasileiros
#define TAMANHO_TELEFONE 11 // 2 Digitos do DDD + 9 digitos de 0 a 9
#define TAMANHO_DATA 8 // ddmmaaaa - apenas números

// definição das cores utilizadas neste método
#define CIANO 3
#define MARROM 6
#define VERMELHO_CLARO 12
#define BRANCO 15


int sistemaFormulario(const int tamanhoMaxNome, const int tamanhoMaxRua, const int tamanhoMaxNumero,
                      const int tamanhoMaxComplemento, const int tamanhoMaxBairroCidade,
                      const int tamanhoMaxEmail, const int tamanhoMaxComorbidades){

    // Inicialização das variáveis e seus auxiliares

    char auxNome[tamanhoMaxNome+AJUSTE_TAMANHO_STR];
    const char* nome;

    char auxCPF[TAMANHO_CPF+AJUSTE_TAMANHO_STR];
    const char* cpf;

    char auxTelefone[TAMANHO_TELEFONE+AJUSTE_TAMANHO_STR];
    const char* telefone;

    char auxRua[tamanhoMaxRua+AJUSTE_TAMANHO_STR];
    const char* rua;

    char auxNumero[tamanhoMaxNumero+AJUSTE_TAMANHO_STR];
    const char* numero;

    char auxComplemento[tamanhoMaxComplemento+AJUSTE_TAMANHO_STR];
    const char* complemento;

    char auxBairro[tamanhoMaxBairroCidade+AJUSTE_TAMANHO_STR];
    const char* bairro;

    char auxCidade[tamanhoMaxBairroCidade+AJUSTE_TAMANHO_STR];
    const char* cidade;

    char auxEstado[TAMANHO_ESTADO+AJUSTE_TAMANHO_STR];
    const char* estado;

    char auxCEP[TAMANHO_CEP+AJUSTE_TAMANHO_STR];
    const char* cep;

    char auxDataNascimento[TAMANHO_DATA+AJUSTE_TAMANHO_STR];
    const char* dataNascimento;

    char auxEmail[tamanhoMaxEmail+AJUSTE_TAMANHO_STR];
    const char* email;

    char auxDataDiagnostico[TAMANHO_DATA+AJUSTE_TAMANHO_STR];
    const char* dataDiagnostico;

    char auxComorbidades[tamanhoMaxComorbidades+AJUSTE_TAMANHO_STR];
    const char* comorbidades;

    int salvamentoConfirmado;
    int statusSalvamentoPaciente;
    int statusSalvamentoGrupoDeRisco;

    char novoPaciente = 'S';

    do{
        clearScreen(); // método clearScreen externo
        fflush(stdin); // limpeza do buffer de entrada
        setColor(MARROM); // altera a cor da fonte do terminal para MARROM com o método setColor externo
        printf("************************************");
        printf("\n*******BEM VINDO AO SISTEMA*********");
        printf("\n**********FORMULARIO****************");
        printf("\n************************************\n");
        setColor(BRANCO); // altera a cor da fonte do terminal para BRANCO com o método setColor externo

        /*
        Recebe valor oriundo do usuário via terminal e armazena nas variáveis auxiliares,
        após isso, transmite esse valor para a variável constante de mesmo nome
        */

        strcpy(auxCPF, getCPF(TAMANHO_CPF, AJUSTE_TAMANHO_STR));
        cpf = auxCPF;

        strcpy(auxNome, getNome(tamanhoMaxNome));
        nome = auxNome;

        strcpy(auxTelefone, getTelefone(TAMANHO_TELEFONE, AJUSTE_TAMANHO_STR));
        telefone = auxTelefone;

        strcpy(auxRua, getRua(tamanhoMaxRua));
        rua = auxRua;

        strcpy(auxNumero, getNumero(tamanhoMaxNumero, AJUSTE_TAMANHO_STR));
        numero = auxNumero;

        strcpy(auxComplemento, getComplemento(tamanhoMaxComplemento));
        complemento = auxComplemento;

        strcpy(auxBairro, getBairro(tamanhoMaxBairroCidade));
        bairro = auxBairro;

        strcpy(auxCidade, getCidade(tamanhoMaxBairroCidade));
        cidade = auxCidade;

        strcpy(auxEstado, getEstado(TAMANHO_ESTADO, AJUSTE_TAMANHO_STR));
        estado = auxEstado;

        strcpy(auxCEP, getCEP(TAMANHO_CEP, AJUSTE_TAMANHO_STR));
        cep = auxCEP;

        strcpy(auxDataNascimento, getDataNascimento(TAMANHO_DATA, AJUSTE_TAMANHO_STR));
        dataNascimento = auxDataNascimento;

        strcpy(auxEmail, getEmail(tamanhoMaxEmail, AJUSTE_TAMANHO_STR));
        email = auxEmail;

        strcpy(auxDataDiagnostico, getDataDiagnostico(TAMANHO_DATA, AJUSTE_TAMANHO_STR, dataNascimento));
        dataDiagnostico = auxDataDiagnostico;

        strcpy(auxComorbidades, getComorbidades(tamanhoMaxComorbidades));
        comorbidades = auxComorbidades;

        // salvar em arquivo o paciente
        clearScreen(); // método clearScreen externo
        fflush(stdin); // limpeza do buffer de entrada

        // Apresenta um resumo dos dados informados para o usuário decidir se está correto ou não para salvar em arquivo txt
        salvamentoConfirmado = exibeResumoFormulario(nome, cpf, telefone, rua, numero, complemento,
                                                     bairro, cidade, estado, cep, dataNascimento,
                                                     email, dataDiagnostico, comorbidades );

        // Caso esteja tudo Ok
        if(salvamentoConfirmado == 0){
            printfColorido("\nSalvando....\n", CIANO);
            // salva o paciente em um arquivo cpf.txt
            statusSalvamentoPaciente = salvarArquivoPaciente(nome, cpf, telefone, rua, numero, complemento,
                                                     bairro, cidade, estado, cep, dataNascimento,
                                                     email, dataDiagnostico, comorbidades );

            // Caso o arquivo seja gerado ou não, exibe mensagem de acordo
            if(statusSalvamentoPaciente != 0){
                printfColorido("\nErro ao salvar arquivo do paciente, contate o administrador\n", VERMELHO_CLARO);
            } else{
                printfColorido("\nSalvo arquivo do paciente com sucesso!\n", CIANO);
            }


            // Verifica e salva o paciente em grupo de risco em outro arquivo txt
            statusSalvamentoGrupoDeRisco = salvarArquivoGrupoDeRisco(cpf, cep, dataNascimento, comorbidades);


            // Caso o arquivo seja gerado ou não, exibe mensagem de acordo
            if(statusSalvamentoGrupoDeRisco == 0){
                printfColorido("\nSalvo arquivo do paciente do grupo de risco com sucesso!\n", CIANO);
            } else if(statusSalvamentoGrupoDeRisco < 0){
                printfColorido("\nErro ao salvar arquivo do paciente do grupo de risco, contate o administrador\n", VERMELHO_CLARO);
            }

            do{
                // Apresenta opção de inserir dados de um novo paciente
                setlocale(LC_ALL, "Portuguese_Brazil.1252"); // Altera o locale para Portugues do Brasil, encoding Windows 1252
                printf("\nDeseja inserir dados de um novo paciente?: S para sim, N para não: ");
                setlocale(LC_ALL, "C"); // Altera o locale de volta para "C"
                novoPaciente = getchar(); // leitura de 1 character
                fflush(stdin); // limpeza do buffer de entrada para eliminar o \n adicional

                // Caso o usuario opte por não inserir dados, realiza o logoff
                if(novoPaciente == 'n' || novoPaciente == 'N' ){
                    printfColorido("\nDeslogando...\n", CIANO);
                    Sleep(500); // aguarda 0,5s
                }
                // Caso contrário, reinicia o formulário
                else if (novoPaciente == 's' || novoPaciente == 'S'){
                    Sleep(500); // aguarda 0,5s
                }
            }while(!((novoPaciente == 's' || novoPaciente == 'S')||(novoPaciente == 'n' || novoPaciente == 'N'))); // Loop que espera s, S, n ou N
        // Caso o usuário não esteja em conformes com o resumo dos dados inseridos,
        // Induz a repetição do loop para reiniciar o formulário
        } else{
            novoPaciente = 's';
        }
    }while(novoPaciente == 's' || novoPaciente == 'S'); // repete o formulário caso o usuario tenha informado s ou S

    return 1; // retorna 1 para main
}
