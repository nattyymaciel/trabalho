#include "libTrabalho.h"

int cadastraImagem(char arqFisicoImagensBase[], char nomeImagem[]){
      
   
   int retorno;
   Imagem img;
   retorno=verificaCadastro(arqFisicoImagensBase, nomeImagem);

   if(retorno==1){
      printf("\nJa existe uma imagem com este nome no arquivo.\n");
   }else if(retorno==0){

      strcpy(img.nome, nomeImagem);

      gravaInfoImagem(arqFisicoImagensBase, img);
      printf("\nImagem cadastrada no arquivo com sucesso.\n");
      return 0;
   }else{
      printf("\nErro em realizar o cadastro.\n");
   }

   
   return 1;
}
