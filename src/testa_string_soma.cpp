#include "string_soma.cpp"
#include <gtest/gtest.h>
#include <iostream>
using namespace std;




TEST(soma_string, primeiroteste) { 
	char *string_entrada;
	string_entrada = (char *) malloc (strlen("olatudobem"));
	string_entrada = "olatudobem";
    ASSERT_EQ(1, soma_string(string_entrada));
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}