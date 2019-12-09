/*------------------------------------------------------------------------------
                                "principal.cpp"
                                ---------------

            	Estao sendo  chamados  os  procedimentos arquivo("Nome_Arquivo") e
            	RetornaToken.

				- arquivo("ArquivoFonte1.mln").:
            ----------------------
              Chama o procedimento que  abre o arquivo e armazena todo o
            seu conteudo em um vetor.
              Para identificar o arquivo, basta apenas por o  endereco e
            o nome do arquivo  entre   aspa  dupla dentro do parentes
            apenas a palavra arquivo.


            - RetornaToken.:
            ----------------
              Chama o procedimento que retorna o proximo token e imprime
            na tela para que possa verificar quais os tokens encontrados.

------------------------------------------------------------------------------*/

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "buffer.h"
#include "alfabeto.h"
#include "token.h"

using namespace std;


//Chamada do Analisador LÃ©xico
int main ()
{
   //Basta apenas digitar o  endereço  e  o nome do
   //arquivo entre aspa dupla dentro do parenteses.
	arquivo("ArquivoFonte2.mln");

   //Retorna os tokens
   RetornaToken ();

   return 0;

}
