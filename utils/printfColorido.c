#define BRANCO 15


void printfColorido(const char* texto, int cor){

    setColor(cor);
    printf("%s", texto);
    setColor(BRANCO);

}
