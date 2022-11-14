#include "libTrabalho.h"
/*Na função cadastraImagem foi verificada a existencia de cadastro no arquivo com o mesmo nome de 
imagem existente, se houver, não será feito o cadastro, se não houver o nome digitado na main será copiado 
para o img.nome. Em seguida será chamado o gravaInfoImagem
*/

int cadastraImagem(char arqFisicoImagensBase[], char nomeImagem[]){
      
   
   int retorno;
   Imagem img;
   retorno=verificaCadastro(arqFisicoImagensBase, nomeImagem);

   if(retorno==1){
      printf("\nJa existe uma imagem com este nome no arquivo.\n");
   }else if(retorno==0){
      strcpy(img.nome, nomeImagem);
      gravaInfoImagem(arqFisicoImagensBase, img);
      
      return 0;
   }
    
   return 1;
}
