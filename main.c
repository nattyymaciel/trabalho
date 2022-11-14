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
					printf("\nImagem cadastrada com sucesso.\n");
				}
				else{
					printf("\nErro ao cadastrar imagem \n");
				}
			} 
			else{
				printf("\nA imagem não existe no diretorio\n");
			}
			free(auxNomeImagem);
		    break;
             //===alteraImagem		    
	     case 3:
		 	printf("\nDigite a ID da imagem a ser alterada:\n");
			scanf("%d",&id);
			int alterou;
			alterou=alteraImagem(arqFisicoImagensBase, id);
			
			if(alterou=0){
				printf("\nNão foi possivel alterar os dados da imagem.\n");
			}
			else{
				printf("\nAlteração realizada com sucesso.\n");
			}
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
			//verificar o nome escolhido	
			while(nomeExiste!=0){
				printf("\nDigite o nome da imagem a ser binarizada: \n");
				scanf("%s", nomeArqSaida);
			}
			//realizar o binarizar
			binarizar(matImagem, lin, col);
			//grava imagem
			gravou=gravaImagem(nomeArqSaida, tipo, lin, col, maxval, matImagem);
			if(gravou!=0){
				printf("\nErro ao gravar imagem.\n");
			}
			else{
				img=getImage(arqFisicoImagensBase, auxNomeImagem);
				strcpy(img.nome, nomeArqSaida);
				int gravaInfo=gravaInfoImagem(arqFisicoImagensBase, img);
				if(gravaInfo!=0){
					printf("\nErro em gravar informações da imagem.\n");
				}
				else{
					printf("\nOperação de binarização realizada com sucesso.\n");
				}
			}
			//desalocar matriz 
			desalocaMatrizImagem(matImagem, lin, col);
			free(auxNomeImagem);
		 	//binarizar(matImagem, lin, col);
		   	break;
	     	//===Ruído  	   
	     case 6:  //ruido(matImagem, lin, col);	
			printf("\nDigite o nome da imagem a ser adicionado ruido:\n");
			auxNomeImagem = alocaString(MAX_NAME);
			scanf("\n%[^\n]s", auxNomeImagem);
			nomeExiste=verificaCadastro(arqFisicoImagensBase, auxNomeImagem);
			//aloca string tipo (p2)
			tipo = alocaString(MAX_NAME);
			//le arquivo imagem
			matImagem = leArquivoImagem (auxNomeImagem, tipo, &lin, &col, &maxval);
			printf("\nDigite o novo nome de saida do arquivo modificado:\n");
			nomeArqSaida = alocaString(MAX_NAME);
			scanf("%s",nomeArqSaida);
			nomeExiste=verificaCadastro(arqFisicoImagensBase, nomeArqSaida);
			//verificar o nome escolhido	
			while(nomeExiste!=0){
				printf("\nDigite o nome da imagem a ser binarizada: \n");
				scanf("%s", nomeArqSaida);
			}
			//realizar o ruido sobre a imagem
			ruido(matImagem, lin, col);
			//grava imagem
			gravou=gravaImagem(nomeArqSaida, tipo, lin, col, maxval, matImagem);
			if(gravou!=0){
				printf("\nErro ao gravar imagem.\n");
			}
			else{
				img=getImage(arqFisicoImagensBase, auxNomeImagem);
				strcpy(img.nome, nomeArqSaida);
				int gravaInfo=gravaInfoImagem(arqFisicoImagensBase, img);
				if(gravaInfo!=0){
					printf("\nErro em gravar informações da imagem.\n");
				}
				else{
					printf("\nRuido sobre a imagem  realizada com sucesso.\n");

				}
			}
			//desalocar matriz 
			desalocaMatrizImagem(matImagem, lin, col);
			free(auxNomeImagem);
		   	break;
	      //===Negativo 	   
	     case 7: //negativo(matImagem, lin, col);
		 	printf("\nDigite o nome da imagem a ser transformada em negativa:\n");
			auxNomeImagem = alocaString(MAX_NAME);
			scanf("\n%[^\n]s", auxNomeImagem);
			nomeExiste=verificaCadastro(arqFisicoImagensBase, auxNomeImagem);
			//aloca string tipo (p2)
			tipo = alocaString(MAX_NAME);
			//le arquivo imagem
			matImagem = leArquivoImagem (auxNomeImagem, tipo, &lin, &col, &maxval);
			printf("\nDigite o novo nome de saida do arquivo modificado:\n");
			nomeArqSaida = alocaString(MAX_NAME);
			scanf("%s",nomeArqSaida);
			nomeExiste=verificaCadastro(arqFisicoImagensBase, nomeArqSaida);
			//verificar o nome escolhido	
			while(nomeExiste!=0){
				printf("\nDigite o nome da imagem a ser binarizada: \n");
				scanf("%s", nomeArqSaida);
			}
			//realizar o nagativo na imagem
			negativo(matImagem, lin, col);
			//grava imagem
			gravou = gravaImagem(nomeArqSaida, tipo, lin, col, maxval, matImagem);
			if(gravou!=0){
				printf("\nErro ao gravar imagem.\n");
			}
			else{
				img=getImage(arqFisicoImagensBase, auxNomeImagem);
				strcpy(img.nome, nomeArqSaida);
				int gravaInfo=gravaInfoImagem(arqFisicoImagensBase, img);
				if(gravaInfo!=0){
					printf("\nErro em gravar informações da imagem.\n");
				}
				else{
					printf("\nOperação de negativar a imagem  realizada com sucesso.\n");
				}
			}
			//desalocar matriz 
			desalocaMatrizImagem(matImagem, lin, col);
			free(auxNomeImagem);	
		   	break;
	     //====Espelhamento	    
	     case 8: //espelhar(matCop, lin, col);	
			printf("\nDigite o nome da imagem a ser espelhada:\n");
			auxNomeImagem = alocaString(MAX_NAME);
			scanf("\n%[^\n]s", auxNomeImagem);
			nomeExiste=verificaCadastro(arqFisicoImagensBase, auxNomeImagem);
			//aloca string tipo (p2)
			tipo = alocaString(MAX_NAME);
			//le arquivo imagem
			matImagem = leArquivoImagem (auxNomeImagem, tipo, &lin, &col, &maxval);
			printf("\nDigite o novo nome de saida do arquivo modificado:\n");
			nomeArqSaida = alocaString(MAX_NAME);
			scanf("%s",nomeArqSaida);
			nomeExiste=verificaCadastro(arqFisicoImagensBase, nomeArqSaida);
			//verificar o nome escolhido	
			while(nomeExiste!=0){
				printf("\nDigite o nome da imagem a ser binarizada: \n");
				scanf("%s", nomeArqSaida);
			}
			//espelhar a imagem
			int **matCop= alocaMatrizImagem(lin, col);
   			copiaMatrizImagem (matImagem, matCop, lin, col);
			espelhar(matCop, lin, col);
			//grava imagem
			gravou=gravaImagem(nomeArqSaida, tipo, lin, col, maxval, matCop);
			if(gravou!=0){
				printf("\nErro ao gravar imagem.\n");
			}
			else{
				img=getImage(arqFisicoImagensBase, auxNomeImagem);
				strcpy(img.nome, nomeArqSaida);
				int gravaInfo=gravaInfoImagem(arqFisicoImagensBase, img);
				if(gravaInfo!=0){
					printf("\nErro em gravar informações da imagem.\n");
				}
				else{
					printf("\nOperação de espelhar a imagem  realizada com sucesso.\n");
				}
			}
			//desalocar matriz 
			desalocaMatrizImagem(matCop, lin, col);
			free(auxNomeImagem);
		   	break;		    
	     default: printf("\nOpção inválida");
     }

  }while (opt != 0);

  return 0;
}
