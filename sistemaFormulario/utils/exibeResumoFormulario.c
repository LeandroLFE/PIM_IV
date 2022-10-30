// Importação das bibliotecas utilizadas no arquivo
#include<ctype.h>
#include<locale.h> // setlocale()
#include<stdio.h> // printf() getchar() fflush()
#include<string.h>

// Inclui o cabeçalho com todos os cabeçalhos dos métodos utilizados no programa
#include "../../headers/headers_programa.h"

// definição das cores utilizadas neste método
#define MARROM 6
#define VERMELHO_CLARO 12

int exibeResumoFormulario(const char* nome, const char* cpf, const char* telefone, const char* rua,
                          const char* numero, const char* complemento, const char* bairro, const char* cidade, const char* estado,
                          const char* cep, const char* dataNascimento, const char* email, const char* dataDiagnostico,
                          const char* comorbidades){

    /*
        Método que exibe todos os dados do formulário e pede uma confirmação
    */

    char escolha;

    printfColorido("\nConfirma os dados a seguir?\n", MARROM);
    printf("\nNome: %s", nome);
    printf("\nCPF: %s", cpf);
    printf("\nTelefone: %s", telefone);
    printf("\nRua: %s", rua);
    setlocale(LC_ALL, "Portuguese_Brazil.1252"); // altera o locale para Portugues para exibir character do texto do printf com acento no terminal
    printf("\nNúmero: ");
    setlocale(LC_ALL, "C"); // altera o locale de volta para C para exibir variaveis com acento
    printf("%s", numero);
    printf("\nComplemento: %s", complemento);
    printf("\nBairro: %s", bairro);
    printf("\nCidade: %s", cidade);
    printf("\nEstado: %s", estado);
    printf("\nCEP: %s", cep);
    printf("\nData de Nascimento: %s", dataNascimento);
    printf("\nEmail: %s", email );
    setlocale(LC_ALL, "Portuguese_Brazil.1252"); // altera o locale para Portugues para exibir character do texto do printf com acento no terminal
    printf("\nData de Diagnóstico: ");
    setlocale(LC_ALL, "C"); // altera o locale de volta para C para exibir variaveis com acento
    printf("%s", dataDiagnostico);
    printf("\nComorbidades: %s", comorbidades);
    do{
        setlocale(LC_ALL, "Portuguese_Brazil.1252"); // altera o locale para Portugues para exibir character do texto do printf com acento no terminal
        printf("\n\nResponda S para sim ou N para não: ");
        setlocale(LC_ALL, "C"); // altera o locale de volta para C para exibir variaveis com acento
        escolha = getchar(); // Recebe um character informado pelo usuario
        fflush(stdin); // limpa o buffer de entrada (elimina o \n)

        /*
            Retorna 0 caso o usuario confirme que os dados estão corretos
        */
        if(escolha == 's' || escolha == 'S'){
            return 0;
        }

    // repete a escolha caso não seja um valor entre 'n', 'N', 's' ou 'S'
    }while(!((escolha == 's' || escolha == 'S') || (escolha == 'n' || escolha == 'N')));

    // retorna 1 caso o usuario digite 'n' ou 'N', não confirmando os dados
    return 1;
}
