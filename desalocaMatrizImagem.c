#include "libTrabalho.h"
/*A função ira desalocar a matriz após o uso, usada nas operações sobre imagem.
*/
void desalocaMatrizImagem(int **mat, int lin, int col){

   int i, j;
   
   for(i=0; i<lin; i++){
      free(mat[i]);
   }
   free(mat);
}
