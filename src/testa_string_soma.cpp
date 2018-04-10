/**
 * @file testa_string_soma.cpp
 * @author Tomás Rosário Rosemberg
 * @date 20/09/2017
 * @brief Arquivo contendo os testes do Trabalho 1 de Metodos de Programacao 2/2017
 *
 *  
 *
 * @see https://github.com/trosemberg/Trabalho1MP
 * 
 */

#include "string_soma.cpp"
#include <gtest/gtest.h>


///teste feito apenas para saber como funciona o gtest
TEST(soma_string, primeiroteste) { 
  char str1[] = "\n";
  ASSERT_EQ(0, soma_string(str1));
}

///teste com strings que ou nao tinham tamanho suficiente para armazernar um "\n" ou nao terminavam em "\n"
TEST(soma_string, string_pequena_ou_sem_barran) { 
  char str1[10],str2[10],str3[10];
  strcpy(str1,"n");
  strcpy(str2,"");
  strcpy(str3,"1233");
  ASSERT_EQ(-1, soma_string(str1));
  ASSERT_EQ(-1, soma_string(str2));
  ASSERT_EQ(-1, soma_string(str3));
}

///Teste  com strings que contem apenas um numero
TEST(soma_string,testando_soma_sem_separador){
  char str1[10] = "\n";
  char str2[10] = "1\n";
  char str3[10] = "2\n";


  ASSERT_EQ(0,soma_string(str1));
  ASSERT_EQ(1,soma_string(str2));
  ASSERT_EQ(2,soma_string(str3));
}

///teste com numeros com mais de uma casa mas menores que 999
TEST(soma_string,testando_menores_que_999){
  char str1[10] = "100\n";
  char str2[10] = "10\n";

  ASSERT_EQ(100,soma_string(str1));
  ASSERT_EQ(10,soma_string(str2));
}

///teste com numeros maiores que 999
TEST(soma_string,testando_maiores_que_999){
  char str1[10] = "1000\n";
  char str2[10] = "10000\n";

  ASSERT_EQ(0,soma_string(str1));
  ASSERT_EQ(0,soma_string(str2));
}

///teste com numeros separados por virgulas
TEST(soma_string,testendo_soma_com_separador){
  char str1[] = "11,2\n";
  char str2[10] = "1,1,3\n";

  ASSERT_EQ(13,soma_string(str1));
  ASSERT_EQ(5,soma_string(str2));
}

///teste com casas diferente de numeros, virgula ou "\n"
TEST(soma_string,testendo_soma_com_separadorerrado){
  char str1[10] = "1;2\n";
  char str2[10] = "1o1,3\n";

  ASSERT_EQ(-1,soma_string(str1));
  ASSERT_EQ(-1,soma_string(str2));
}

///teste com separador em posições que ele nao pode estar
TEST(soma_string,testendo_soma_separador_pos_errada){
  char str1[10] = "1,,\n";
  char str2[10] = ",11,3\n";
  char str3[10] = "11,3,\n";

  ASSERT_EQ(-1,soma_string(str1));
  ASSERT_EQ(-1,soma_string(str2));
  ASSERT_EQ(-1,soma_string(str3));
}

///teste com mais numeros por linhas do que pode
TEST(soma_string,test_mais_num_q_pode_linha){
  char str1[20] = "1,2,3,4\n";
  char str2[20] = "1,2,3,4,5\n";

  ASSERT_EQ(-1,soma_string(str1));
  ASSERT_EQ(-1,soma_string(str2));
}

///teste com atualização de delimitadores
TEST(soma_string,test_com_delimitador){
  char str1[] = "//[@]\n2@3\n";
  char str2[] = "//[***][!!]\n2***3!!4\n";
  char str3[] = "//[@][!][$]\n2@3\n2!2$2\n";

  ASSERT_EQ(5,soma_string(str1));
  ASSERT_EQ(9,soma_string(str2));
  ASSERT_EQ(11,soma_string(str3));
}

///Casos adicionais de testes para que o gcov saisse de 95% para 100% de cobertura do codigo string_soma.cpp
TEST(soma_string,Testes_adicionais){
  char str1[] = "1,2[\n";
  char str2[] = "//[#]\n[1,2#3\n";
  char str3[] = "//[#]1],2#3\n";
  char str4[] = "//[#]\n";
  char str5[] = "//[##]\n1#\n\n2\n";

  ASSERT_EQ(-1,soma_string(str1));
  ASSERT_EQ(-1,soma_string(str2));
  ASSERT_EQ(-1,soma_string(str3));
  ASSERT_EQ(-1,soma_string(str4));
  ASSERT_EQ(-1,soma_string(str5));
}


