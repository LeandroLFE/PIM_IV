#include<ctype.h>
#include<locale.h>
#include<stdio.h>
#include<string.h>

#include "../../headers/headers_programa.h"

#define CIANO 3
#define MARROM 6
#define VERMELHO_CLARO 12

int exibeResumoFormulario(const char* nome, const char* cpf, const char* telefone, const char* rua,
                          int numero, const char* complemento, const char* bairro, const char* cidade, const char* estado,
                          const char* cep, const char* dataNascimento, const char* email, const char* dataDiagnostico,
                          const char* comorbidades){

    char escolha;

    printfColorido("\nConfirma os dados a seguir?\n", MARROM);

    printf("\nNome: %s", nome);
    printf("\nCPF: %s", cpf);
    printf("\nTelefone: %s", telefone);
    printf("\nRua: %s", rua);
    setlocale(LC_ALL, "Portuguese_Brazil.1252");
    printf("\nNúmero: ");
    setlocale(LC_ALL, "C");
    printf("%d", numero);
    printf("\nComplemento: %s", complemento);
    printf("\nBairro: %s", bairro);
    printf("\nCidade: %s", cidade);
    printf("\nEstado: %s", estado);
    printf("\nCEP: %s", cep);
    printf("\nData de Nascimento: %s", dataNascimento);
    printf("\nEmail: %s", email );
    setlocale(LC_ALL, "Portuguese_Brazil.1252");
    printf("\nData de Diagnóstico: ");
    setlocale(LC_ALL, "C");
    printf("%s", dataDiagnostico);
    printf("\nComorbidades: %s", comorbidades);
    do{
        setlocale(LC_ALL, "Portuguese_Brazil.1252");
        printf("\n\nResponda S para sim ou N para não: ");
        setlocale(LC_ALL, "C");
        escolha = getchar();
        fflush(stdin);

        if(escolha == 's' || escolha == 'S'){
            printfColorido("\nSalvando....\n", CIANO);
            //salvar
            return 0;
        }

    }while(!((escolha == 's' || escolha == 'S') || (escolha == 'n' || escolha == 'N')));

    return 1;
}
