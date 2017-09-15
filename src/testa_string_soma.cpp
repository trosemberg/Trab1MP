#include "string_soma.cpp"
#include <gtest/gtest.h>
#include <iostream>
using namespace std;




TEST(soma_string, primeiroteste) { 
	char *str1;
	str1 = (char *) malloc (strlen("\n"));
	strcpy(str1,"\n");
    
    ASSERT_EQ(-1, soma_string(str1));

}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}