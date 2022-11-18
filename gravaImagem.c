#include "libTrabalho.h"
/*A funcão vai abrir o arquivo e "captar" os novos dados da imagem que foi criada com
 base na imagem original.
*/

int gravaImagem (char *nomeArqSaida, char *tipo, int lin, int col, int maxval, int **mat){

   FILE *imagemComOperacoes = fopen(nomeArqSaida, "a+b");
   if(imagemComOperacoes == NULL){
      printf("\nErro ao abrir arquivo de imagens com operações. Execução finalizada.\n");
      return 1;
   }

   fprintf(imagemComOperacoes, "%s\n", tipo);
   fprintf(imagemComOperacoes, "%d %d\n", col, lin);
   fprintf(imagemComOperacoes, "%d\n", maxval);

   int i,j;

   for(i=0; i<lin; i++){
      for(j=0; j<col; j++){
        fprintf(imagemComOperacoes, "%d ", mat[i][j]);// não esquecer o espaço após o %d para que o arquivo 
        //tenha espaçamento entre os numeros de pixels, se esquecer ele nâo vai ler corretamente
      }
   }
   
   fclose(imagemComOperacoes);
   return 0;
}
