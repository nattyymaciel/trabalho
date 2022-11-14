#include "libTrabalho.h"

/****** Completar *****/
void copiaMatrizImagem (int **mat, int **matCopia, int lin, int col){
   int i, j;

   for(i=0; i<lin; i++){
      for(j=0; j<col; j++){
         matCopia[i][j]=mat[i][j];
      }
   }
}
