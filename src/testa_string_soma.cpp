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

int main(int argc, char **argv) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}