/**\Class testes
*\brief Função que descreve os testes 
*/
/** Testes baseados no documento de especificação
*/

TEST (Calculadora_Trab1, 1_virg_2_ql){ 
 ASSERT_EQ (3, soma_string((char*)"1,2\n"));/**<Teste que verifica se está processando entradas de 2 numeros*/
}
TEST (Calculadora_Trab1, 3_virg_2_virg_1_ql){ 
 ASSERT_EQ (6, soma_string((char*)"3,2,1\n"));/**<Teste que verifica se está processando entradas de 3 numeros*/ 
}
TEST (Calculadora_Trab1, 1_virg_ql){ 
 ASSERT_EQ (-1, soma_string((char*)"1,\n"));/**<Teste que verifica se está invalidando delimitadores que nao possui numero consecutivo*/
}
TEST (Calculadora_Trab1, virg_2_ql){ 
 ASSERT_EQ (-1, soma_string((char*)",2\n"));/**<Teste que verifica se está invalidando delimitadores que nao possui numero anterior a ele*/
}
TEST (Calculadora_Trab1, 1_2virg_2_ql){ 
 ASSERT_EQ (-1, soma_string((char*)"1,,2\n"));/**<Teste que verifica se está invalidando a fata de um numero entre dois delimitadores*/
}
TEST (Calculadora_Trab1, virg_ql){ 
 ASSERT_EQ (-1, soma_string((char*)",\n"));/**<Teste que verifica se está invalidando delimitadores sem numero posterior ou anterior*/
}
TEST (Calculadora_Trab1, 1_dotvirg_2_ql){ 
 ASSERT_EQ (-1, soma_string((char*)"1;2\n"));/**<Teste que verifica se está invalidando caracteres estranhos*/
}
TEST (Calculadora_Trab1, 1_virg_2){ 
 ASSERT_EQ (-1, soma_string((char*)"1,2"));/**<Teste que verifica se está invalidando a falta de quebra de linha ao final*/
}
TEST (Calculadora_Trab1, 1_virg_2_ql_sp){ 
 ASSERT_EQ (-1, soma_string((char*)"1,2\n "));/**<Teste que verifica se está processando todos os caracteres fornecidos*/
}
TEST (Calculadora_Trab1, 1_ql_virg_2_ql){ 
 ASSERT_EQ (3, soma_string((char*)"1\n,2\n"));/**<Teste que verifica se está ignorando as quebras de linhas no processamento da soma (1)*/
}
TEST (Calculadora_Trab1, 1_ql_ql_ql_virg_4_ql){ 
 ASSERT_EQ (5, soma_string((char*)"1\n\n\n,4\n"));/**<Teste que verifica se está ignorando as quebras de linhas no processamento da soma(2)*/
}
TEST (Calculadora_Trab1, 1_ql_ql_ql_virg_ql_ql_ql_3_ql){ 
 ASSERT_EQ (4, soma_string((char*)"1\n\n\n,\n\n\n3\n"));/**<Teste que verifica se está ignorando as quebras de linhas no processamento da soma(3)*/ 
}
TEST (Calculadora_Trab1, 1_virg_2_virg_3_virg_4_ql){ 
 ASSERT_EQ (-1, soma_string((char*)"1,2,3,4\n"));/**<Teste que verifica se está invalidando mais do que 3 numeros por linha*/
}
TEST (Calculadora_Trab1, 1_virg_2_virg_3_ql_virg_4_ql){ 
 ASSERT_EQ (10, soma_string((char*)"1,2,3\n,4\n"));/**<Teste que verifica se está processando as quebras de linhas na contagem de inteiros por linha*/
}
TEST (Calculadora_Trab1, 1_virg_neg_virg_3_ql){ 
 ASSERT_EQ (-1, soma_string((char*)"1,-2,3\n"));/**<Teste que verifica se está invalidando numeros negativos*/
}
TEST (Calculadora_Trab1, 3_virg_2000_ql){ 
 ASSERT_EQ (-1, soma_string((char*)"3,2000\n"));/**<Teste que verifica se está invalidando numeros maiores que 1000*/
}
TEST (Calculadora_Trab1, 1_virg_1000_virg_3_ql){ 
 ASSERT_EQ (1004, soma_string((char*)"1,1000,3\n"));/**<Teste que verifica se está processando numeros até 1000*/
}

