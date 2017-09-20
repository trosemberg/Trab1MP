#include <iostream>
#include "string_soma.hpp"
using namespace std;


int main(){
  char string_entrada[10000] = "",temp1[10000];
  while (scanf("%c",temp1)!=EOF) {
    strcat(string_entrada,temp1);
  } 
  int tamanho =strlen(string_entrada);
  string_entrada[tamanho-1]='\0';
  int soma = soma_string(string_entrada);
  cout<<soma;
  return 0;
}