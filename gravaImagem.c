#include "libTrabalho.h"

int gravaImagem (char *nomeArqSaida, char *tipo, int lin, int col, int maxval, int **mat){

   FILE *imagemComOperacoes = fopen(nomeArqSaida, "a+b");
   if(imagemComOperacoes == NULL){
      printf("\nErro ao abrir arquivo de imagens com operações. Execução finalizada.\n");
      return 1;
   }
   else{
      printf("\nArquivo aberto.\n");
   }
   fwrite(&img, sizeof(Imagem), 1, imagemComOperacoes);
   

   fclose(imagemComOperacoes);
   return 0;
}
