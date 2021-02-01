/*************************************************************************
	> File Name: test.cpp
	> Author: guojunnan
	> Mail: guojunnan2010@163.com
	> Created Time: 2021/1/31
 ************************************************************************/

#include <iostream>
#include <like_googletest/like_gtest.h>
#include <typeinfo>
using namespace std;

int add(int a, int b) {
    return a + b;
}

//first arg is name,second arg is the number of instructions you design 
TEST(test_add1,9) {
    EXPECT_EQ(add(3, 4), 7); // ==
    ADD_FAILURE("asf");
    EXPECT_EQ(add(3, 4), 9); // !=
    EXPECT_LT(add(3, 4), 8); // <
    EXPECT_LE(add(3, 4), 7); // <=
    EXPECT_GT(add(3, 4), 6); // >
    EXPECT_GE(add(3, 4), 7); // >=
    EXPECT_TRUE(2!=1);
    EXPECT_STREQ("asd","asd");
    EXPECT_STREQ("asd","ad");
}

TEST(test_add2,6) {
    EXPECT_EQ(add(3, 4), 4.0); // ==
    EXPECT_NE(add(3, 4), 9); // !=
    EXPECT_LT(add(3, 4), 8); // <
    EXPECT_LE(add(3, 4), 7); // <=
    EXPECT_GT(add(3, 4), 9); // error >
    EXPECT_GE(add(3, 4), 7); // >=
}
int main() {
    return RUN_ALL_TESTS();
}

