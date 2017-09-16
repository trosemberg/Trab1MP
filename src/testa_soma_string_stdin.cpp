#include <iostream>
#include "string_soma.hpp"
using namespace std;


int main(){
int soma;
char oi[1000];
cout<< "digite a sua entrada:"<<endl;
cin>> oi; 
soma = soma_string(oi);
cout<< "A soma é igual a: "<< soma <<endl;
return 0;
}