#include<windows.h>

int calculaIdade(const char* txtData);

void clearScreen(HANDLE hConsole);

const char* getBairro(const int tamanhoMaxBairro);

const char* getCidade(const int tamanhoMaxCidade);

const char* getCEP(const int tamanhoCEP, const int ajusteTamanhoStr);

const char* getCPF(const int tamanhoCPF, const int ajusteTamanhoStr);

const char* getData(const int tamanhoData, const int ajusteTamanhoStr);

const char* getEstado(const int tamanhoEstado, const int ajusteTamanhoStr);

const char* getNome(const int tamanhoMaxNome);

const int getNumero(const int tamanhoMaxNumero, const int ajusteTamanhoStr);

const char* getRua(const int tamanhoMaxRua);

const char* getSenha(const int tamanhoMaxSenha);

const char* getTelefone(const int tamanhoTelefone, const int ajusteTamanhoStr);

const char* getUsuario(const int tamanhoMaxUsuario);

int login(const char* user, const int tamanhoMaxUsuario, const char* password, const int tamanhoMaxSenha);

void printfColorido(const char* texto, int cor);

void setColor(int ForgC);

int sistemaFormulario(const int tamanhoMaxNome, const int tamanhoMaxRua, const int tamanhoMaxNumero,
                      const int tamanhoMaxComplemento, const int tamanhoMaxBairroCidade,
                      const int tamanhoMaxEmail, const int tamanhoMaxComorbidades);

int sistemaLogin(const int tamanhoMaxUsuario, const int tamanhoMaxSenha);

const char* trimEspacosEmBrancoGetS(const int tamanhoMaxUsuario);

int validacaoCPF(const char* CPF, const int tamanhoCPF);

int validacaoData(const char* data, const int tamanhoData);

int validacaoEstado(const char* estado, const int tamanhoEstado);

int validacaoNumero(const char* textoNumero, const int tamanhoMaxNumero);

int validacaoTelefone(const char* telefone, const int tamanhoTelefone);
