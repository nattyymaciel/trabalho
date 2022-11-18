#include "libTrabalho.h"
/*É responsavel por realizar a leitura dos dados da imagem que já existe, ira alocar 
memoria traves da função alocaMatrizImagem que é chamada aqui, como retornarmos uma matriz aqui, o desalocamatriz
será chamado depois, para que não ter risco de desalocar a matriz que nem chegou a ser usada ainda.
*/

int **leArquivoImagem (char *nomeArqEntrada, char *tipo, int *lin, int *col, int *maxval){
   FILE *arq= fopen (nomeArqEntrada, "r");
   if(arq==NULL){
    printf("\nErro em leArquivoImagem\n");
    return NULL;
   }
   
   fscanf(arq, "%s", tipo);
   fscanf(arq, "%d", col);
   fscanf(arq, "%d", lin);
   fscanf(arq, "%d", maxval);


    int **mat= alocaMatrizImagem(*lin, *col);
    int i,j;
    for(i=0; i<(*lin); i++){
        for(j=0; j<(*col); j++){
            fscanf(arq, "%d", &mat[i][j]);
        }
    }

    fclose(arq);

    return mat;   
}

