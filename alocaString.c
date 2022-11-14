#include "libTrabalho.h"


char *alocaString (int size){
   
   char *st; 
   st=(char *) malloc (size * sizeof(char));
   if(st==NULL){
      printf("\nMemoria Insuficiente.\n");
      st=(char *) malloc (0 * sizeof(char));
   }
   
   return st;
}
