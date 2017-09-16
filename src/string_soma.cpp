#include <iostream>
#include "string_soma.hpp"
using namespace std;

//constantes globais com base na tabela ascci
const static int cbarra = 92; //cbarra significa contra barra ou seja "\"
const static int ajustenum = 48;//constante para pegar o numero na tabela ascci e tranformar em numero de verdade 


int soma_string(char * string_entrada ){
	int soma = 0;

	soma = soma_string_virgula(string_entrada);
	return soma;
}

/*A função soma string virgula funciona da seguinte forma, primeiramente checa-se se a string passada possui no minimo o tamanho para se caber a "\n"
*/
int soma_string_virgula(char * new_string_entrada){

	int tamstr = 0,soma = 0,ndigitos = 0,nnum = 0,sep=2;
	//tamstr é uma variavel que armazena o tamanho da string de entrada, desta forma 
	//ndigitos é uma variavel usada para identificar se o numero passado esta na casa das unidades, dezenas ou centenas.
	//nnum é um contador para o numero de numeros digitados
	/*a variavel sep, server pra contar o separador,se encontrar um separador ela é setada para 1, se encontrar um numero ela é setada para 0, seta forma é possivel 
	saber se esta encontrando dois separadores sem ter numero entre eles,ou se ainda nao apareceu nenhum numero antes do primeiro separador,por isso começamos
	a, o que deve acarretar numa entrada invalida*/

	tamstr = strlen(new_string_entrada);
	if(tamstr < 2){//saber se o tamanho da string é pelo menos equivalente a "\n"
		return -1;
	}else if((new_string_entrada[tamstr-1]!= 'n') && (new_string_entrada[tamstr-2]!= cbarra )){ //checa se tudo termina com "\n"
		return -1;
	}
	for (int i = 0; i < tamstr; i++){//esse for varre toda a string passada para a função.
		if((new_string_entrada[i]>='0') && (new_string_entrada [i]<='9')){ //checa se a posição atual do array contem um numero
			sep=0;//se contiver numero, a variavel sep que indica a quantidade de separadores seguidos é atualizada para 0
			ndigitos++;//a variavel ndigitos é incrementado para que seja possivel saber o tamanho dos numeros.
			if(ndigitos == 1){//sempre que o numero de digitos for de 1, o numero de numeros é incrementado para que seja possivel saber quantos numeros estao sendo somados
				nnum++;
			}
		}else if ((new_string_entrada[i]!=',') && ((new_string_entrada[i]!=cbarra) && (new_string_entrada[i+1]!='n')) && ((new_string_entrada[i]!='n') && (new_string_entrada[i-1]!=cbarra))){
			return -1;//se a posição do array nao contiver nenhum numero, checa se ela tem uma virgula ou um "\" de um "\n" ou um "n" do "\n"
		}else if(new_string_entrada[i]==',' && sep != 0){//checa a presença de duas virgulas sem numero entre elas ou se a string recebida começou com delimitador
			return -1;
		}else{
			if(ndigitos<4){//checa se o numero tem menos de 4digitos, considerando que numeros maiores que 1000 serão ignorados
				for(int j = 0; j<ndigitos;j++){
					soma = soma + ((int)new_string_entrada[i-j-1] - ajustenum)*pow(10,j);
				}
			}
			ndigitos = 0;//zera o numero de digitos do numero analisado para que o proximos possa ser
		}
		if (((new_string_entrada[i]==cbarra) && (new_string_entrada[i+1]=='n')) || ((new_string_entrada[i]=='n') && (new_string_entrada[i-1]==cbarra))){
			nnum = 0;//aqui se é checado se a posição atual do array é um"\n" para que se zere a quantidade de numeros nessa linha
		}
		if(new_string_entrada[i]==','){//diz que a posição atual é uma virgula para que na proxima iteração possa se saber se ha virgulas seguidas
			sep = 1;
		}
		if(nnum>3){//checa se a quantidade de numeros na mesma linha é maior que 3, pois se for, deve-se retornar -1.
			return -1;
		}
	}

	if (sep == 1){
		return -1;
	}

	return soma;
}