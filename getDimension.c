#include "libTrabalho.h"
/*A função vai ler os dados do arquivo e armzenar em variaveis os valores de tipo, largura, altura e maxVal
*/
int getDimension( char nomeImagem[], int *pAltura){
	
	int largura;
	Imagem img;
	
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
