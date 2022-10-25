#include<ctype.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>

int verificaBissexto(long ano){
    if ( ano%400 == 0 || ( ano%4==0 && ano%100!=0) ){
        return 0;
    }
    return 1;
}


int calculaIdade(const char* txtData){
    time_t dataHoraAtual;
    time(&dataHoraAtual);

    struct tm* structDataHoraAtual;
    structDataHoraAtual = localtime( &dataHoraAtual );

    long dia = (txtData[0]-'0')*10 + (txtData[1]-'0');
    long mes = (txtData[2]-'0')*10 + (txtData[3]-'0');
    long ano = (txtData[4]-'0')*1000 + (txtData[5]-'0')*100 + (txtData[6]-'0')*10 + (txtData[7]-'0');

    long anoAtual = structDataHoraAtual->tm_year+1900;
    long mesAtual = structDataHoraAtual->tm_mon+1;
    long diaAtual = structDataHoraAtual->tm_mday;

    int diasDeCadaMes[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    int idade;

    if (verificaBissexto(ano) == 0){
        diasDeCadaMes[1] = 29;
    }

    if( dia<=0 || mes<=0 || ano<=0 ){
        return -3;
    }

    if( anoAtual < ano || (anoAtual == ano && mesAtual < mes) || (anoAtual == ano && mesAtual == mes && diaAtual < dia) || anoAtual - ano > 150 ){
        return -4;
    }

    if( mes > 12 ){
        return -5;
    }

    if(dia > diasDeCadaMes[mes-1]){
        return -6;
    }

    if((anoAtual >= ano && mesAtual == mes && diaAtual >= dia) || (anoAtual >= ano && mesAtual > mes)){
        idade = anoAtual - ano;
    } else {
        idade = anoAtual - ano - 1;
    }

    return idade;
}
