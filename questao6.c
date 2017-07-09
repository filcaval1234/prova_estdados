#include <stdio.h>
#include <stdlib.h>
#include <string.h>

union numero{
	int idade;
	char cpf[12]; 
};
typedef union numero Numero;

struct empregado{
	char matricula[10];
	char nome[50];
	Numero number;	
};
typedef struct empregado Empregado;
int verifica123(char* matricula);
void retornaInformacao(Empregado* empregados);

int main(void){
	int i=0;
	char nome[50], matricula[10], cpf[12];
	int idade;
	Empregado empregados[3];
	
	for(;i<3;i++){
		printf("Digite o nome: ");
		scanf("%s", empregados[i].nome);
		printf("digite a matricula de %s", empregados[i].nome);
		scanf("%s", empregados[i].matricula);
		if(verifica123(empregados[i].matricula) == 1){
			printf("digite a idade de %s", empregados[i].nome);
			scanf("%d", &empregados[i].number.idade);
		}
		else{
			printf("digite o CPF de %s", empregados[i].nome);
			scanf("%s", empregados[i].number.cpf);
		}
	}
	retornaInformacao(empregados);
	return 0;
}

int verifica123(char* matricula){
	int condicao = 1;
	int i=0;
	const char UDT[4] = "123";
	for(;i < 3;i++){
		if(*(matricula+i) == *(UDT+i)){
			continue;
		}
		else condicao = 0;
	}
	return condicao;
} 

void retornaInformacao(Empregado* empregados){
	int i=0;
	for(;i<3;i++){
		printf("Nome: %s\n",empregados[i].nome);
		printf("Matricula: %s\n", empregados[i].matricula);
		if(verifica123(empregados[i].matricula) == 1){
			printf("Idade: %d\n", empregados[i].number.idade);
		}
		else printf("CPF: %s\n", empregados[i].number.cpf);
	}
}
