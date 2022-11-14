#include "libTrabalho.h"

int gravaInfoImagem(char arqFisicoImagensBase[], Imagem img){

   FILE *arqFisicoImagem = fopen(arqFisicoImagensBase, "a+b");
   if(arqFisicoImagem == NULL){
      printf("\nErro na leitura do arquivo. Execução finalizada.\n");
      return 0;
   }
   int num=0, i, j;
   //pegar ultimo id registrado
   img.id=getLastId(arqFisicoImagensBase);
   //como é novo cadastro, add mais 1 ao id ja existente
   img.id++;
   char *tipo = img.tipo;
   getExtension(img.nome, &tipo);
   img.size=getSize(img.nome);
   int altura;
   int largura=getDimension(img.nome, &altura);
   img.dimensao.largura=largura;
   img.dimensao.altura=altura;
   char dono[MAX_NAME];
   printf("Digite o nome do dono da imagem:\n");
   scanf(" %s", dono);
   for (j=0; dono[j]!='\0'; j++) {
      img.proprietario[j]=dono[j];
   }
   img.proprietario[j]='\0';
      //Para pegar/usar data do sistema
      //descomentar código a seguir
   struct tm tm =getSystemTime();
   img.data_criacao.dia = img.data_modificacao.dia = tm.tm_mday;
   img.data_criacao.mes = img.data_modificacao.mes = tm.tm_mon + 1;
   img.data_criacao.ano = img.data_modificacao.ano = tm.tm_year + 1900;   
   fwrite(&img, sizeof(Imagem), 1, arqFisicoImagem);
   fclose(arqFisicoImagem);


   return 0;
}
