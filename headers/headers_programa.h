#include<windows.h>

void clearScreen(HANDLE hConsole);

const char* getSenha(const int tamanhoMaxSenha);

const char* getUsuario(const int tamanhoMaxUsuario);

int login(const char* user, const int tamanhoMaxUsuario, const char* password, const int tamanhoMaxSenha);

void setColor(int ForgC);

const char* trimEspacosEmBrancoGetS(const int tamanhoMaxUsuario);
