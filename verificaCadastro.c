#include "libTrabalho.h"

int verificaCadastro(char arqFisicoImagensBase[], char nomeImagem[]){
   
   FILE *arqFisicoImagem = fopen(arqFisicoImagensBase, "rb");
      if(arqFisicoImagem == NULL){
         printf("\nArquivo vazio\n");
         return 0;
      }
   Imagem img;

   int i, j;
   int retorno=0, nomeIgual;
   while (fread(&img, sizeof(Imagem), 1 ,arqFisicoImagem) !=0 && retorno==0){
      nomeIgual = 1;
      for(i=0; nomeImagem[i]!='\0', nomeIgual==1; i++){
         if(nomeImagem[i] != img.nome[i]){
            nomeIgual = 0;
         }
      }
      if (nomeIgual==1) {
         return 1;
      }
   }
   fclose(arqFisicoImagem);

   return 0;
}
