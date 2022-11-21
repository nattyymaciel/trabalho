#include "libTrabalho.h"
/*É aberto o arquivo e então lido e comparado os nomes, o nome digitado na main e os nomes existentes no arquivo, se os
nomes forem iguais é encerrado o programa, se forem diferentes então é liberado para que seja cadastrado no arquivo.
*/
int verificaCadastro(char arqFisicoImagensBase[], char nomeImagem[]){
   
   FILE *arqFisicoImagem = fopen(arqFisicoImagensBase, "rb");
      if(arqFisicoImagem == NULL){
         printf("\nArquivo vazio. Caso seja a primeira imagem a ser cadastrada, desconsiderar a mensagem.\n");
         return -1;
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
