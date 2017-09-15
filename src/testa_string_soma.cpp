#include "string_soma.cpp"
#include <gtest/gtest.h>
#include <iostream>
using namespace std;
//salvando o caracter "\" de uma formar que seja possivel usa-lo



TEST(soma_string, primeiroteste) { 
	char str1[10] = {cbarra,'n'};
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

TEST(soma_string,testando_soma){
	char str1[10] = {cbarra,'n'};
	char str2[10] = {'1',cbarra,'n'};
	char str3[10] = {'2',cbarra,'n'};


    ASSERT_EQ(0,soma_string(str1));
    ASSERT_EQ(1,soma_string(str2));
    ASSERT_EQ(2,soma_string(str3));
}




int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}