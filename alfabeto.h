/*------------------------------------------------------------------------------
                                "alfabeto.h"
                                ----------
         --------------
           No arquivo "alfabeto.h"  contem procedimentos de verficacao,
         se  os lexecemas  sao validos na linguage. 

         - int  FalhouAutomatos.:
         ------------------------
          Retorna  em   que   posicao do automato  tem  que ir para a
          proxima verificacao.

         - token ProximoToken.:
         ----------------------
             Vai   receber  o  caracter do  vetor e verificar se o
          Lexema faz parte da linguagem. Retorna o token ou erro se o
          Lexema nao fizer parte da linguagem.


         =================Criacao dos Automatos===================
         |                                                       |
		 |	  Sao criados  automatos finitos  deterministicos    |
         |    para cada  padrao  de  token  da linguagem MLN    |
         |                                                       |
         =========================================================

              "  Comentario "
			0 ------> 1 -------> 2

            i      f
         3 ---> 4 ---> 5

            s      t      e      p
         6 ---> 7 ---> 8 ---> 9 ---> 10

             e       l       s       e
         11 ---> 12 ---> 13 ---> 14 ---> 15

             f       o       r
         16 ---> 17 ---> 18 ---> 19

             s       t       r       i       n       g
         20 ---> 21 ---> 22 ---> 23 ---> 24 ---> 25 ---> 26

             p       r       i       n       t
         27 ---> 28 ---> 29 ---> 30 ---> 31 ---> 32

             r       e       a       d
         33 ---> 34 ---> 35 ---> 36 ---> 37

             t       o       
         38 ---> 39 ---> 40
         
		 	  n		  u		  m
		  41 ---> 42 ---> 43 ---> 44

			 r  	 e		 t		 u		 r		 n
		 45 ---> 46 ---> 47 ---> 48 ---> 49 ---> 50 ---> 51
		 
		     s       q       r      t
		 52 ---> 53 ---> 54 ---> 55 ---> 56
		 
             +
         57 ---> 58

             -
         59 ---> 60

             *
         61 ---> 62

             /
         63 ---> 64

             =
         65 ---> 66

             <
         67 ---> 68
         
             >
         69 ---> 70  

             (
         71 ---> 72

             )
         73 ---> 74

             ;
         75 ---> 76

             :  
         77 ---> 78
         
             %
         79 ---> 80
             
            [0...9]+     [0...9]+     outro
         81 --------------> 82 -------------> 83

            [a...z]+     [a...z]+   [0...9]+    [0...9]+    outro
         84 --------------> 85 ------------------> 86 ------------> 87

         	 \0
         88 ----> 89    //Final de sentenca

        Erro
         90
   
------------------------------------------------------------------------------*/

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

using namespace std;
/*----------------------------------------------------------------------------*/




/*---------------------Inicio int FalhouAutomatos-----------------------------*/
int FalhouAutomatos (int &partida)
{
	switch(partida)
   {
   		 case  0: return  3; //comentario
   		 case  3: return  6; //if
         case  6: return 11; //step
         case 11: return 16; //else
         case 16: return 20; //for
         case 20: return 27; //string
         case 27: return 33; //print
         case 33: return 38; //read
         case 38: return 41; //to
         case 41: return 45; //num
         case 45: return 52; // return
         case 52: return 57; //sqrt
         case 57: return 59; // +
         case 59: return 61; // -
         case 61: return 63; // *
         case 63: return 65; // /
         case 65: return 67; // =
         case 67: return 69; // <
         case 69: return 71; // >
         case 71: return 73; // (
         case 73: return 75; // )
         case 75: return 77; // ;
         case 77: return 79; // :
         case 79: return 81; // %
         case 81: return 84; // numero
         case 84: return 88; //Identificador e final
         default: return 90;//Retorna Erro
   }
}
/*-----------------------Fim int FalhouAutomatos------------------------------*/



