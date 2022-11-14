#include "libTrabalho.h"
/*A função irá realizar a subtração do valor armazenado na matriz em determinado indice de 255.
*/
void negativo (int **mat, int lin, int col){
   int i,j;   
   //negativo  da matriz (mat[i][j], lin, col);
   for(i=0; i<lin; i++){
      for(j=0; j<col; j++){
         mat[i][j]=255-mat[i][j];
      }
   }
}
