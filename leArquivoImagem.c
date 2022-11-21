#include "libTrabalho.h"
/*É responsavel por realizar a leitura dos dados da imagem que já existe, ira alocar 
memoria traves da função alocaMatrizImagem que é chamada aqui, como retornarmos uma matriz aqui, o desalocamatriz
será chamado depois, para que não ter risco de desalocar a matriz que não foi usada ainda.
*/

int **leArquivoImagem (char *nomeArqEntrada, char *tipo, int *lin, int *col, int *maxval){
   FILE *arq= fopen (nomeArqEntrada, "r");
   if(arq==NULL){
    printf("\nErro em leArquivoImagem\n");
    return NULL;
   }
   
   fscanf(arq, "%s", tipo);//primeira linha
   fscanf(arq, "%d", col);//segunda linha, primeira coluna
   fscanf(arq, "%d", lin);//segunda linha, segunda coluna
   fscanf(arq, "%d", maxval);//terceira linha


    int **mat= alocaMatrizImagem(*lin, *col);
    int i,j;
    //captura da matriz dado a dado, primeiro indice da primeira linha, em seguida todos os indices da coluna deste indice,
    //ao acabar, passa para o segundo indice da primeira linha, e assim até o final da matriz.
    for(i=0; i<(*lin); i++){
        for(j=0; j<(*col); j++){
            fscanf(arq, "%d", &mat[i][j]);
        }
    }

    fclose(arq);

    return mat;   
}

