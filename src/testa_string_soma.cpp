#include "string_soma.cpp"
#include <gtest/gtest.h>
#include <iostream>
using namespace std;
//salvando o caracter "\" de uma formar que seja possivel usa-lo



TEST(soma_string, primeiroteste) { 
	char str1[] = "\\n";
    ASSERT_EQ(0, soma_string(str1));

}

TEST(soma_string, string_pequena_ou_sem_barran) { 
	char str1[10],str2[10],str3[10];
	strcpy(str1,"n");
    strcpy(str2,"");
    strcpy(str3,"1233");
    ASSERT_EQ(-1, soma_string(str1));
    ASSERT_EQ(-1, soma_string(str2));
    ASSERT_EQ(-1, soma_string(str3));

}

TEST(soma_string,testando_soma_sem_separador){
	char str1[10] = {cbarra,'n'};
	char str2[10] = {'1',cbarra,'n'};
	char str3[10] = {'2',cbarra,'n'};


    ASSERT_EQ(0,soma_string(str1));
    ASSERT_EQ(1,soma_string(str2));
    ASSERT_EQ(2,soma_string(str3));
}

TEST(soma_string,testando_menores_que_999){
	char str1[10] = {'1','0','0',cbarra,'n'};
	char str2[10] = {'1','0',cbarra,'n'};

	ASSERT_EQ(100,soma_string(str1));
	ASSERT_EQ(10,soma_string(str2));
}

TEST(soma_string,testando_maiores_que_999){
	char str1[10] = {'1','0','0','0',cbarra,'n'};
	char str2[10] = {'1','0','0','0','0',cbarra,'n'};

	ASSERT_EQ(0,soma_string(str1));
	ASSERT_EQ(0,soma_string(str2));
}

TEST(soma_string,testendo_soma_com_separador){
	char str1[10] = {'1' , ',' , '2' , cbarra ,'n'};
	char str2[10] = {'1' , ',' , '1', ',' , '3' , cbarra,'n'};

	ASSERT_EQ(3,soma_string(str1));
	ASSERT_EQ(5,soma_string(str2));


}

TEST(soma_string,testendo_soma_com_separadorerrado){
	char str1[10] = {'1' , ';' , '2' , cbarra ,'n'};
	char str2[10] = {'1' , 'o' , '1', ',' , '3' , cbarra,'n'};

	ASSERT_EQ(-1,soma_string(str1));
	ASSERT_EQ(-1,soma_string(str2));


}

TEST(soma_string,testendo_soma_separador_pos_errada){
	char str1[10] = {'1' , ',' , ',' , cbarra ,'n'};
	char str2[10] = {',' , '1' , '1', ',' , '3' , cbarra,'n'};
	char str3[10] = {'1' , '1', ',' , '3' , ',' , cbarra,'n'};

	ASSERT_EQ(-1,soma_string(str1));
	ASSERT_EQ(-1,soma_string(str2));
	ASSERT_EQ(-1,soma_string(str3));


}

TEST(soma_string,test_mais_num_q_pode_linha){
	char str1[20] = {'1' , ',' , '2' ,',' , '3' ,',' , '4' , cbarra ,'n'};
	char str2[20] = {'1' , ',' , '2' ,',' , '3' ,',' , '4' , ',' , '5' , cbarra ,'n'};

	ASSERT_EQ(-1,soma_string(str1));
	ASSERT_EQ(-1,soma_string(str2));

}


TEST(soma_string,test_com_um_delimitador){
	char str1[] = "//[***]\\n2***3***4\\n";
	char str2[] = "//[@]\\n2@3\\n";

	ASSERT_EQ(9,soma_string(str1));
	ASSERT_EQ(5,soma_string(str2));

}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}