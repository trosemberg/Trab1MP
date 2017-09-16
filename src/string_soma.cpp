#include <iostream>
#include "string_soma.hpp"
using namespace std;

//constantes globais com base na tabela ascci
const static int cbarra = 92; //cbarra significa contra barra ou seja "\"
const static int ajustenum = 48;//constante para pegar o numero na tabela ascci e tranformar em numero de verdade 


int soma_string(char * string_entrada ){
	int tamstr = 0,soma = 0,ndigitos = 0,nnum = 0,sep=2;
	//tamstr é uma variavel que armazena o tamanho da string de entrada, desta forma 
	//ndigitos é uma variavel usada para identificar se o numero passado esta na casa das unidades, dezenas ou centenas.
	//nnum é um contador para o numero de numeros digitados
	/*a variavel sep, server pra contar o separador,se encontrar um separador ela é setada para 1, se encontrar um numero ela é setada para 0, seta forma é possivel 
	saber se esta encontrando dois separadores sem ter numero entre eles,ou se ainda nao apareceu nenhum numero antes do primeiro separador,por isso começamos
	a, o que deve acarretar numa entrada invalida*/

	tamstr = strlen(string_entrada);
	if(tamstr < 2){//saber se o tamanho da string é pelo menos equivalente a "\n"
		return -1;
	}else if((string_entrada[tamstr-1]!= 'n') && (string_entrada[tamstr-2]!= cbarra )){
		return -1;
	}
	for (int i = 0; i < tamstr; i++){
		if((string_entrada[i]>='0') && (string_entrada [i]<='9')){
			sep=0;
			ndigitos++;
			if(ndigitos == 1){
				nnum++;
			}
		}else if ((string_entrada[i]!=',') && ((string_entrada[i]!=cbarra) && (string_entrada[i+1]!='n')) && ((string_entrada[i]!='n') && (string_entrada[i-1]!=cbarra))){
			return -1;
		}else if (string_entrada[0]==','){
				return -1;
		}else if(string_entrada[i]==',' && sep != 0){
			return -1;
		}else{
			if(ndigitos<4){
				for(int j = 0; j<ndigitos;j++){
					soma = soma + ((int)string_entrada[i-j-1] - ajustenum)*pow(10,j);
				}
			}
			ndigitos = 0;
		}
		if (((string_entrada[i]==cbarra) && (string_entrada[i+1]=='n')) || ((string_entrada[i]=='n') && (string_entrada[i-1]==cbarra))){
			nnum = 0;
		}
		if(string_entrada[i]==','){
			sep = 1;
		}
		if(nnum>3){
			return -1;
		}
	}

	if (sep == 1){
		return -1;
	}

	return soma;
}