#include "libTrabalho.h"
/*A função irá realizar a subtração do valor armazenado na matriz no determinado indice de 255.
Por ser uma matriz, o processo foi realizado em um ciclo for dentro de outro ciclo for.
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
