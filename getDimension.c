#include "libTrabalho.h"

int getDimension( char nomeImagem[], int *pAltura){
	
	int largura;
	Imagem img;
	//vide abertura da imagem e contar qtd de colunas
	FILE *arqFisicoImagem = fopen(nomeImagem, "r");
    if(arqFisicoImagem == NULL){
    	printf("\nErroa\n");
    	return 0;
    }
	char tipo[3];
    int  maxVal;
    fscanf(arqFisicoImagem, "%s", tipo);
    fscanf(arqFisicoImagem, "%d", &largura);
    fscanf(arqFisicoImagem, "%d", pAltura);
    fscanf(arqFisicoImagem, "%d", &maxVal);


	
	fclose(arqFisicoImagem);

	return largura;
}
