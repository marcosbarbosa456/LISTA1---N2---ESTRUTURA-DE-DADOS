#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAM_MAXIMO 100

typedef struct {
    int dia;
    int mes;
    int ano;
} Data;

typedef struct {
    char nomeCompleto[81];
    char sexo;
    Data dataNascimento;
    float altura;
    float peso;
} PerfilSaude;

void preencherPerfilSaude(PerfilSaude* perfil);
int calcularIdade(const Data* dataNascimento);
float calcularIMC(float peso, float altura);
int calcularFrequenciaCardiacaMaxima(int idade);
int calcularFrequenciaCardiacaIdeal(int frequenciaCardiacaMaxima);
int calcularExpectativaAnos(char sexo);
void exibirTabelaIMC();
void exibirPerfilSaude(const PerfilSaude* perfil);

void preencherPerfilSaude(PerfilSaude* perfil) {
    printf("Digite o nome completo: ");
    fgets(perfil->nomeCompleto, sizeof(perfil->nomeCompleto), stdin);
    perfil->nomeCompleto[strcspn(perfil->nomeCompleto, "\n")] = '\0';

    printf("Digite o sexo (M/F): ");
    scanf(" %c", &perfil->sexo);
    getchar(); // Consumir o caractere de nova linha

    printf("Digite a data de nascimento (dd/mm/aaaa): ");
    scanf("%d/%d/%d", &perfil->dataNascimento.dia, &perfil->dataNascimento.mes, &perfil->dataNascimento.ano);

    printf("Digite a altura (em metros): ");
    scanf("%f", &perfil->altura);

    printf("Digite o peso (em kg): ");
    scanf("%f", &perfil->peso);
}

int calcularIdade(const Data* dataNascimento) {
    // Obter a data atual
    Data dataAtual;
    printf("Digite a data atual (dd/mm/aaaa): ");
    scanf("%d/%d/%d", &dataAtual.dia, &dataAtual.mes, &dataAtual.ano);
    getchar(); // Consumir o caractere de nova linha

    // Calcular a idade em anos
    int idade = dataAtual.ano - dataNascimento->ano;

    // Verificar se já fez aniversário no ano atual
    if (dataNascimento->mes > dataAtual.mes || (dataNascimento->mes == dataAtual.mes && dataNascimento->dia > dataAtual.dia)) {
        idade--;
    }

    return idade;
}

float calcularIMC(float peso, float altura) {
    return peso / (altura * altura);
}

int calcularFrequenciaCardiacaMaxima(int idade) {
    return 220 - idade;
}

int calcularFrequenciaCardiacaIdeal(int frequenciaCardiacaMaxima) {
    return frequenciaCardiacaMaxima * 0.7;
}

int calcularExpectativaAnos(char sexo) {
    if (sexo == 'M' || sexo == 'm') {
        return 70;  // Expectativa de vida média para homens
    } else {
        return 75;  // Expectativa de vida média para mulheres
    }
}

void exibirTabelaIMC() {
    printf("Tabela de valores do IMC:\n");
    printf("Abaixo do peso: menor que 18.5\n");
    printf("Peso normal: 18.5 - ");
}
void exibirPerfilSaude(const PerfilSaude* perfil) {
    printf("Nome: %s\n", perfil->nomeCompleto);
    printf("Sexo: %c\n", perfil->sexo);
    printf("Data de Nascimento: %02d/%02d/%04d\n", perfil->dataNascimento.dia, perfil->dataNascimento.mes, perfil->dataNascimento.ano);
    printf("Altura: %.2f metros\n", perfil->altura);
    printf("Peso: %.2f kg\n", perfil->peso);
}

int main() {
    int N;
    printf("Digite o número de pessoas: ");
    scanf("%d", &N);
    getchar(); // Consumir o caractere de nova linha

    PerfilSaude* perfis = malloc(N * sizeof(PerfilSaude));
    if (perfis == NULL) {
        printf("Erro de alocação de memória.\n");
        return 1;
    }

    for (int i = 0; i < N; i++) {
        printf("\n--- Pessoa %d ---\n", i + 1);
        preencherPerfilSaude(&perfis[i]);
    }

    for (int i = 0; i < N; i++) {
        printf("\n--- Pessoa %d ---\n", i + 1);
        exibirPerfilSaude(&perfis[i]);

        int idade = calcularIdade(&perfis[i].dataNascimento);
        printf("Idade: %d anos\n", idade);

        float imc = calcularIMC(perfis[i].peso, perfis[i].altura);
        printf("IMC: %.2f\n", imc);

        int frequenciaMaxima = calcularFrequenciaCardiacaMaxima(idade);
        printf("Frequência Cardíaca Máxima: %d bpm\n", frequenciaMaxima);

        int frequenciaIdeal = calcularFrequenciaCardiacaIdeal(frequenciaMaxima);
        printf("Frequência Cardíaca Ideal: %d bpm\n", frequenciaIdeal);

        exibirTabelaIMC();

        int expectativaAnos = calcularExpectativaAnos(perfis[i].sexo);
        int expectativaVida = expectativaAnos - idade;
        printf("Expectativa de vida: %d anos\n", expectativaVida);
    }

    free(perfis);

    return 0;
}