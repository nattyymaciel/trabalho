#include "libTrabalho.h"

/****** Completar *****/
void espelhar (int **mat, int lin, int col){
   int i, j;
   int **matAux= alocaMatrizImagem(lin, col);
   copiaMatrizImagem (mat, matAux, lin, col);
   for(i=0; i<lin; i++){
      for(j=0; j<col; j++){
         mat[i][j]=matAux[i][col-j];
      }
   } 
   free(matAux);
}
