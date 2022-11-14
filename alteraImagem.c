#include "libTrabalho.h"
/*A função alteraIagem vai realizar a alteração dos dados de nome de proprietario e data de MODIFICAÇÃO
da imagem. Primeiro vamos abrir o arquivo no modo leitura e escrita, em seguida vamos ler o conteudo do 
arquivo, onde cada leitura nos fornece a posição lida(no caso a quatidade de ID), até ue encontremos
o ID desejado. Ao final da leitura rebobinamos o arquivo.
Através do fseek, seek_set, vamos até a posição do ID desejado para então realizarmos as alterações desejada.
Ao final é utilizado o fwrite para escrever no arquivo os dados modificados.
*/

int alteraImagem(char arqFisicoImagensBase[], int id){
   
   Imagem img;
   int posicao=0, i, j;// posição do id desejado
   FILE *arqFisicoImagem=fopen(arqFisicoImagensBase, "r+b");
   if(arqFisicoImagem == NULL){
      printf("\nErro no arquivo altera imagem\n");
      return 0;
   }
   
   while (fread(&img, sizeof(Imagem), 1 ,arqFisicoImagem) !=0 && id!= img.id)
   {
      posicao++;
   }
   rewind(arqFisicoImagem);
   fseek(arqFisicoImagem, posicao*sizeof(Imagem), SEEK_SET);
   
   char dono[MAX_NAME];
   printf("\n Digite o nome do novo proprietario:\n");
   scanf(" %s", dono);
   
    for (j=0; dono[j]!='\0'; j++) {
      img.proprietario[j]=dono[j];
   }
   img.proprietario[j]='\0';
   struct tm tm =getSystemTime();
   img.data_modificacao.dia = tm.tm_mday;
   img.data_modificacao.mes = tm.tm_mon + 1;
   img.data_modificacao.ano = tm.tm_year + 1900;  
   fwrite(&img, sizeof(Imagem),1, arqFisicoImagem);

   
   fclose(arqFisicoImagem);
   return 1;
}
