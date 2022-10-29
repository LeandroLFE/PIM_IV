#include<stdio.h>
#include<string.h>
#include<windows.h>

#include "../headers/headers_programa.h"

#define AJUSTE_TAMANHO_STR 3
#define TAMANHO_CEP 8
#define TAMANHO_CPF 11
#define TAMANHO_ESTADO 2
#define TAMANHO_TELEFONE 11
#define TAMANHO_DATA 8 // ddmmaaaa

#define CIANO 3
#define MARROM 6
#define VERMELHO_CLARO 12
#define BRANCO 15


int sistemaFormulario(const int tamanhoMaxNome, const int tamanhoMaxRua, const int tamanhoMaxNumero,
                      const int tamanhoMaxComplemento, const int tamanhoMaxBairroCidade,
                      const int tamanhoMaxEmail, const int tamanhoMaxComorbidades){

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

    HANDLE hStdout;
    hStdout = GetStdHandle(STD_OUTPUT_HANDLE);

    char novoPaciente = 'S';

    do{
        clearScreen(hStdout);
        fflush(stdin);
        setColor(MARROM);
        printf("************************************");
        printf("\n*******BEM VINDO AO SISTEMA*********");
        printf("\n**********FORMULARIO****************");
        printf("\n************************************\n");
        setColor(BRANCO);

        strcpy(auxNome, getNome(tamanhoMaxNome));
        nome = auxNome;

        strcpy(auxCPF, getCPF(TAMANHO_CPF, AJUSTE_TAMANHO_STR));
        cpf = auxCPF;

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
        clearScreen(hStdout);
        fflush(stdin);
        salvamentoConfirmado = exibeResumoFormulario(nome, cpf, telefone, rua, numero, complemento,
                                                     bairro, cidade, estado, cep, dataNascimento,
                                                     email, dataDiagnostico, comorbidades );
        if(salvamentoConfirmado == 0){

            // salvar o paciente em grupo de risco em outro arquivo
            do{
                printf("\nDeseja inserir dados de um novo paciente?: S para sim: ");
                novoPaciente = getchar();
                fflush(stdin);

                if(novoPaciente == 'n' || novoPaciente == 'N' ){
                    printfColorido("\nDeslogando...\n", CIANO);
                    Sleep(500);
                } else if (novoPaciente == 's' || novoPaciente == 'S'){
                    Sleep(500);
                }
            }while(!((novoPaciente == 's' || novoPaciente == 'S')||(novoPaciente == 'n' || novoPaciente == 'N')));

        } else{
            novoPaciente = 's';
        }
    }while(novoPaciente == 's' || novoPaciente == 'S');

    return 1;
}
