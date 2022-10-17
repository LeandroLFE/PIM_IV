#include<stdlib.h>

const char* colorir(char cor){

    switch(cor){

    case 'v':
        return "\033[1;31m";

    case 'z':
        return "\033[1;34m";

    case 'c':
        return "\033[0;36m";

    case 'a':
        return "\033[0;33m";

    default:
        return "\033[0m";

    }

}
