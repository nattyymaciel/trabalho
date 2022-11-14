#include "libTrabalho.h"

/****** Completar *****/
void listaImagens(char arqFisicoImagensBase[]){
   /****** Completar *****/
   
   FILE *arqFisicoImagem = fopen(arqFisicoImagensBase, "r");
   if(arqFisicoImagem == NULL){
      printf("\nErro\n");
   }
   
   Imagem img;
   while (fread(&img, sizeof(Imagem),1, arqFisicoImagem)!=0)
   {
      printf("\nNome: %s \t Id: %d \t Tipo: %s \t", img.nome, img.id, img.tipo);
      //apagar prints a baixo
      printf("\nproprietario: %s\n",img.proprietario);
      printf("\nsize: %d\n", img.size);
      printf("\naltura: %d\n", img.dimensao.altura);
      printf("\nlargura: %d\n", img.dimensao.largura);
      printf("\ndia %d \nmes %d \nano %d",img.data_criacao.dia, img.data_criacao.mes ,img.data_criacao.ano );
      printf("\ndia %d \nmes %d \nano %d\n",img.data_modificacao.dia, img.data_modificacao.mes ,img.data_modificacao.ano );

   }
   
   
   

   fclose(arqFisicoImagem);

      
}

