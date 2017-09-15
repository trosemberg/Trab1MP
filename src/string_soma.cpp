#include <iostream>
#include "string_soma.hpp"
using namespace std;


int soma_string(char * string_entrada ){
	int tamstr,soma = 0, i = 0;
	tamstr = strlen(string_entrada);
	if(tamstr < 2){
		soma = -1;
	}else if((string_entrada[tamstr-1]!= 'n') && (string_entrada[tamstr-2])){
		soma = -1;
	}
	return soma;
}