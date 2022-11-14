#include "libTrabalho.h"
/*Inicialmente foi alocada memoria determinada pela qantida de linhas da matriz,
onde, se ocorrer algum erro, ira aparecer a mensagem de erro.
Em seguida foi realizado a alocação de memoria para as colunas relacionadas às linhas 
anteriormente alocadas. Foi determinado que se nesta segunda etapa ocorrer algum erro, 
a matriz será desalocada.
*/

int **alocaMatrizImagem (int lin, int col){

   int i; 
   int **mat;
   
   mat=(int**)malloc(lin*sizeof(int*));
   if (mat== NULL){
      printf("\n Ocorreu erro em alocar matriz.\n");
      return 0;
   }
   for(i=0; i<lin; i++){
      mat[i]=(int*)malloc(col*sizeof(int));
      if(mat[i]==NULL){
         desalocaMatrizImagem(mat, lin, col);
         return 0;

      }
   }
   return mat;
}
