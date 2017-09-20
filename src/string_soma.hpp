/**
 * @file string_soma.hpp
 * @author Tomás Rosário Rosemberg
 * @date 20/09/2017
 * @brief Arquivo contendo os headers das funcoes soma_string, SomaStringVirgula, ManipulaStringEntrada eDelimitadorViraVirgula.
 *
 * @brif Este header define as funções a serem utilizadas no Trabalho 1 de Metodos de Programacao.
 *  
 *
 * @see https://github.com/trosemberg/Trabalho1MP
 * 
 */


#ifndef STRING_SOMA_HPP
#define STRING_SOMA_HPP
#include <iostream>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <cmath>
using namespace std;

/** @brief funcao que recebe um ponteiro para char de entrada retorna a soma resultante da calculadora de strings
* @param string_entrada - string de entrada
* @return um inteiro que significa a soma da calculadora
*/
int soma_string(char * string_entrada );

/** @brief funcao que valida a string_entrada recebida funcionando apenas para delimitador sendo virgula.
* @param new_string_entrada que é uma string com todos os delimitadores sento virgula
* @return retorna a soma realizada quando os delimitadores sao virgulas
*/
int SomaStringVirgula(char * new_string_entrada);

/** @brief funcao que recebe a string_entrada e retorna a string_entrada no formato que a SomaStringVirgula consegue validar.
* @param string_entrada que a entrada do programa
* @return string entrada conforme as especificacoes,
*/
char * ManipulaStringEntrada(char * string_entrada);

/** @brief funcao que caso a string_entrada seja constituida de declaracao de novos delimitadores, os tranforma em virgula e 
* formata a string_entrada para o formato desejado.
* @param num_delimit-> quantidade de delimitadores
* @param string_entrada -> string a ser manipulada substituindo os delimitadores por virgula
* @return a string_entrada depois de alterar todos os delimitadores para virgula.
*/
char * DelimitadorViraVirgula( int num_delimit, char * string_entrada);

#endif