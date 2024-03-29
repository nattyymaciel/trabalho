#include "libTrabalho.h"
/*Ira abrir o arquivo e salvar os dados da imagem, caso não exista um arquivo, ele irá criar um para que
os dados sejam salvos, sempre irá salvar na ultima posição do arquivo.
*/

int gravaInfoImagem(char arqFisicoImagensBase[], Imagem img){

   FILE *arqFisicoImagem = fopen(arqFisicoImagensBase, "a+b");
   if(arqFisicoImagem == NULL){
      printf("\nErro na leitura do arquivo. Execução finalizada.\n");
      return 1;
   }
   int num=0, i, j;

   //pegar ultimo id registrado
   img.id=getLastId(arqFisicoImagensBase);
   //como é novo cadastro, adiciona mais 1 ao ID ja existente
   img.id++;

   char *tipo = img.tipo;
   getExtension(img.nome, &tipo);//pega o pmg do nome da imagem

   img.size=getSize(img.nome);

   int altura;
   int largura=getDimension(img.nome, &altura);//passado o endereço da altura(COL), para que localize o dado seguinte, a largura(LIN).
   img.dimensao.largura=largura;
   img.dimensao.altura=altura;

   char dono[MAX_NAME];
   printf("Digite o nome do proprietario da imagem:\n");
   scanf(" %s", dono);
   for (j=0; dono[j]!='\0'; j++) {
      img.proprietario[j]=dono[j];
   }
   img.proprietario[j]='\0';

   struct tm tm =getSystemTime();
   img.data_criacao.dia = img.data_modificacao.dia = tm.tm_mday;
   img.data_criacao.mes = img.data_modificacao.mes = tm.tm_mon + 1;
   img.data_criacao.ano = img.data_modificacao.ano = tm.tm_year + 1900;   
   
   fwrite(&img, sizeof(Imagem), 1, arqFisicoImagem);
   fclose(arqFisicoImagem);


   return 0;
}
