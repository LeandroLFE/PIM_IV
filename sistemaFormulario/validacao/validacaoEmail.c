// Importação das bibliotecas utilizadas no arquivo
#include<string.h> // strlen()


int validacaoEmail(const char* email, const int tamanhoMaxEmail){
    // Inicialização das variáveis
    int caracterEspecial = 0;
    int i = 0;

    /*
        Email válido:
        Um email válido pode conter letras, números e characteres especiais antes do @ (mínimo 1),
        entretanto não pode iniciar nem conter a ultima letra antes do @ como um character especial,
        após o @ não pode conter characteres especiais, apenas letras de 'a' a 'z' até o '.' (mínimo 1)
        e após o '.' deve conter outro texto com characteres de 'a' a 'z' (mínimo 1)
        Opcionalmente pode conter outro '.' seguido de mais um texto com os mesmos characters (mínimo 1)

    */

    /*
        Verifica se o primeiro character não é uma letra ou numero,
        retorna 1 caso possua um character diferente
    */
    if(!((email[i]>='a' && email[i]<='z') || (email[i] >= '0' && email[i] <= '9'))){
        return 1;
    }
    /*
        Varre o email da segunda letra até o @ (ou até o fim caso não possua)
    */
    for(i=1; i< strlen(email) && email[i] != '@'; i++){
        /*
            Caso o character atual seja uma letra, numero, ou algum character especial listado,
            se não lido um deles, retorna 2
        */
        if((email[i]>='a' && email[i]<='z') || (email[i] >= '0' && email[i] <= '9')
            || email[i] == '#' || email[i] == '!' || email[i] == '%' || email[i] == '\'' || email[i] == '&'
            || email[i] == '+' || email[i] == '*' || email[i] == '-' || email[i] == '/' || email[i] == '='
            || email[i] == '?' || email[i] == '^' || email[i] == '`' || email[i] == '.' || email[i] == '{'
            || email[i] == '|' || email[i] == '}' || email[i] == '~' || email[i] == '$'
        ){
            /*
                marca se o ultimo character lido foi um especial ou não
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
        caso o ultimo character antes do @ tenha sido especial retorna 3 por não ser válido
    */
    if(caracterEspecial == 1){
        return 3;
    }

    /*
        caso não possua mais espaço para mais letras após o final do for retorna 4
    */
    if (i >= strlen(email)-1){
        return 4;
    }

    i++; // adiciona mais um ao índice, esperando ser a posição logo após o @
    /*
        Verifica se o primeiro character após o @ não é uma letra de 'a' a 'z',
        retorna 5 caso possua um character diferente
    */
    if(!((email[i]>='a' && email[i]<='z'))){
        return 5;
    }
    i++; // adiciona mais 1 ao indice
    /*
        varre o email partindo da posição do índice atual (2 letras após o @),
        até encontrar o '.' (ou o fim da string caso não exista)
    */
    for(; i<strlen(email) && email[i] != '.'; i++){
        // caso o character lido não seja uma letra nem um ponto, retorna 6
        if(!(email[i]>='a' && email[i]<='z')){
            return 6;
        }
    }

    // Caso o '.' não tenha sido encontrado, retorna 7
    if (i >= strlen(email)){
        return 7;
    }

    i++; // adiciona mais 1 ao indice (posição do character após o '.')

    /*
        verifica se o character logo após o ponto é uma letra valida,
        caso não seja, retorna 8
    */
    if(!((email[i]>='a' && email[i]<='z'))){
        return 8;
    }

    i++; // adiciona mais 1 ao indice

    // varre o email do '.' + 2 até o fim da string (ou até um segundo ponto)
    for(; i<strlen(email) && email[i] != '.'; i++){
        // caso o character lido não seja uma letra nem um ponto, retorna 9
        if(!(email[i]>='a' && email[i]<='z')){
            return 9;
        }
    }

    // Caso tenha chegado ao final da string do email, retorna 0 = OK
    if (i == strlen(email)){
        return 0;
    }

    // Caso contrário, significa que encontrou um segundo ponto
    i++; // adiciona mais 1 ao indice (posição do character após o '.')

    /*
        verifica se o character logo após o segundo ponto é uma letra valida,
        caso não seja, retorna 10
    */
    if(!((email[i]>='a' && email[i]<='z'))){
        return 10;
    }

    i++; // adiciona mais 1 ao indice

    // varre o email do segundo '.' + 2 até o fim da string
    for(; i<strlen(email); i++){
        // caso o character lido não seja uma letra, retorna 11
        if(!(email[i]>='a' && email[i]<='z')){
            return 11;
        }
    }

    // se o programa chegou até este ponto significa que é um email OK com .textoAdicional e retorna 0
    return 0;
}
