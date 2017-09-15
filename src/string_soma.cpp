#include <iostream>
#include "string_soma.hpp"
using namespace std;

//constantes globais com base na tabela ascci
const static int cbarra = 92; //cbarra significa contra barra ou seja "\"
const static int ajustenum = 48;//constante para pegar o numero na tabela ascci e tranformar em numero de verdade 


int soma_string(char * string_entrada ){
	int tamstr = 0,soma = 0, i = 0;
	//tamstr é uma variavel que armazena o tamanho da string de entrada, desta forma 
	tamstr = strlen(string_entrada);
	if(tamstr < 2){
		soma = -1;
		return soma;
	}else if((string_entrada[tamstr-1]!= 'n') && (string_entrada[tamstr-2]!= cbarra )){
		soma = -1;
		return soma;
	}
	for (i = 0; i < tamstr; i++){
		if((string_entrada[i]>='0') && (string_entrada [i]<='9')){
			soma = (int)string_entrada[i] - ajustenum;
		}

	}






	return soma;
}