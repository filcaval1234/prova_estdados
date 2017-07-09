#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//enum complemento {apartamento, casa};

struct imovel{
	char bairro[20];
	double preco;
	int vagasDeGaragem;
	double tamanhoPrivativo;
	enum {apartamento, casa} tipoDoImovel;
};
typedef struct imovel Imovel;
int main(void){
	int tamanho = 1;
	Imovel vetor_imovel[tamanho];
	int i=0;
	char tiposImoveis[1][12];
	
	for(;i<tamanho;i++){
		printf("Informe o Bairro: \n");
		scanf("%s",vetor_imovel[i].bairro);
		printf("Informe o preco do imovel: \n");
		scanf("%d",&vetor_imovel[i].preco);
		printf("Informe o numero de vagas na garagem da casa: \n");
		scanf("%d",&vetor_imovel[i].vagasDeGaragem);
		printf("Informe o tamanho da area do imovel: \n");
		scanf("%d",&vetor_imovel[i].tamanhoPrivativo);
		printf("Informe o tipo do imovel(0-apartamento ou 1-casa): \n");
		scanf("%d",&vetor_imovel[i].tipoDoImovel);
		
		switch(vetor_imovel[i].tipoDoImovel){
			case apartamento:
				strcpy(tiposImoveis[i],"apartamento");
				break;
			case casa:
				strcpy(tiposImoveis[i],"casa");
				break;
			default: printf("Tipo de imovel invalido. \n");
		}
	}
	
	for (i=0;i<tamanho;i++){
		printf("Tipo do imovel: %s \n", tiposImoveis[i]);
		printf("Bairro: %s \n", vetor_imovel[i].bairro);
		printf("Preco: %d \n", vetor_imovel[i].preco);
	}
	
	return 0;
}
