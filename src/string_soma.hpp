#ifndef STRING_SOMA_HPP
#define STRING_SOMA_HPP
#include <iostream>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <cmath>
using namespace std;

///funcao que recebe um ponteiro para char de entrada retorna a soma resultante da calculadora de strings
int soma_string(char * string_entrada );

///funcao que valida a string_entrada recebida funcionando apenas para delimitador sendo virgula.
int SomaStringVirgula(char * new_string_entrada);

///funcao que recebe a string_entrada e retorna a string_entrada no formato que a SomaStringVirgula consegue validar.
char * ManipulaStringEntrada(char * string_entrada);

/**funcao que caso a string_entrada seja constituida de declaracao de novos delimitadores, os tranforma em virgula e 
formata a string_entrada para o formato desejado*/
char * DelimitadorViraVirgula( int num_delimit, char * string_entrada);

#endif