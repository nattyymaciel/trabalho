#include "libTrabalho.h"
/*A função verifica os IDs cadastrados no arquivo, a partir do ultimo id é atribuido ao proximo  
cadastro a ID seguinte
*/

int getLastId(char arqFisicoImagensBase[]){
   
   Imagem img;
   int lastId = 0;
   int num=0;
   
   FILE *arqFisicoImagem = fopen(arqFisicoImagensBase, "a+b");
   if(arqFisicoImagem == NULL){
      printf("\nErro\n");
      return 0;
   }
   while (fread(&img,sizeof(Imagem),1,arqFisicoImagem)!=0) 
   {
      num++;
   }
   fseek(arqFisicoImagem, num*sizeof(Imagem), SEEK_END);
   lastId = img.id;
      
   rewind(arqFisicoImagem);
   fclose(arqFisicoImagem);


   return lastId;
}
