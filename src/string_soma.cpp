#include <iostream>
#include "string_soma.hpp"
using namespace std;

//constantes globais com base na tabela ascci
const static int cbarra = 92; //cbarra significa contra barra ou seja "\"
const static int ajustenum = 48;//constante para pegar o numero na tabela ascci e tranformar em numero de verdade 

/*A função soma_string  que serve para chamar a função transforma_delimitador e a partir do resultado dessa função chamar a função soma_string_virgula,
e retorna o resultado desta ultima função chamada.*/
int soma_string(char * string_entrada ){
	int soma = 0,tamstr;
	tamstr = strlen(string_entrada);
	if(tamstr < 2){//saber se o tamanho da string é pelo menos equivalente a "\n"
		return -1;
	}else if((string_entrada[tamstr-1]!= 'n') && (string_entrada[tamstr-2]!= cbarra )){ //checa se tudo termina com "\n"
		return -1;
	}
	string_entrada = transforma_delimitador(string_entrada);

	soma = soma_string_virgula(string_entrada);
	return soma;
}

/*a Função serve para receber a string com delimitador e fazer alterações nele para que,  */
char * transforma_delimitador(char * string_entrada){
	int tamstr,num_delimit = 0, tam_delimit = 0, pos_ult_colch = 0,temp = 0, flag_colch = 0, flag_new = 0, flag_subst = 0;
	//a variavel flag_colch é setada para 1 ao encontrar o primeiro "\n" se a função tiver novos delimitadores, para que se for encontrado algum colchete apos
	//esse "\n" ja retorne uma saida invalida.Pois se isso nao for feito, poderia acarretar em news sem delete.
	char string_temp[strlen(string_entrada+1)];
	char * delimitador;
	strcpy(string_temp,string_entrada);
	//tam_delimit armazena o tamanho do primeiro delimitador
	tamstr = strlen(string_entrada);
	if((string_entrada[0] == '/') && (string_entrada[1] == '/') && (string_entrada[2] == '[')){ // significa que vai ter novo delimitador
		for(int i = 2; i < tamstr; i++){//for a partir da pos q começa o delimitador
			if((string_entrada[i] == cbarra) && (string_entrada[i+1] == 'n') && (flag_colch == 0)){//teste para saber se encontrou o primeiro '\n'
				flag_colch = 1;
			}
			if((flag_colch == 1) && ((string_entrada[i] == '[') || (string_entrada[i] == ']' ))){//se encontrar '[' ou ']'apos o primeiro \n, acaba
				strcpy(string_entrada,"n");
				return	string_entrada;
			}
			if(string_entrada[i] == '['){//if para somar  o numero de delimitadores
				num_delimit++;
			}
			if (string_entrada[i] == ']'){//atualiza a posição do ultimo colchete ']'
				pos_ult_colch = i;
			}
		}
		if((string_entrada[pos_ult_colch+1] != cbarra) || (string_entrada[pos_ult_colch+2] != 'n') ){ //acaba se apos ultimo ']' nao tiver um \n
			strcpy(string_entrada,"n");
			return	string_entrada;
		}
		for(int i = 0; i < tamstr; i++){//apos saber a qnt de delimitadores faz uma nova varredura no array
			if(string_entrada[i] == '['){//achou o começo de um delimitador
				temp = i + 1;
				while(string_entrada[temp] != ']' && string_entrada[temp] != '\0' ){//enquanto nao acha o final do delimitardor ou o final da string entrada
					tam_delimit++;//atualiza o tamanho deste delimitador
					temp++;
				}
				delimitador = new char[tam_delimit];//cria uma char *com o tamanho do delimitador
				for(int j = 0; j<tam_delimit;j++){//salva no delimitador seus caracteres
					flag_new = 1;//fala que foi alocado dinamicamente
					delimitador[j] = string_entrada[temp - tam_delimit + j];
				}
				for(int k = i ; k < tamstr; k ++ ){//varre todo o resto do array atualizando o delimitador para virgula 
					if(string_entrada[k] == delimitador[0]){//achou um lugar pra atualizar o delimitador
						flag_subst = 1;//indica que havera substituição do delimitador pela virgula
						for(int l = 0; l < tam_delimit; l++){ //for serve para checar se era o delimitador ou era algo que parecia ser o delimitador
							if((string_entrada[k+l] == delimitador[l]) && (flag_subst == 1)){
								flag_subst = 1;
							}else{
								flag_subst = 0;
							}
						}
						if(flag_subst == 1){//era realmente o delimitador, logo trocaremos ele por virgula
							string_temp[k] = ',';
							for(int m = k+1 ; m <= tamstr; m++){//trocado o primeiro caracter por virgula, copia o resto do string_entrada para o string_temṕ
								string_temp[m] = string_entrada[m + tam_delimit - 1];//a partir do ponto que terminou o delimitador em string_entrada. 
							}
							tamstr = strlen(string_temp);//atualiza o valor do tamanho da string sendo modificada
							strcpy(string_entrada,string_temp);//atualiza string_entrada para ela mesma com os delimitadores alterados por virgula
						}
					}
				}
			}
			if(flag_new == 1 ){
				delete[] delimitador;
				flag_new = 0; 
			}
			tam_delimit = 0;
			flag_subst = 0;
			tamstr = strlen(string_temp);
			strcpy(string_entrada,string_temp);
		}
		for(int i = (4+3*num_delimit) ;i <= tamstr; i++){
			string_temp[i - 4-3*num_delimit] = string_entrada[i];
		}
	}
	strcpy(string_entrada,string_temp);
	return string_entrada;
}


