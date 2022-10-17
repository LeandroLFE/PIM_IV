#include<windows.h>

void clearScreen(HANDLE hConsole);

const char* getSenha(const int tamanhoMaxSenha);

const char* getUsuario(const int tamanhoMaxUsuario);

int sistemaLogin(const int tamanhoMaxUsuario, const int tamanhoMaxSenha);

int login(const char* user, const int tamanhoMaxUsuario, const char* password, const int tamanhoMaxSenha);

const char* trimEspacosEmBrancoGetS(const int tamanhoMaxUsuario);