/*---------------------Inicio token ProximoToken()----------------------------*/
token ProximoToken ()
{
  	//Declarando Variaveis
  	token t;//Declarando token de retorno
  	int p;//Contador auxiliar
   int estado = 0;//Auxilia Posiciona as comparações
  	int partida = 0;//Posiciona as comparações
  	int pos = 0;//Variavel contadora aux for

  //Limpando o vetor que recebo o Lexema
  for(p = 0; p < 100; p++)
  {
  		t.valor[p] = NULL;
  }
                

   	while(1)//La�o Infinito
  		{
        switch (estado)
        {
           /*---------------Inicio "Comentario"--------------------*/
          case 0: c = ProximoCaracter ( );
                  if(isspace(c))//Verifica se é espaço em branco ,tabulação ou final de linha
                    	InicioDeLexema++;//Aponta para o início do Lexema
                  else if(c == '"') estado = 1;
                  else
                  {   //Iguala o inicio do apontador com o próximo Lexema
                      ApontadorAdiante = InicioDeLexema;
                  	 estado = partida = FalhouAutomatos(partida);
                  }
          break;



          case 1: c = ProximoCaracter ( );
          			if (c == '"' && vetor[InicioDeLexema] == '"')
                  	estado = 2;
                  if (c == '"' && vetor[InicioDeLexema] == '"')
                  {
                  	estado = 90;
                     if (vetor[ApontadorAdiante] == '\n')
                     	ApontadorAdiante--;
                  }      
                  if (c != '"' && vetor[InicioDeLexema] != '"')
                  {
                  	estado = 1;
                  }
          break;



          case 2: estado = 0;
                  InicioDeLexema = ApontadorAdiante;
			 break;
          /*------------------Fim "Comentario"---------------------*/


          /*-------------------Inicio "if"-----------------------*/
          case 3: c = ProximoCaracter ( );
          			if(c == 'i')estado = 4;
                  else
                  {   //Iguala o inicio do apontador com o próximo Lexema
                      ApontadorAdiante = InicioDeLexema;
                  	 estado = partida = FalhouAutomatos(partida);
                  }
          break;

          case 4: c = ProximoCaracter ();
          			if ((c == 'f')&&(!islower(vetor[ApontadorAdiante])))
                  	estado = 5;
                  else
                  {
                      ApontadorAdiante = InicioDeLexema;
                  	 estado = partida = FalhouAutomatos(partida);
                  }
          break;

          case 5:
          			t.classe = 1;
                  strcpy(t.valor,"if");//Retorna o Lexema
                  t.posicaoL = linha; //Linha do Lexema
                  		InicioDeLexema = ApontadorAdiante;
			 return t;
          /*-------------------Fim "if"------------------------*/



          /*-----------------Inicio "step"---------------------*/
          case 6: c = ProximoCaracter ();
          			if (c == 's')
                  	estado = 7;
                  else
                  {
                      ApontadorAdiante = InicioDeLexema;
                  	 estado = partida = FalhouAutomatos(partida);
                  }
          break;

          case 7: c = ProximoCaracter ();
          			if (c == 't')
                  	estado = 8;
                  else
                  {
                      ApontadorAdiante = InicioDeLexema;
                  	 estado = partida = FalhouAutomatos(partida);
                  }
          break;

          case 8: c = ProximoCaracter ();
          			if (c == 'e')
                  	estado = 9;
                  else
                  {
                      ApontadorAdiante = InicioDeLexema;
                  	 estado = partida = FalhouAutomatos(partida);
                  }
          break;

          case 9: c = ProximoCaracter ();
          			if ((c =='p')&&(!islower(vetor[ApontadorAdiante])))
                  	estado = 10;
                  else
                  {
                      ApontadorAdiante = InicioDeLexema;
                  	 estado = partida = FalhouAutomatos(partida);
                  }
          break;

          case 10:
          			t.classe = 2;
                  strcpy(t.valor,"step");//Retorna o Lexema
                  t.posicaoL = linha; //Linha do Lexema
                  		InicioDeLexema = ApontadorAdiante;
			 return t;
          /*-------------------Fim "step"-----------------------*/



          /*------------------Inicio "else"---------------------*/
          case 11: c = ProximoCaracter ();
          			if (c == 'e')
                  	estado = 12;
                  else
                  {
                      ApontadorAdiante = InicioDeLexema;
                  	 estado = partida = FalhouAutomatos(partida);
                  }
          break;


          case 12: c = ProximoCaracter ();
          			if (c == 'l')
                  	estado = 13;
                  else
                  {
                      ApontadorAdiante = InicioDeLexema;
                  	 estado = partida = FalhouAutomatos(partida);
                  }
          break;


          case 13: c = ProximoCaracter ();
          			if (c == 's')
                  	estado = 14;
                  else
                  {
                      ApontadorAdiante = InicioDeLexema;
                  	 estado = partida = FalhouAutomatos(partida);
                  }
          break;


          case 14: c = ProximoCaracter ( );
          			if ((c =='e')&&(!islower(vetor[ApontadorAdiante])))
                  	estado = 15;
                  else
                  {
                      ApontadorAdiante = InicioDeLexema;
                  	 estado = partida = FalhouAutomatos(partida);
                  }
          break;

          case 15:
          			t.classe = 3;
                  strcpy(t.valor,"else");//Retorna o Lexema
                  t.posicaoL = linha; //Linha do Lexema
                  		InicioDeLexema = ApontadorAdiante;
			 return t;
          /*-----------------Fim "else"------------------------*/



          /*----------------Inicio "for"-----------------------*/
          case 16: c = ProximoCaracter ( );
          			if (c == 'f')
                  	estado = 17;
                  else
                  {
                      ApontadorAdiante = InicioDeLexema;
                  	 estado = partida = FalhouAutomatos(partida);
                  }
          break;


          case 17: c = ProximoCaracter ( );
          			if (c == 'o')
                  	estado = 18;
                  else
                  {
                      ApontadorAdiante = InicioDeLexema;
                  	 estado = partida = FalhouAutomatos(partida);
                  }
          break;


          case 18: c = ProximoCaracter ( );
          			if ((c =='r')&&(!islower(vetor[ApontadorAdiante])))
                  	estado = 19;
                  else
                  {
                      ApontadorAdiante = InicioDeLexema;
                  	 estado = partida = FalhouAutomatos(partida);
                  }
          break;


          case 19:
          			t.classe = 4;
                  strcpy(t.valor,"for");//Retorna o Lexema
                  t.posicaoL = linha; //Linha do Lexema
                  		InicioDeLexema = ApontadorAdiante;
  		    return t;
          /*------------------Fim "for"-------------------------*/



          /*----------------Inicio "string"---------------------*/
          case 20: c = ProximoCaracter ( );
          			if (c == 's')
                  	estado = 21;
                  else
                  {
                      ApontadorAdiante = InicioDeLexema;
                  	 estado = partida = FalhouAutomatos(partida);
                  }
          break;


          case 21: c = ProximoCaracter ( );
          			if (c == 't')
                  	estado = 22;
                  else
                  {
                      ApontadorAdiante = InicioDeLexema;
                  	 estado = partida = FalhouAutomatos(partida);
                  }
          break;


          case 22: c = ProximoCaracter ( );
          			if (c == 'r')
                  	estado = 23;
                  else
                  {
                      ApontadorAdiante = InicioDeLexema;
                  	 estado = partida = FalhouAutomatos(partida);
                  }
          break;


          case 23: c = ProximoCaracter ( );
          			if (c == 'i')
                  	estado = 24;
                  else
                  {
                      ApontadorAdiante = InicioDeLexema;
                  	 estado = partida = FalhouAutomatos(partida);
                  }
          break;


          case 24: c = ProximoCaracter ( );
          			if (c == 'n')
                  	estado = 25;
                  else
                  {
                      ApontadorAdiante = InicioDeLexema;
                  	 estado = partida = FalhouAutomatos(partida);
                  }
          break;


          case 25: c = ProximoCaracter ( );
          			if ((c == 'g')&&(!islower(vetor[ApontadorAdiante])))
                  	estado = 26;
                  else
                  {
                      ApontadorAdiante = InicioDeLexema;
                  	 estado = partida = FalhouAutomatos(partida);
                  }
          break;


          case 26:
          			t.classe = 5;
                  strcpy(t.valor,"string");//Retorna o Lexema
                  t.posicaoL = linha; //Linha do Lexema
                  		InicioDeLexema = ApontadorAdiante;
			 return t;
          /*-----------------Fim "string"-----------------------*/



          /*----------------Inicio "print"----------------------*/
          case 27: c = ProximoCaracter ( );
          			if (c == 'p')
                  	estado = 28;
                  else
                  {
                      ApontadorAdiante = InicioDeLexema;
                  	 estado = partida = FalhouAutomatos(partida);
                  }
          break;


          case 28: c = ProximoCaracter ( );
          			if (c == 'r')
                  	estado = 29;
                  else
                  {
                      ApontadorAdiante = InicioDeLexema;
                  	 estado = partida = FalhouAutomatos(partida);
                  }
          break;


          case 29: c = ProximoCaracter ( );
          			if (c == 'i')
                  	estado = 30;
                  else
                  {
                      ApontadorAdiante = InicioDeLexema;
                  	 estado = partida = FalhouAutomatos(partida);
                  }
          break;


          case 30: c = ProximoCaracter ( );
          			if (c == 'n')
                  	estado = 31;
                  else
                  {
                      ApontadorAdiante = InicioDeLexema;
                  	 estado = partida = FalhouAutomatos(partida);
                  }
          break;


          case 31: c = ProximoCaracter ( );
          			if ((c == 't')&&(!islower(vetor[ApontadorAdiante])))
                  	estado = 32;
                  else
                  {
                      ApontadorAdiante = InicioDeLexema;
                  	 estado = partida = FalhouAutomatos(partida);
                  }
          break;


          case 32:
          			t.classe = 6;
                  strcpy(t.valor,"print");//Retorna o Lexema
                  t.posicaoL = linha; //Linha do Lexema
                  		InicioDeLexema = ApontadorAdiante;
			 return t;
          /*------------------Fim "print"----------------------*/



          /*-----------------Inicio "read"---------------------*/
          case 33: c = ProximoCaracter ( );
          			if (c == 'r')
                  	estado = 34;
                  else
                  {
                      ApontadorAdiante = InicioDeLexema;
                  	 estado = partida = FalhouAutomatos(partida);
                  }
          break;

          case 34: c = ProximoCaracter ( );
          			if (c == 'e')
                  	estado = 35;
                  else
                  {
                      ApontadorAdiante = InicioDeLexema;
                  	 estado = partida = FalhouAutomatos(partida);
                  }
          break;

          case 35: c = ProximoCaracter ( );
          			if (c == 'a')
                  	estado = 36;
                  else
                  {
                      ApontadorAdiante = InicioDeLexema;
                  	 estado = partida = FalhouAutomatos(partida);
                  }
          break;

          case 36: c = ProximoCaracter ( );
          			if ((c == 'd')&&(!islower(vetor[ApontadorAdiante])))
                  	estado = 37;
                  else
                  {
                      ApontadorAdiante = InicioDeLexema;
                  	 estado = partida = FalhouAutomatos(partida);
                  }
          break;

          case 37:
						t.classe = 7;
                  strcpy(t.valor,"read");//Retorna Lexema
                  t.posicaoL = linha; //Linha do Lexema
                  		InicioDeLexema = ApontadorAdiante;
			  return t;
          /*-------------------Fim "read"-----------------------*/



          /*-----------------Inicio "to"---------------------*/
          case 38: c = ProximoCaracter ( );
          			if (c == 't')
                  	estado = 39;
                  else
                  {
                      ApontadorAdiante = InicioDeLexema;
                  	 estado = partida = FalhouAutomatos(partida);
                  }
          break;


          case 39: c = ProximoCaracter ( );
          			if (c == 'o')
                  	estado = 40;
                  else
                  {
                      ApontadorAdiante = InicioDeLexema;
                  	 estado = partida = FalhouAutomatos(partida);
                  }
          break;
          
		  case 40:
          			t.classe = 8;
                  strcpy(t.valor,"to");//Retorna o Lexema
                  t.posicaoL = linha; //Linha do Lexema
                  		InicioDeLexema = ApontadorAdiante;
			 return t;
			/*-----------------Fim "to"-----------------------*/
			
			
			
			/*-----------------Inicio "num"------------------------*/
          case 41: c = ProximoCaracter ( );
          			if (c == 'n')
                  	estado = 42;
                  else
                  {
                      ApontadorAdiante = InicioDeLexema;
                  	 estado = partida = FalhouAutomatos(partida);
                  }
          break;


          case 42: c = ProximoCaracter ( );
          			if (c == 'u')
                  	estado = 43;
                  else
                  {
                      ApontadorAdiante = InicioDeLexema;
                  	 estado = partida = FalhouAutomatos(partida);
                  }
          break;


          case 43: c = ProximoCaracter ( );
          			if ((c == 'm')&&(!islower(vetor[ApontadorAdiante])))
                  	estado = 44;
                  else
                  {
                      ApontadorAdiante = InicioDeLexema;
                  	 estado = partida = FalhouAutomatos(partida);
                  }
          break;


          case 44:
          			t.classe = 9;
                  strcpy(t.valor,"num");//Retorna o Lexema
                  t.posicaoL = linha; //Linha do Lexema
                  		InicioDeLexema = ApontadorAdiante;
			 return t;
          /*-----------------Fim "num"-----------------------*/
          
          
          
	      /*-----------------Inicio "return"------------------------*/
		  case 45: c = ProximoCaracter ( );
          			if (c == 'r')
                  	estado = 46;
                  else
                  {
                      ApontadorAdiante = InicioDeLexema;
                  	 estado = partida = FalhouAutomatos(partida);
                  }
          break;


          case 46: c = ProximoCaracter ( );
          			if (c == 'e')
                  	estado = 47;
                  else
                  {
                      ApontadorAdiante = InicioDeLexema;
                  	 estado = partida = FalhouAutomatos(partida);
                  }
          break;


          case 47: c = ProximoCaracter ( );
          			if (c == 't')
                  	estado = 48;
                  else
                  {
                      ApontadorAdiante = InicioDeLexema;
                  	 estado = partida = FalhouAutomatos(partida);
                  }
          break;


          case 48: c = ProximoCaracter ( );
          			if (c == 'u')
                  	estado = 49;
                  else
                  {
                      ApontadorAdiante = InicioDeLexema;
                  	 estado = partida = FalhouAutomatos(partida);
                  }
          break;


          case 49: c = ProximoCaracter ( );
          			if (c == 'r')
                  	estado = 50;
                  else
                  {
                      ApontadorAdiante = InicioDeLexema;
                  	 estado = partida = FalhouAutomatos(partida);
                  }
          break;


          case 50: c = ProximoCaracter ( );
          			if ((c == 'n')&&(!islower(vetor[ApontadorAdiante])))
                  	estado = 51;
                  else
                  {
                      ApontadorAdiante = InicioDeLexema;
                  	 estado = partida = FalhouAutomatos(partida);
                  }
          break;


          case 51:
          			t.classe = 10;
                  strcpy(t.valor,"return");//Retorna o Lexema
                  t.posicaoL = linha; //Linha do Lexema
                  		InicioDeLexema = ApontadorAdiante;
			 return t;
          /*-----------------Fim "return"-----------------------*/



		 /*-----------------Inicio "sqrt"------------------------*/
		  case 52: c = ProximoCaracter ( );
          			if (c == 's')
                  	estado = 53;
                  else
                  {
                      ApontadorAdiante = InicioDeLexema;
                  	 estado = partida = FalhouAutomatos(partida);
                  }
          break;


          case 53: c = ProximoCaracter ( );
          			if (c == 'q')
                  	estado = 54;
                  else
                  {
                      ApontadorAdiante = InicioDeLexema;
                  	 estado = partida = FalhouAutomatos(partida);
                  }
          break;


          case 54: c = ProximoCaracter ( );
          			if (c == 'r')
                  	estado = 55;
                  else
                  {
                      ApontadorAdiante = InicioDeLexema;
                  	 estado = partida = FalhouAutomatos(partida);
                  }
          break;


          case 55: c = ProximoCaracter ( );
          			if (c == 't')
                  	estado = 56;
                  else
                  {
                      ApontadorAdiante = InicioDeLexema;
                  	 estado = partida = FalhouAutomatos(partida);
                  }
          break;


          case 56:
          			t.classe = 10;
                  strcpy(t.valor,"sqrt");//Retorna o Lexema
                  t.posicaoL = linha; //Linha do Lexema
                  		InicioDeLexema = ApontadorAdiante;
			 return t;
          /*-----------------Fim "sqrt"-----------------------*/
          
          

          /*-----------------Inicio "+"------------------------*/
          case 57: c = ProximoCaracter ( );
          			if (c == '+')
                  	estado = 58;
                  else
                  {
                      ApontadorAdiante = InicioDeLexema;
                  	 estado = partida = FalhouAutomatos(partida);
                  }
          break;


          case 58:
          			t.classe = 11;
                  strcpy(t.valor,"+");//Retorna o Lexema
                  t.posicaoL = linha; //Linha do Lexema
                  		InicioDeLexema = ApontadorAdiante;
			 return t;
          /*------------------Fim "+"--------------------------*/



          /*-----------------Inicio "-"------------------------*/
          case 59: c = ProximoCaracter ( );
          			if (c == '-')
                  	estado = 60;
                  else
                  {
                      ApontadorAdiante = InicioDeLexema;
                  	 estado = partida = FalhouAutomatos(partida);
                  }
          break;


          case 60:
          			t.classe = 12;
                  strcpy(t.valor,"-");//Retorna o Lexema
                  t.posicaoL = linha; //Linha do Lexema
                  		InicioDeLexema = ApontadorAdiante;
			 return t;
          /*------------------Fim "-"--------------------------*/



          /*-----------------Inicio "*"------------------------*/
          case 61: c = ProximoCaracter ( );
          			if (c == '*')
                  	estado = 62;
                  else
                  {
                      ApontadorAdiante = InicioDeLexema;
                  	 estado = partida = FalhouAutomatos(partida);
                  }
          break;


          case 62:
          			t.classe = 13;
                  strcpy(t.valor,"*");//Retorna o Lexema
                  t.posicaoL = linha; //Linha do Lexema
                  		InicioDeLexema = ApontadorAdiante;
			 return t;
          /*------------------Fim "*"--------------------------*/



          /*-----------------Inicio "/"------------------------*/
          case 63: c = ProximoCaracter ( );
          			if (c == '/')
                  	estado = 64;
                  else
                  {
                      ApontadorAdiante = InicioDeLexema;
                  	 estado = partida = FalhouAutomatos(partida);
                  }
          break;


          case 64:
          			t.classe = 14;
                  strcpy(t.valor,"/");//Retorna o Lexema
                  t.posicaoL = linha; //Linha do Lexema
                  		InicioDeLexema = ApontadorAdiante;
			 return t;
          /*------------------Fim "/"--------------------------*/



          /*-----------------Inicio "="------------------------*/
          case 65: c = ProximoCaracter ( );
          			if (c == '=')
                  	estado = 66;
                  else
                  {
                      ApontadorAdiante = InicioDeLexema;
                  	 estado = partida = FalhouAutomatos(partida);
                  }
          break;


          case 66:
          			t.classe = 15;
                  strcpy(t.valor,"=");//Retorna o Lexema
                  t.posicaoL = linha; //Linha do Lexema
                  		InicioDeLexema = ApontadorAdiante;
			 return t;
          /*------------------Fim "="--------------------------*/



          /*-----------------Inicio "<"------------------------*/
          case 67: c = ProximoCaracter ( );
          			if (c == '<')
                  	estado = 68;
                  else
                  {
                      ApontadorAdiante = InicioDeLexema;
                  	 estado = partida = FalhouAutomatos(partida);
                  }
          break;


          case 68:
          			t.classe = 16;
                  strcpy(t.valor,"<");//Retorna o Lexema
                  t.posicaoL = linha; //Linha do Lexema
                  		InicioDeLexema = ApontadorAdiante;
			 return t;
          /*------------------Fim "<"--------------------------*/
          
          
          
          /*-----------------Inicio ">"------------------------*/
          case 69: c = ProximoCaracter ( );
          			if (c == '<')
                  	estado = 70;
                  else
                  {
                      ApontadorAdiante = InicioDeLexema;
                  	 estado = partida = FalhouAutomatos(partida);
                  }
          break;


          case 70:
          			t.classe = 16;
                  strcpy(t.valor,">");//Retorna o Lexema
                  t.posicaoL = linha; //Linha do Lexema
                  		InicioDeLexema = ApontadorAdiante;
			 return t;
          /*------------------Fim ">"--------------------------*/



          /*-----------------Inicio "("------------------------*/
          case 71: c = ProximoCaracter ( );
          			if (c == '(')
                  	estado = 72;
                  else
                  {
                      ApontadorAdiante = InicioDeLexema;
                  	 estado = partida = FalhouAutomatos(partida);
                  }
          break;


          case 72:
          			t.classe = 17;
                  strcpy(t.valor,"(");//Retorna o Lexema
                  t.posicaoL = linha; //Linha do Lexema
                  		InicioDeLexema = ApontadorAdiante;
			 return t;
          /*------------------Fim "("--------------------------*/



          /*-----------------Inicio ")"------------------------*/
          case 73: c = ProximoCaracter ();
          			if (c == ')')
                  	estado = 73;
                  else
                  {
                      ApontadorAdiante = InicioDeLexema;
                  	 estado = partida = FalhouAutomatos(partida);
                  }
          break;


          case 74:
          			t.classe = 18;
                  strcpy(t.valor,")");//Retorna o Lexema
                  t.posicaoL = linha; //Linha do Lexema
                  		InicioDeLexema = ApontadorAdiante;
			 return t;
          /*------------------Fim ")"--------------------------*/



          /*-----------------Inicio ";"------------------------*/
          case 75: c = ProximoCaracter ( );
          			if (c == ';')
                  	estado = 76;
                  else
                  {
                      ApontadorAdiante = InicioDeLexema;
                  	 estado = partida = FalhouAutomatos(partida);
                  }
          break;


          case 76:
          			t.classe = 19;
                  strcpy(t.valor,";");//Retorna o Lexema
                  t.posicaoL = linha; //Linha do Lexema
                  		InicioDeLexema = ApontadorAdiante;
			 return t;
          /*------------------Fim ";"--------------------------*/



          /*-----------------Inicio ":"------------------------*/
          case 77: c = ProximoCaracter ( );
          			if (c == ':')
                  	estado = 78;
                  else
                  {
                      ApontadorAdiante = InicioDeLexema;
                  	 estado = partida = FalhouAutomatos(partida);
                  }
          break;


          case 78:
          			t.classe = 20;
                  strcpy(t.valor,":");//Retorna o Lexema
                  t.posicaoL = linha; //Linha do Lexema
                  		InicioDeLexema = ApontadorAdiante;
			 return t;
          /*------------------Fim ":"--------------------------*/
          
          
          
          /*-----------------Inicio "%"------------------------*/
          case 79: c = ProximoCaracter ( );
          			if (c == ':')
                  	estado = 80;
                  else
                  {
                      ApontadorAdiante = InicioDeLexema;
                  	 estado = partida = FalhouAutomatos(partida);
                  }
          break;


          case 80:
          			t.classe = 20;
                  strcpy(t.valor,":");//Retorna o Lexema
                  t.posicaoL = linha; //Linha do Lexema
                  		InicioDeLexema = ApontadorAdiante;
			 return t;
          /*------------------Fim "%"--------------------------*/
          
          

          /*-----------------Inicio "número"--------------------*/
          case 81: c = ProximoCaracter ( );
          			if (isdigit(c))
                  	estado = 81;
                  else
                  {
                      ApontadorAdiante = InicioDeLexema;
                  	 estado = partida = FalhouAutomatos(partida);
                  }
          break;



          case 82: c = ProximoCaracter ( );
          			if (isdigit(c))
                  	estado = 82;
                  else
                  {
                  	if(c == '\n')linha--;//Para que não seja contado linha a mais
                  	estado = 83;
                     ApontadorAdiante--;
                  }
          break;



          case 83:
          			t.classe = 21;
                  for( p = InicioDeLexema; p < ApontadorAdiante; p++)
                  {
                    	t.valor[pos] = vetor[p]; //Retorna Lexema
                     pos++;
                  }
                  t.posicaoL = linha; //Linha do Lexema
                  		InicioDeLexema = ApontadorAdiante;
			 return t;
          /*------------------Fim "número"----------------------*/



          /*--------------Inicio "identificador"------------------*/
          case 84: c = ProximoCaracter ( );
          			if (islower(c) || isupper(c))
                  	estado = 85;
                  else
                  {
                      ApontadorAdiante = InicioDeLexema;
                  	 estado = partida = FalhouAutomatos(partida);
                  }
          break;



          case 85: c = ProximoCaracter ( );
          			if (islower(c) || isupper(c))
                  	estado = 85;
                  else
                  {
                     if(c == '\n')linha--;//Para que não seja contado linha a mais
                  	estado = 86;
                     ApontadorAdiante--;
                  }
          break;


          case 86: c = ProximoCaracter ( );
          			if (isdigit(c))
                  {
                    	estado = 86;
                  }
                  else
                  {
                  	if(c == '\n')linha--;//Para que não seja contado linha a mais
                  	estado = 87;
                     ApontadorAdiante--;
                  }
          break;



          case 87:
                  t.classe = 22;
                  for( p = InicioDeLexema; p < ApontadorAdiante; p++)
                  {
                    	t.valor[pos] = vetor[p]; //Retorna Lexema
                     pos++;
                  }
                  t.posicaoL = linha; //Linha do Lexema
                  		InicioDeLexema = ApontadorAdiante;
			 return t;
          /*---------------Fim "identificador"-------------------*/
          
          
         /*-----------------Inicio "final"------------------------*/
          case 88: c = ProximoCaracter ();
          			if (c == '\0')
                  	estado = 89;
                  else
                  {
                      ApontadorAdiante = InicioDeLexema;
                  	 estado = partida = FalhouAutomatos(partida);
                  }
          break;


          case 89:
          			t.classe = 23;
                  strcpy(t.valor,"FIM");//Retorna o Lexema
                  t.posicaoL = linha; //Linha do Lexema
                  		InicioDeLexema = ApontadorAdiante;
			 return t;
          /*------------------Fim "final"--------------------------*/



			 /*-------------------Inicio "erro"---------------------*/
          case 90:
          			ApontadorAdiante++;

          			t.classe = 24;
                  for(p = InicioDeLexema; p < ApontadorAdiante; p++)
                  {
                    	t.valor[pos] = vetor[p];//Retorna Lexema
                     pos++;
                  }
                  t.posicaoL = linha; //Linha do Lexema
                  		InicioDeLexema = ApontadorAdiante;
		    return t;
         /*---------------------Fim "erro"----------------------*/
        }//Fim switch
  		}//Fim while
}//Fim Procedimento
/*-----------------------Fim token ProximoToken()-----------------------------*/
