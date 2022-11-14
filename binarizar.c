#include "libTrabalho.h"
/*Para binarizar a matriz foi realizado um ciclo for, onde se o valor do indice fosse maior ou igual a 127,
o valor no indice será substituido por 255, se não, seu valor será 0.
*/

void binarizar (int **mat, int lin, int col){
    int i,j;
    //binarização da matriz (mat[i][j], lin, col);
    for(i=0; i<lin; i++){
        for(j=0; j<col; j++){
            if(mat[i][j]>=127){
                mat[i][j]= 255;
            }
            else{
                mat[i][j]=0;
            }
        }
    }
}
