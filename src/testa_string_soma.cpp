#include "string_soma.cpp"
#include <gtest/gtest.h>
#include <iostream>
using namespace std;




TEST(soma_string, primeiroteste) { 
	char teste1[100];
	cin>> teste1;
    ASSERT_EQ(1, soma_string(teste1));
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}