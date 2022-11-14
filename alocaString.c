#include "libTrabalho.h"
/*A função alocaString irá liberar a quantidade de memoria necessaria para realizar o cadastro de nome
da imagem e de seu tipo(P2).
Casso ocorra erro a mensagem "memoria insuficiente" sera exibida e não será realizada a alocação.
*/

char *alocaString (int size){
   
   char *st; 
   st=(char *) malloc (size * sizeof(char));
   if(st==NULL){
      printf("\nMemoria Insuficiente.\n");
      st=(char *) malloc (0 * sizeof(char));
   }
   
   return st;
}
