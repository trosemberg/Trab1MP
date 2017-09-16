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

int soma_string_virgula(char * new_string_entrada);

void transforma_delimitador(char * string_entrada, int qnt_delimitadores);

#endif