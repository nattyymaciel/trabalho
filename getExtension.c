#include "libTrabalho.h"

void getExtension(char nomeImagem[], char* extension[]){
   int i, j, cont=0, aux=0;
   //cont representa posição de encontro do caracter ".";
   //aux representa o contador da extension;
   //encontrar a posiçao onde começa o .pgm
   for(i=0; nomeImagem[i]!='\0'; i++){
      if(nomeImagem[i]=='.'){
         cont=i+1;
         
      }
   }
   //passar p o extension o tipo da imagem a partir da posição encontrada do .pgm
   for (i=cont; nomeImagem[i]!='\0'; i++) {
      (*extension)[aux]=nomeImagem[i];
      aux++;
   }
   (*extension)[aux]='\0';   
}
