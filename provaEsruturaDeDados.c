#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void retornaPalavra(char * texto, char* palavr);
void maior_palavra(char *texto2, char* maiorPalavra);
void quantitativoPalavras(char* texto, int* listaDeTamanhos);
void printTabela(int* listaDeTamanhos);
int quantNumerosIguais(int* vetor1, int* vetor2, int tam1, int tam2);
void zerarLista(int* lista, int tamanho);
void questao4(char* string, int* lista, int tamanho);

int main(void){
	char string[] = "Filipe Cazuza    Cavalcanti";
	char maior[50];
	maior_palavra(string, maior);
	printf("%s", maior);
	return 0;
}

/*-----------------------------questao 2 a--------------------------------------------------*/
void maior_palavra(char *texto2, char* maiorPalavra){
	int i;
	int tamanho = 0;
	char texto[strlen(texto2)];
	strcpy(texto, texto2);
	for(i=0;i<strlen(texto);i++){
		char palavra[200] = "";
		retornaPalavra(texto, palavra);
		if(strlen(palavra) > tamanho){
			tamanho = strlen(palavra);
			strcpy(maiorPalavra, palavra);
		}
	}
}

void retornaPalavra(char * texto, char * palavr){
	char espaco = ' ';
	int i;
	int j=0;
	for(i=0;i<strlen(texto);i++){
		if(*(texto+i) != espaco){
			*(palavr+j) = *(texto+i);
			*(texto+i) = espaco;
			j++;
		}
		else if(strlen(palavr) != 0){
			break;
		} 
	}
}
/*------------------------------------questao 2 b-------------------------------------*/

void quantitativoPalavras(char* texto, int* listaDeTamanhos){
	const int tresLetras = 3, seisLetras = 6, seteLetras = 7;
	enum index_list{pos_1, pos_2, pos_3};
	int i=0;
	
	for(; i<strlen(texto);i++){
		char palavra[200] = "";
		retornaPalavra(texto, palavra);
		if(strlen(palavra) <= tresLetras && strlen(palavra) != 0){
			*(listaDeTamanhos+pos_1) += 1;
		}
		else if(strlen(palavra) <= seisLetras && strlen(palavra) != 0){
			*(listaDeTamanhos+pos_2) += 1;
		}
		else if(strlen(palavra) >= seteLetras && strlen(palavra) != 0){
			*(listaDeTamanhos+pos_3) += 1;
		} 
	}
}
void printTabela(int* listaDeTamanhos){
	printf("classe das palavras					frequencia\n");
	printf("0---3							%d\n", *(listaDeTamanhos));
	printf("4---6							%d\n", *(++listaDeTamanhos));
	printf("7---N							%d\n", *(++listaDeTamanhos));
}
/*------------------------------questao 3---------------------------------------*/
int quantNumerosIguais(int* vetor1, int* vetor2, int tam1, int tam2){
	int i,j;
	int numerosIguais = 0;
	for(i=0; i < tam1;i++){
		for(j=0; j < tam2;j++){
			if(*(vetor1+i) == *(vetor2+j)){
				numerosIguais+=1;
			}
		}
	}
	return numerosIguais;
}
/*-------------------------------questao 4----------------------------------------*/
void questao4(char* string, int* lista, int tamanho){
	char espaco = ' ';
	enum index_pos{pos_1,pos_2,pos_3};
	int i;
	zerarLista(lista, tamanho);
	for(i=0;i<strlen(string);i++){
		if(*(string+i) == espaco){
			*(lista+pos_3)+=1;
		}
		if(*(string+i) >= 65 && *(string+i) <= 90){
			*(lista+pos_1)+=1;
		}
		else if(*(string+i) >= 97 && *(string+i) <= 122){
			*(lista+pos_2)+=1;
		}
	}
}
void zerarLista(int* lista, int tamanho){
	int i=0;
	for(;i<tamanho;i++){
		*(lista+i) = 0;
	}
}
/*---------------------------questao 5-------------------------------------------------*/
struct usuario{
	char nome[30];
	char login[10];
	char senha[10];
};
typedef struct usuario Usuario;
Usuario filipe;
Usuario leandro;
char nome[30], login[10], senha[10];
strcpy(filipe.nome, "filipe");
strcpy(filipe.login, "filcaval");
strcpy(filipe.senha, "filipe123");

strcpy(leandro.nome, "leandro");
strcpy(leandro.login, "leo123");
strcpy(leandro.senha, "leo123");

printf("Digite o login do usuario: \n");
scanf("%s", login);

printf("Digite a senha do usuario: \n");
scanf("%s", senha);

if(strcmp(login, filipe.login) == 0 && strcmp(senha, filipe.senha) == 0){
	printf("Bem vindo %s", filipe.nome);
}
else if(strcmp(login, leandro.login) == 0 && strcmp(senha, leandro.senha) == 0){
	printf("Bem vindo %s", leandro.nome);
}
else printf("Usuario nao encontrado");

/*--------------------------------questao 6-------------------------------------------*/

