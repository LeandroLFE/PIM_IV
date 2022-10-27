#include<ctype.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int validacaoEmail(const char* email, const int tamanhoMaxEmail){
    int caracterEspecial = 0;
    int i = 0;

    if(!((email[i]>='a' && email[i]<='z') || (email[i] >= '0' && email[i] <= '9'))){
        return 1;
    }
    for(i=1; i< strlen(email) && email[i] != '@'; i++){
        if((email[i]>='a' && email[i]<='z') || (email[i] >= '0' && email[i] <= '9')
            || email[i] == '#' || email[i] == '!' || email[i] == '%' || email[i] == '‘' || email[i] == '&'
            || email[i] == '+' || email[i] == '*' || email[i] == '-' || email[i] == '/' || email[i] == '='
            || email[i] == '?' || email[i] == '^' || email[i] == '`' || email[i] == '.' || email[i] == '{'
            || email[i] == '|' || email[i] == '}' || email[i] == '~' || email[i] == '$'
        ){
            if(!((email[i]>='a' && email[i]<='z') || (email[i] >= '0' && email[i] <= '9'))){
                caracterEspecial = 1;
            } else{
                caracterEspecial = 0;
            }
        }
    }
    if(caracterEspecial == 1){
        return 2;
    }

    if (i >= strlen(email)-1){
        return 3;
    }

    i++;
    if(!((email[i]>='a' && email[i]<='z'))){
        return 4;
    }
    i++;

    for(; i<strlen(email) && email[i] != '.'; i++){
        if(!(email[i]>='a' && email[i]<='z')){
            return 5;
        }
    }

    if (i >= strlen(email)){
        return 6;
    }

    i++;
    if(!((email[i]>='a' && email[i]<='z'))){
        return 7;
    }
    i++;

    for(; i<strlen(email) && email[i] != '.'; i++){
        if(!(email[i]>='a' && email[i]<='z')){
            return 8;
        }
    }

    if (i == strlen(email)){
        return 0;
    }

    i++;
    if(!((email[i]>='a' && email[i]<='z'))){
        return 9;
    }

    i++;
    for(; i<strlen(email); i++){
        if(!(email[i]>='a' && email[i]<='z')){
            return 10;
        }
    }

    return 0;
}