TEST (Calculadora_Trab1, del_ql_2_del_3_ql){ 
 ASSERT_EQ (5, soma_string((char*)"//[;]\n2;3\n"));/**<Teste que verifica se está processando a inclusao de um único delimitador de tamanho 1*/
}
TEST (Calculadora_Trab1, del_2_del_3_del_4_ql){ 
 ASSERT_EQ (-1, soma_string((char*)"//[***]2***3***4\n"));/**<Teste que verifica se está processando a inclusao de um único delimitador de qualquer tamanho*/
}
TEST (Calculadora_Trab1, del1_del2_ql_2_del1_1_del2_3_ql){ 
 ASSERT_EQ (6, soma_string((char*)"//[**][%%%]\n2**1%%%3\n"));/**<Teste que verifica se está processando a inclusao de mais de um delimitador de tamanho qualquer*/
}

/**\Class testes_unit
  Testes de desenvolvimento
*/

TEST (Calculadora_Trab1, 21_virg_12_ql){ 
 ASSERT_EQ (33, soma_string((char*)"21,12\n"));/**<Teste que verifica se está processando a soma de inteiros com 2 casas*/
}
TEST (Calculadora_Trab1, sp_21_virg_12_ql){ 
 ASSERT_EQ (-1, soma_string((char*)" 21,12\n"));/**<Teste que verifica se está processando caracteres invali
 dos antes da sentença*/
}
TEST (Calculadora_Trab1, 21_sp_virg_12_ql){ 
 ASSERT_EQ (-1, soma_string((char*)"21 ,12\n"));/**<Teste que verifica se está processando caracteres invalidos antes de um delimitador*/
}
TEST (Calculadora_Trab1, 21_virg_sp_12_ql){ 
 ASSERT_EQ (-1, soma_string((char*)"21, 12\n"));/**<Teste que verifica se está processando caracteres invalidos depois de um delimitador*/
}
TEST (Calculadora_Trab1, del1_del2_ql_2_INV_1_INV_3_ql){ 
 ASSERT_EQ (-1, soma_string((char*)"//[**][%%%]\n2***1%%3\n"));/**<Teste que verifica se está invalidando palavras que se parecem com delimitadores**/
}
TEST (Calculadora_Trab1, del1_del2_ql_2_del1_1_INV_3_ql){ 
 ASSERT_EQ (-1, soma_string((char*)"//[**][%%]\n2**1%3\n"));/**<Teste que verifica se está invalidando uma palavra que se parece com delimitador mas não o é*/
}
TEST (Calculadora_Trab1, del_ql_2_del_3_del_4_del_5_ql){ 
 ASSERT_EQ (-1, soma_string((char*)"//[;]\n2;3;4;5\n"));/**<Teste que verifica se o processamento dos delimitadores é independente da contagem de inteiros por linha (1)*/
}
TEST (Calculadora_Trab1, del_ql_2_del_3_ql_del_4_del_5_ql){ 
 ASSERT_EQ (14, soma_string((char*)"//[;]\n2;3\n;4;5\n"));/**<Teste que verifica se o processamento dos delimitadores é independente da contagem de inteiros por linha(2)*/
}
TEST (Calculadora_Trab1, del_ql_2_del_3_del){ 
 ASSERT_EQ (-1, soma_string((char*)"//[;]\n2;3;"));/**<Teste que verifica se o processamento dos delimitadores é independente do processamento da quebra de linha*/
}
TEST (Calculadora_Trab1, del_ql_1_del_2_ql){ 
 ASSERT_EQ (3, soma_string((char*)"//[**]\n1**2\n"));/**<Teste que verifica o processamento de apenas um delimitador*/
}
TEST (Calculadora_Trab1, INVALID){ 
 ASSERT_EQ (-1, soma_string((char*)"//[**\n1**2\n"));/**<Teste que verifica se a sentença de inscrição de delimitadores esta completa*/
}

int main(int argc, char **argv) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}