#ifndef STRING_SOMA_HPP
#define STRING_SOMA_HPP
#include <iostream>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <cmath>
using namespace std;

//função original especificada para ser usada pelo trabalho
int soma_string(char * string_entrada );

//função que funciona quando o delimitador é virgula
int soma_string_virgula(char * new_string_entrada);

//função que recebe a string entrada e atualiza todos os delimitadores em , e coloca a string num formato que possa ser usado pela função soma_string_virgula.
char * transforma_delimitador(char * string_entrada);

#endif