/*A função soma string virgula funciona da seguinte forma, primeiramente checa-se se a string passada possui no minimo o tamanho para se caber a "\n"
*/
int soma_string_virgula(char * string_entrada){

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
	}else if((string_entrada[tamstr-1]!= 'n') && (string_entrada[tamstr-2]!= cbarra )){ //checa se tudo termina com "\n"
		return -1;
	}
	for (int i = 0; i < tamstr; i++){//esse for varre toda a string passada para a função.
		if((string_entrada[i]>='0') && (string_entrada [i]<='9')){ //checa se a posição atual do array contem um numero
			sep=0;//se contiver numero, a variavel sep que indica a quantidade de separadores seguidos é atualizada para 0
			ndigitos++;//a variavel ndigitos é incrementado para que seja possivel saber o tamanho dos numeros.
			if(ndigitos == 1){//sempre que o numero de digitos for de 1, o numero de numeros é incrementado para que seja possivel saber quantos numeros estao sendo somados
				nnum++;
			}
		}else if ((string_entrada[i]!=',') && ((string_entrada[i]!=cbarra) && (string_entrada[i+1]!='n')) && ((string_entrada[i]!='n') && (string_entrada[i-1]!=cbarra))){
			return -1;//se a posição do array nao contiver nenhum numero, checa se ela tem uma virgula ou um "\" de um "\n" ou um "n" do "\n"
		}else if(string_entrada[i]==',' && sep != 0){//checa a presença de duas virgulas sem numero entre elas ou se a string recebida começou com delimitador
			return -1;
		}else{
			if(ndigitos<4){//checa se o numero tem menos de 4digitos, considerando que numeros maiores que 1000 serão ignorados
				for(int j = 0; j<ndigitos;j++){
					soma = soma + ((int)string_entrada[i-j-1] - ajustenum)*pow(10,j);
				}
			}
			ndigitos = 0;//zera o numero de digitos do numero analisado para que o proximos possa ser
		}
		if (((string_entrada[i]==cbarra) && (string_entrada[i+1]=='n')) || ((string_entrada[i]=='n') && (string_entrada[i-1]==cbarra))){
			nnum = 0;//aqui se é checado se a posição atual do array é um"\n" para que se zere a quantidade de numeros nessa linha
		}
		if(string_entrada[i]==','){//diz que a posição atual é uma virgula para que na proxima iteração possa se saber se ha virgulas seguidas
			sep = 1;
		}
		if(nnum>3){//checa se a quantidade de numeros na mesma linha é maior que 3, pois se for, deve-se retornar -1.
			return -1;
		}
	}

	if (sep == 1){// checa se o sep é igual a 1, o que indicaria que a string terminou com uma virgula que nao foi usada para somar dois numeros.
		return -1;
	}

	return soma;
}