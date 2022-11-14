#include "libTrabalho.h"

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
