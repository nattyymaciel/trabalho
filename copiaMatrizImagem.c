#include "libTrabalho.h"
/*A função realiza a copia da matriz original para que possa ser realizada operações sobre a matriz.
Usada para espelhar a matriz.
*/
void copiaMatrizImagem (int **mat, int **matCopia, int lin, int col){

   int i, j;
   
   for(i=0; i<lin; i++){
      for(j=0; j<col; j++){
         matCopia[i][j]=mat[i][j];
      }
   }
}
