#include "libTrabalho.h"

/*A função vai exibir em tela os dados da imagem, tentei alinhar os dados, mas como os nomes possuem quantidade
diferente de caracteres, não foi possivel
*/
void listaImagens(char arqFisicoImagensBase[]){

   FILE *arqFisicoImagem = fopen(arqFisicoImagensBase, "r");
   if(arqFisicoImagem == NULL){
      printf("\nErro. Arquivo vazio.\n");
      return ;
   }
   
   Imagem img;
   
   while (fread(&img, sizeof(Imagem),1, arqFisicoImagem)!=0)
   {
      printf("\nNome: %s \t\t Id: %d \t Tipo: %s \t", img.nome, img.id, img.tipo);
   }
   fclose(arqFisicoImagem);

      
}

