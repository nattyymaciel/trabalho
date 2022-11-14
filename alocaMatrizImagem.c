#include "libTrabalho.h"

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
   //desalocaMatrizImagem(mat, lin, col);
   return mat;
}
