/*------------------------------------------------------------------------------
                                "buffer.h"
                                ----------
         
           No arquivo "buffer.h" contem os  procedimentos de controle
	      e  armazenamento, tambem as  variaveis utilizadas.
         Para que o Analizador Lexico possa varrer todo o  arquivo  e
         retornar os tokens encontrados...


         - char ProximoCaracter.:
         ------------------------
           Tem  a  finalidade  de fazer a leitura do vetor e retornar o
         proximo caracter armazenado no vetor.

         - typedef struct token.:
         ------------------------
         Um registro do tipo token, no qual armazenar as
         informacoes dos tokens encontrados no arquivo como:
           	- Classe  .: Para que classe o token pertence.
            - Valor   .: Lexema encontrado.
            - PosicaoL.: Em que linha foi encontrado.

------------------------------------------------------------------------------*/
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctype.h>

using namespace std;
/*----------------------------------------------------------------------------*/



/*---------------------------Definindo tipo-----------------------------------*/
	typedef struct token	{
                   			int classe;//Classe do token
   					 			char valor[100];//Lexema
                   			int posicaoL;//Linha do lexema
                    		}token;
/*----------------------------------------------------------------------------*/

  

/*-------------------------Declarando variaveis-------------------------------*/
   char c;//Recebe o caracter para ser analizado
	int linha = 1;//Contador de linha
	int InicioDeLexema = 0;//Ponteiro para localizar o inicio do Lexema
	int ApontadorAdiante = 0;//Ponteiro para localizar o fim do Lexema
	char *vetor;//Ponteiro para o vetor que armazena o arquivo
/*----------------------------------------------------------------------------*/



/*------------------------Inicio void arquivo---------------------------------*/
char arquivo(char* nome_arquivo)
{


      FILE *arquivo;//Ponteiro do arquivo
      char letra;//Recebe caracteres lido do arquivo
      int bloco = 0;//Contador de coluna
      int aux=0;//Auxilia na insersao de dados no vetor


      //Abre o arquivo somente para leitura
      /*-------------------------------------------
      Se o arquivo nao for encontrado ou nao puder
      ser aberto retornara um mensagem de erro
      --------------------------------------------*/
      if((arquivo = fopen(nome_arquivo,"r")) == NULL){
          cout << "Erro na Abertura do Arquivo" << endl;
          cout << "Verifique se o endereco do arquivo foi degitado corretamente" << endl;
      }

      
      //Ler caracter por caracter do arquivo
      while((letra = getc(arquivo)) != EOF)
      {
         bloco++;//Conta quantos caracter contem no arquivo...
      }

      /*--------------------------------------------
      Alocando vetor dinamicamente com a quantidade
          de caracter que contem no arquivo
      --------------------------------------------*/
      vetor = new char[bloco];

      //Limpando o vetor
      for(int l = 0; l < bloco; l++)
      		vetor[l] = NULL;


      //Retorna o ponteiro ao inicio do arquivo
      rewind(arquivo);

      
      //Laco caracter por caracter do arquivo
      while((letra = getc(arquivo)) != EOF)
      {
      	//Insere caracter por caracter no vetor
         vetor[aux] = letra;
         aux++;
      }

      //Insere '\0' no final do vetor para
      //que possa identificar o final.
      vetor[bloco] = '\0';

      fclose(arquivo);
}
/*---------------------------Fim void arquivo---------------------------------*/



/*---------------------Inicio void ProximoCaracter----------------------------*/
char ProximoCaracter ( )
{
     c = vetor[ApontadorAdiante++];//Incremento da posição do vetor

     if (c == '\n')
    	linha++;

    return c;//Retorna o caracter do vetor
}
/*------------------------Fim void ProximoCaracter----------------------------*/
