#include "libTrabalho.h"
/*A função irá realizar o "espelhamento" da imagem, onde a matriz final irá receber a matriz original com
a coluna final sendo a coluna final menos o indice j
*/
void espelhar (int **mat, int lin, int col){
   int i, j;
   int **matAux= alocaMatrizImagem(lin, col);
   copiaMatrizImagem (mat, matAux, lin, col);
   for(i=0; i<lin; i++){
      for(j=0; j<col; j++){
         mat[i][j]=matAux[i][col-j];
      }
   } 
   desalocaMatrizImagem(matAux, lin, col);
}
