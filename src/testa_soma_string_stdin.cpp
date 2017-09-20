/**
 * @file testa_soma_string_stdin.cpp
 * @author Tomás Rosário Rosemberg
 * @date 20/09/2017
 * @brief Arquivo contendo a função main do Trabalho 1 de Metodos de Programacao 2/2017
 *
 *  
 *
 * @see https://github.com/trosemberg/Trabalho1MP
 * 
 */

#include <iostream>
#include "string_soma.hpp"
using namespace std;

/** @brief funcao main que inicializa a string_entrada com nenhum valor e le o arquivo de entrada, caracter a caracter
*salvando na variavel temp1, e concatena o que há em temp1 com string_entrada enquanto nao encontra o fim do arquivo.
*a partir disso envia tal string para soma_string e imprime na tela o resultado de tal funcao.
*/
int main(){
  char string_entrada[10000] = "",temp1[10];
  while (scanf("%c",temp1) != EOF) {
    strcat(string_entrada,temp1);
  } 
  int tamanho = strlen(string_entrada);
  string_entrada[tamanho - 1] = '\0';
  int soma = soma_string(string_entrada);
  cout<<soma;
  return 0;
}