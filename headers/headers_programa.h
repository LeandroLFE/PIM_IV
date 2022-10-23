#include<windows.h>

void clearScreen(HANDLE hConsole);

const char* getCPF(const int tamanhoCPF, const int ajusteTamanhoStr);

const char* getNome(const int tamanhoMaxNome);

const char* getSenha(const int tamanhoMaxSenha);

const char* getTelefone(const int tamanhoTelefone, const int ajusteTamanhoStr);

const char* getUsuario(const int tamanhoMaxUsuario);

int login(const char* user, const int tamanhoMaxUsuario, const char* password, const int tamanhoMaxSenha);

void printfColorido(const char* texto, int cor);

void setColor(int ForgC);

int sistemaFormulario(const int tamanhoMaxNome, const int tamanhoMaxRua, const int tamanhoMaxBairroCidade, const int tamanhoMaxEmail, const int tamanhoMaxComorbidades);

int sistemaLogin(const int tamanhoMaxUsuario, const int tamanhoMaxSenha);

const char* trimEspacosEmBrancoGetS(const int tamanhoMaxUsuario);

int validacaoCPF(const char* CPF, int tamanhoCPF);

int validacaoTelefone(const char* Telefone, int tamanhoTelefone);
