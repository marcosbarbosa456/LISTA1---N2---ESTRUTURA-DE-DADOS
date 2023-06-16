/*
** Função : Classifica os elementos de um vetor em ordem crescente
usando o algoritmo conhecido como “classificação por seleção”
** Autor : Joel Adelaide Medeiros - P3 CC Unipê - RGM 29799384
** Data : 16/06/2023
** Observações:
*/

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

void preenchimento_aleatorio_vetor(int*, int);
void ordenacao_por_selecao(int*, int);
void printar_vetor(int*, int);

int main() {
	
	setlocale(LC_ALL, "Portuguese");
	
	int tamanhoVetor;
	int *vetor;
	
	printf("Método de Classificação por seleção na linguagem C\n\n");
	printf("Digite o tamanho do vetor:");
	scanf("%d", &tamanhoVetor);
	
	vetor = (int*)malloc(tamanhoVetor*sizeof(int));
	if(vetor == NULL){
		printf("Memoria Insuficiente.\n");
		exit(1);
	}
	
	preenchimento_aleatorio_vetor(vetor, tamanhoVetor);
	printf("\nVETOR ALEATÓRIO: \n");
	printar_vetor(vetor, tamanhoVetor);
	ordenacao_por_selecao(vetor, tamanhoVetor);
	printf("VETOR ORDENADO: \n");
	printar_vetor(vetor, tamanhoVetor);
	
	return 0;
}

void preenchimento_aleatorio_vetor(int* vetor, int tamanhoVetor){
	
	srand(time(NULL));
	int i;
	
	for (i = 0; i < tamanhoVetor; i++){
		vetor[i] = (rand() % 100) + 1;
	}
}

void ordenacao_por_selecao(int* vetor, int tamanhoVetor) { 
	
	int i, j, min, aux;
	
	for (i = 0; i < (tamanhoVetor-1); i++){
		min = i;
		for (j = (i+1); j < tamanhoVetor; j++) {
			if(vetor[j] < vetor[min])
				min = j;
			}
			
			if (vetor[i] != vetor[min]) {
				aux = vetor[i];
				vetor[i] = vetor[min];
				vetor[min] = aux;
			}
	}
}

void printar_vetor(int* vetor, int tamanhoVetor) { 
	
	int i;
	
	for (i = 0; i < tamanhoVetor; i++){
		printf("%d\t", vetor[i]);
	}
	
	printf("\n\n");

}



