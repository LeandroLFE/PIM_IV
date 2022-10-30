// Importa��o das bibliotecas utilizadas no arquivo
#include<string.h> // strlen()


int validacaoEmail(const char* email, const int tamanhoMaxEmail){
    // Inicializa��o das vari�veis
    int caracterEspecial = 0;
    int i = 0;

    /*
        Email v�lido:
        Um email v�lido pode conter letras, n�meros e characteres especiais antes do @ (m�nimo 1),
        entretanto n�o pode iniciar nem conter a ultima letra antes do @ como um character especial,
        ap�s o @ n�o pode conter characteres especiais, apenas letras de 'a' a 'z' at� o '.' (m�nimo 1)
        e ap�s o '.' deve conter outro texto com characteres de 'a' a 'z' (m�nimo 1)
        Opcionalmente pode conter outro '.' seguido de mais um texto com os mesmos characters (m�nimo 1)

    */

    /*
        Verifica se o primeiro character n�o � uma letra ou numero,
        retorna 1 caso possua um character diferente
    */
    if(!((email[i]>='a' && email[i]<='z') || (email[i] >= '0' && email[i] <= '9'))){
        return 1;
    }
    /*
        Varre o email da segunda letra at� o @ (ou at� o fim caso n�o possua)
    */
    for(i=1; i< strlen(email) && email[i] != '@'; i++){
        /*
            Caso o character atual seja uma letra, numero, ou algum character especial listado,
            se n�o lido um deles, retorna 2
        */
        if((email[i]>='a' && email[i]<='z') || (email[i] >= '0' && email[i] <= '9')
            || email[i] == '#' || email[i] == '!' || email[i] == '%' || email[i] == '\'' || email[i] == '&'
            || email[i] == '+' || email[i] == '*' || email[i] == '-' || email[i] == '/' || email[i] == '='
            || email[i] == '?' || email[i] == '^' || email[i] == '`' || email[i] == '.' || email[i] == '{'
            || email[i] == '|' || email[i] == '}' || email[i] == '~' || email[i] == '$'
        ){
            /*
                marca se o ultimo character lido foi um especial ou n�o
            */
            if(!((email[i]>='a' && email[i]<='z') || (email[i] >= '0' && email[i] <= '9'))){
                caracterEspecial = 1;
            } else{
                caracterEspecial = 0;
            }
        } else{
            return 2;
        }
    }

    /*
        caso o ultimo character antes do @ tenha sido especial retorna 3 por n�o ser v�lido
    */
    if(caracterEspecial == 1){
        return 3;
    }

    /*
        caso n�o possua mais espa�o para mais letras ap�s o final do for retorna 4
    */
    if (i >= strlen(email)-1){
        return 4;
    }

    i++; // adiciona mais um ao �ndice, esperando ser a posi��o logo ap�s o @
    /*
        Verifica se o primeiro character ap�s o @ n�o � uma letra de 'a' a 'z',
        retorna 5 caso possua um character diferente
    */
    if(!((email[i]>='a' && email[i]<='z'))){
        return 5;
    }
    i++; // adiciona mais 1 ao indice
    /*
        varre o email partindo da posi��o do �ndice atual (2 letras ap�s o @),
        at� encontrar o '.' (ou o fim da string caso n�o exista)
    */
    for(; i<strlen(email) && email[i] != '.'; i++){
        // caso o character lido n�o seja uma letra nem um ponto, retorna 6
        if(!(email[i]>='a' && email[i]<='z')){
            return 6;
        }
    }

    // Caso o '.' n�o tenha sido encontrado, retorna 7
    if (i >= strlen(email)){
        return 7;
    }

    i++; // adiciona mais 1 ao indice (posi��o do character ap�s o '.')

    /*
        verifica se o character logo ap�s o ponto � uma letra valida,
        caso n�o seja, retorna 8
    */
    if(!((email[i]>='a' && email[i]<='z'))){
        return 8;
    }

    i++; // adiciona mais 1 ao indice

    // varre o email do '.' + 2 at� o fim da string (ou at� um segundo ponto)
    for(; i<strlen(email) && email[i] != '.'; i++){
        // caso o character lido n�o seja uma letra nem um ponto, retorna 9
        if(!(email[i]>='a' && email[i]<='z')){
            return 9;
        }
    }

    // Caso tenha chegado ao final da string do email, retorna 0 = OK
    if (i == strlen(email)){
        return 0;
    }

    // Caso contr�rio, significa que encontrou um segundo ponto
    i++; // adiciona mais 1 ao indice (posi��o do character ap�s o '.')

    /*
        verifica se o character logo ap�s o segundo ponto � uma letra valida,
        caso n�o seja, retorna 10
    */
    if(!((email[i]>='a' && email[i]<='z'))){
        return 10;
    }

    i++; // adiciona mais 1 ao indice

    // varre o email do segundo '.' + 2 at� o fim da string
    for(; i<strlen(email); i++){
        // caso o character lido n�o seja uma letra, retorna 11
        if(!(email[i]>='a' && email[i]<='z')){
            return 11;
        }
    }

    // se o programa chegou at� este ponto significa que � um email OK com .textoAdicional e retorna 0
    return 0;
}
