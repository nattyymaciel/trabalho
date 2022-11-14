//libTrabalho.h é inclusa para que a função main tenha acesso às funções, registros e constantes definidos. 
#include "libTrabalho.h"

int main(){

   //=======Variáveis para cadastro na base
  char arqFisicoImagensBase[] = "arqFisicoImagensBase.bin";
  int id;// é diferente do id q esta no registro, serve para achar o registro desejado
  char nomeImagem[MAX_NAME];  


   //======Variáveis para operações sobre imagens	
   int opt = 1, lin, col, maxval, gravou;
   char *tipo, *nomeArqSaida;
   int **matImagem; 
   char *auxNomeImagem;
   Imagem img;
  
  do{	  
     //Função que mostra as opções para o usuário ao executar o programa	  
     menuOperacoes();
     scanf("%d", &opt);



     
     switch (opt){
	     case 0:printf("Encerrando o sistema.\n");
		    break;
	     //===listaImagens	    
	     case 1: //listaImagens
		 	listaImagens(arqFisicoImagensBase);
  		    break; 
	     //===cadastraImagem	    
	     case 2:
		    //cadastraImagem
			printf("\nDigite o nome da imagem:\n");
			auxNomeImagem=alocaString(MAX_NAME);
   			scanf(" %s", auxNomeImagem);
			int imagemExiste = verificaExistenciaDeImagem(auxNomeImagem);
			if (imagemExiste==1) {
				cadastraImagem(arqFisicoImagensBase, auxNomeImagem);
				int retorno;
				if(retorno==0){
					printf("\nImagem cadastrada com sucesso ESSE VEM DA MAIN.\n");
				}
				else{
					printf("\nErro em cadastrar imagem ESSE VEM DA MAIN\n");
				}
			} 
			else {
				printf("\nA imagem não existe no diretorio\n");
			}
			free(auxNomeImagem);
		    break;
             //===alteraImagem		    
	     case 3:
		 	printf("\nDigite a ID da imagem a ser alterada:\n");
			scanf("%d",&id);
			alteraImagem(arqFisicoImagensBase, id);
		    break; 
             //===removeImagem 		    
	     case 4: 
		 	printf("\nDigite a ID da imagem a remover: ");
		    scanf("%d",&id);
		    removeImagem(arqFisicoImagensBase, id);
		    break;  
             //===Binarizar		    
	     case 5: 
		 	printf("\nDigite o nome da imagem a ser binarizada:\n");
			auxNomeImagem=alocaString(MAX_NAME);
			scanf("\n%[^\n]s", auxNomeImagem);
			int nomeExiste=verificaCadastro(arqFisicoImagensBase, auxNomeImagem);
			//aloca string tipo (p2)
			tipo = alocaString(MAX_NAME);
			//le arquivo imagem
			matImagem = leArquivoImagem (auxNomeImagem, tipo, &lin, &col, &maxval);
			
			//verificar o nome escolhido
			
			printf("\nDigite o novo nome de saida do arquivo modificado:\n");
			nomeArqSaida = alocaString(MAX_NAME);
			scanf("%s",nomeArqSaida);
			nomeExiste=verificaCadastro(arqFisicoImagensBase, nomeArqSaida);
			while(nomeExiste!=0){
				printf("\nDigite o nome da imagem a ser binarizada: \n");
				scanf("%s", nomeArqSaida);
			}
			//realizar o binarizar
			binarizar(matImagem, lin, col);
			//grava imagem
			gravaImagem(nomeArqSaida, tipo, lin, col, maxval, matImagem);

			//desalocar matriz 
			desalocaMatrizImagem(matImagem, lin, col);
			free(auxNomeImagem);
			

		 //binarizar(matImagem, lin, col);
		   break;
	     //===Ruído  	   
	     case 6:  //ruido(matImagem, lin, col);	
		   break;
	      //===Negativo 	   
	     case 7: //negativo(matImagem, lin, col);	
		   break;
	     //====Espelhamento	    
	     case 8: //espelhar(matImagem, lin, col);	
		   break;		    
	     default: printf("\nOpção inválida");
     }

  }while (opt != 0);

  return 0;
}
