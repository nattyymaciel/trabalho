//libTrabalho.h é inclusa para que a função main tenha acesso às funções, registros e constantes definidos. 
#include "libTrabalho.h"

int main(){

   //=======Variáveis para cadastro na base
  char arqFisicoImagensBase[] = "arqFisicoImagensBase.bin";
  int id;//é diferente do ID q esta no registro, serve para achar o registro desejado comparando com o ID armazenado no cadastro
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
	    case 1: //chamando a função listaImagens passando o arquivo de dados de imagem como parametro
		 	listaImagens(arqFisicoImagensBase);
  		    break; 
	    case 2:/*chamando a função cadastraImagem, para isso primeiro verificamos a existencia de imagem com o 
				nome digitado no diretorio, se não exitir a imagem o usuario é informado, se existir chamamos a 
				função cadastraImagem(demais informações sobre o processo de cadastro está na propria função cadastraImagem).
				*/
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
	    case 3:/*chamada da função de alteração do cadastro com base no ID referente a imagem desejada.*/
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
	    case 5:/*Para o processo de binarização da imagem, primeiro é solicitado o nome da imagem(que deve existir já),
		que será binarizada, para isso vamos chamar o alocaString para o auxNomeImagem, e então captado do teclado o nome,
		em seguida verificamos a existencia do cadastro, pois se existe, podemos realizar a binarização. Como vamos usar 
		o tipo P2 na montagem do arquivo da imagem modificado, vamos também alocar string para o tipo. Em seguida lemos o
		arquivo, onde os dados serão salvos em matImagem.
		Após termos a matriz disponivel, vamos verificar o nome da NOVA imagem, que NÃO pode existir no diretorio, portanto
		verificamos o cadastro novamente e nos certificamos que o nome escolhido não existe no diretorio. Quando garantimos
		que o nome não existe e está disponivel para uso ai sim podemos realizar a operação sobre a imagem, salvar a imagem
		modificada do diretorio e seus dados em garavaInfoImagem.
		Ao final como a imagem ja está salva e seus dados também, desalocamos a matriz e a string de auxNomeImagem*/
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
		   	break;
	    case 6:  //ruido(matImagem, lin, col);	
			printf("\nDigite o nome da imagem a ser adicionado ruido:\n");
			auxNomeImagem = alocaString(MAX_NAME);
			scanf("\n%[^\n]s", auxNomeImagem);
			nomeExiste=verificaCadastro(arqFisicoImagensBase, auxNomeImagem);

			//aloca string tipo (p2)
			tipo = alocaString(MAX_NAME);

			//le arquivo imagem
			matImagem = leArquivoImagem (auxNomeImagem, tipo, &lin, &col, &maxval);

			//gravar arquivo de saida 
			printf("\nDigite o novo nome de saida do arquivo modificado:\n");
			nomeArqSaida = alocaString(MAX_NAME);
			scanf("%s",nomeArqSaida);

			//verificar o nome escolhido	
			nomeExiste=verificaCadastro(arqFisicoImagensBase, nomeArqSaida);
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
		default: printf("\nOpção inválida\n");
	}

	}while (opt != 0);

	return 0;
}
