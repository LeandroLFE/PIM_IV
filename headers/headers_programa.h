#include<windows.h>

int calculaIdade(const char* txtData);

void clearScreen(HANDLE hConsole);

const char* converteCParaWindows1252(const char* entrada);

int exibeResumoFormulario(const char* nome, const char* cpf, const char* telefone, const char* rua,
                          const char* numero, const char* complemento, const char* bairro, const char* cidade, const char* estado,
                          const char* cep, const char* dataNascimento, const char* email, const char* dataDiagnostico,
                          const char* comorbidades);

const char* getBairro(const int tamanhoMaxBairro);

const char* getCidade(const int tamanhoMaxCidade);

const char* getCEP(const int tamanhoCEP, const int ajusteTamanhoStr);

const char* getComorbidades(const int tamanhoMaxComorbidades);

const char* getComplemento(const int tamanhoMaxComplemento);

const char* getCPF(const int tamanhoCPF, const int ajusteTamanhoStr);

const char* getDataDiagnostico(const int tamanhoData, const int ajusteTamanhoStr, const char* dataNascimento);

const char* getDataNascimento(const int tamanhoData, const int ajusteTamanhoStr);

const char* getEmail(const int tamanhoMaxEmail, const int ajusteTamanhoStr);

const char* getEstado(const int tamanhoEstado, const int ajusteTamanhoStr);

const char* getNome(const int tamanhoMaxNome);

const char* getNumero(const int tamanhoMaxNumero, const int ajusteTamanhoStr);

const char* getRua(const int tamanhoMaxRua);

const char* getSenha(const int tamanhoMaxSenha);

const char* getTelefone(const int tamanhoTelefone, const int ajusteTamanhoStr);

const char* getUsuario(const int tamanhoMaxUsuario);

int login(const char* user, const int tamanhoMaxUsuario, const char* password, const int tamanhoMaxSenha);

void printfColorido(const char* texto, int cor);

int salvarArquivoPaciente(const char* nome, const char* cpf, const char* telefone, const char* rua,
                          const char* numero, const char* complemento, const char* bairro, const char* cidade, const char* estado,
                          const char* cep, const char* dataNascimento, const char* email, const char* dataDiagnostico,
                          const char* comorbidades);

void setColor(int ForgC);

int sistemaFormulario(const int tamanhoMaxNome, const int tamanhoMaxRua, const int tamanhoMaxNumero,
                      const int tamanhoMaxComplemento, const int tamanhoMaxBairroCidade,
                      const int tamanhoMaxEmail, const int tamanhoMaxComorbidades);

int sistemaLogin(const int tamanhoMaxUsuario, const int tamanhoMaxSenha);

const char* trimEspacosEmBrancoGetS(const int tamanhoMaxUsuario);

int validacaoCEP(const char* CEP, const int tamanhoCEP);

int validacaoCPF(const char* CPF, const int tamanhoCPF);

int validacaoDataDiagnostico(const char* dataDiagnostico, const int tamanhoData, const char* dataNascimento);

int validacaoDataNascimento(const char* dataNascimento, const int tamanhoData);

int validacaoEmail(const char* email, const int tamanhoMaxEmail);

int validacaoEstado(const char* estado, const int tamanhoEstado);

int validacaoNome(const char* nome);

int validacaoNumero(const char* textoNumero, const int tamanhoMaxNumero);

int validacaoTelefone(const char* telefone, const int tamanhoTelefone);

int verificaSeArquivoJaExiste(const char* cpf);
