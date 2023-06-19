/*
** Fun��o : Criar um programa para Implementar uma pilha de n�meros reais
** Autor : Joel Adelaide Medeiros - P3 CC Unip� - RGM 29799384
** Data : 16/06/2023
** Observa��es:
*/

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <Windows.h>

#define MAX 50  //numero de max de elementos na pilha

typedef struct pilha{
	int n;                // vet[n] = primeira posi��o livre do vetor
	float vet[MAX];       // vet[n-1] = topo da pilha
} Pilha;                  // vet[0] a vet[MAX-1] = posi��es ocup�veis

Pilha* pilha_cria(void);
void pilha_push(Pilha* p, float v);
float pilha_pop(Pilha* p);
int pilha_vazia(Pilha* p);
void pilha_libera(Pilha* p);
void pilha_imprime(Pilha* p);

Pilha* pilha_cria(void){
	Pilha* p = (Pilha*)malloc(sizeof(Pilha));
	p->n=0; //inicializa com zero elementos
	return p;
}

void pilha_push(Pilha* p, float v){
	if(p->n==MAX){      // capacidade da pilha esgotada
		printf("Capacidade da pilha estourou!\n");
		exit(1);        // aborta o programa
	}
	p->vet[p->n] = v;
	p->n++;
}

float pilha_pop(Pilha* p){
	float v;
	if(pilha_vazia(p)){
		printf("Pilha vazia!\n");
		exit(1);
	}
	v = p->vet[p->n-1];
	p->n--;
	return v;
}

int pilha_vazia(Pilha* p){
	return (p->n==0);
}

void pilha_libera(Pilha* p){
	free(p);
}

void pilha_imprime(Pilha* p){
	printf("Pilha: ");
	int qnt = p->n;
	int i;
	
	for(i=0; i<qnt; i++){
		printf("\n%f", p[qnt]);
	}
	
	Sleep(5000);
}

int main() {
	
	setlocale(LC_ALL, "Portuguese");
	
	Pilha* nova_pilha;
	nova_pilha = pilha_cria();
	
	int op = 0;
	float valor;
	
	do
    {
    	system("cls || clear");
    	
        printf("\n-*-*-*-*-PILHA DE N�MEROS REAIS-*-*-*-*\n\n");
        printf("[1] - INSERIR (Push)\n");
        printf("[2] - RETIRAR (Pop)\n");
        printf("[3] - IMPRIMIR PILHA\n");
        printf("[0] - SAIR (Free)\n");

		printf("Op��o Desejada: ");
        scanf("%d", &op);
        printf("\n\n");
        
        switch(op)
        {
            case 1:
            	
				printf("Digite o valor a ser inserido: ");
            	scanf("%f", &valor);
            	pilha_push(nova_pilha, valor);
                break;

            case 2:
                pilha_pop(nova_pilha);
                break;
                
            case 3:
                pilha_imprime(nova_pilha);
                break;

            case 0:
            	pilha_libera(nova_pilha);
            	printf("Saindo.......");
                return 0;
                break;

            default:
                printf("Digite uma Op��o V�lida!\n");
        }
    } while(1);
	
	
	return 0;
}

