#include "libTrabalho.h"

/****** Completar *****/
void ruido (int **mat, int lin, int col){
   srand(time(NULL));
   int i,j;
   //ruido na matriz (mat[i][j], lin, col);
   for(i=0; i<lin; i++){
     for(j=0; j<col; j++){
         int ruido = rand() % 100;
         mat[i][j] += ruido;
         if (mat[i][j] > 255) {
            mat[i][j] = 255;
         }

      }
   }
}
