#include "libTrabalho.h"
/*A função vai utilizar o ciclo for para rodar até que chegue no caracter '.' e contar em cada ciclo 
o valor de indice, para que seja armazenado o local onde a extensão irá iniciar.
Em seguida é udado um segundo for para que o ponteiro aponte para a estensão.
O ultimo indice da extension será o '\0' atribuido fora  do ciclo para que não ocorra erro.                         
*/

void getExtension(char nomeImagem[], char* extension[]){
   
   int i, j, cont=0, aux=0;
   //cont representa posição de encontro do caracter ".";
   //aux representa o contador de extension;

   //encontrar a posiçao onde começa o .pgm na string
   for(i=0; nomeImagem[i]!='\0'; i++){
      if(nomeImagem[i]=='.'){
         cont=i+1;
      }
   }
   //passar para o extension o tipo da imagem a partir da posição encontrada do .pgm
   for (i=cont; nomeImagem[i]!='\0'; i++) {
      (*extension)[aux]=nomeImagem[i];
      aux++;
   }
   (*extension)[aux]='\0';   
}
