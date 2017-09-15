#include "string_soma.cpp"
#include <gtest/gtest.h>
#include <iostream>
using namespace std;
char oi ='o';
TEST(soma_string, testebasico) { 
    ASSERT_EQ(1, soma_string(&oi));
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}