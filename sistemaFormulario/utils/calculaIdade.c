// Importa��o das bibliotecas utilizadas no arquivo
#include<ctype.h> // isdigit()
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h> // time_t time() struct tm* localtime()

int verificaBissexto(long ano){
    /*
        programa auxiliar para saber se um ano � bissexto,
        um ano � bissexto quando � divis�vel por 400
        Ou quando � divisivel por 4, mas n�o por 100,
        retorna 0 caso seja bissexto, 1 se n�o for
    */
    if ( ano%400 == 0 || ( ano%4==0 && ano%100!=0) ){
        return 0;
    }
    return 1;
}


int calculaIdade(const char* txtData){
    // Inicializa��o das vari�veis
    time_t dataHoraAtual; // vari�vel que ir� armazenar a data/hora atual
    time(&dataHoraAtual); // chamada do m�todo time que retorna a data/hora atual e armazena em dataHoraAtual

    struct tm* structDataHoraAtual; // estrutura de dados do tipo tm que conter� a Data e hora Atual
    structDataHoraAtual = localtime( &dataHoraAtual ); // associa��o da dataHoraAtual com a sua estrutura

    long dia = (txtData[0]-'0')*10 + (txtData[1]-'0'); // converte os 2 digitos do dia em numero
    long mes = (txtData[2]-'0')*10 + (txtData[3]-'0'); // converte is 2 digitos do mes em numero
    long ano = (txtData[4]-'0')*1000 + (txtData[5]-'0')*100 + (txtData[6]-'0')*10 + (txtData[7]-'0'); // converte os 4 digitos do ano em numero

    long anoAtual = structDataHoraAtual->tm_year+1900; //recebe o ano atual da estrutura
    long mesAtual = structDataHoraAtual->tm_mon+1; //recebe o mes atual da estrutura
    long diaAtual = structDataHoraAtual->tm_mday; // recebe o dia atual da estrutura

    int diasDeCadaMes[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}; //lista com a quantidade de dias de cada m�s do ano

    int idade;

    /*
        caso o ano informado seja bissexto,
        altera a quantidade de dias de fevereiro, 1 a partir do 0, para 29 dias
    */
    if (verificaBissexto(ano) == 0){
        diasDeCadaMes[1] = 29;
    }

    /*
        Caso algum n�mero seja negativo, retorna -3
    */
    if( dia<=0 || mes<=0 || ano<=0 ){
        return -3;
    }

    /*
        Caso a data informada seja superior a data atual, retorna -4

    */
    if( anoAtual < ano || (anoAtual == ano && mesAtual < mes) || (anoAtual == ano && mesAtual == mes && diaAtual < dia)){
        return -4;
    }

    /*
        Caso o ano informado seja 150 anos antes do ano atual, retorna -5
    */
    if(anoAtual - ano > 150){
        return -5;
    }

    /*
        Caso o m�s informado seja maior do que 12, retorna -6
    */
    if( mes > 12 ){
        return -6;
    }

    /*
        Caso o dia informado seja superior a quantidade de dias poss�veis do m�s, retorna -7
    */
    if(dia > diasDeCadaMes[mes-1]){
        return -7;
    }


    /*
        Calcula a idade a partir da data informada:
        - Caso o mes/dia informado seja inferior ao mes/dia atual, calcula-se anoAtual - ano informado
        - Caso contr�rio, reduz-se 1 ano da subtra��o acima

    */
    if((anoAtual >= ano && mesAtual == mes && diaAtual >= dia) || (anoAtual >= ano && mesAtual > mes)){
        idade = anoAtual - ano;
    } else {
        idade = anoAtual - ano - 1;
    }

    // Caso a data esteja validada, retorna a idade calculada
    return idade;
}
