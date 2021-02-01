/*************************************************************************
	> File Name: like_gtest.h
	> Author: guojunnan
	> Mail: guojunnan2010@163.com
	> Created Time: 2021/1/31
 ************************************************************************/
#include<time.h>
#include <stdio.h>
#include <string.h>
#include <stddef.h>
#include <stdint.h>
#ifndef _LIKE_GTEST_H
#define _LIKE_GTEST_H

int counter=0;
int error=0;
int fail=0;
int success=0;
#define COLOR(msg, code) "\033[0;1;" #code "m" msg "\033[0m"
#define RED(msg)    COLOR(msg, 31) 
#define GREEN(msg)  COLOR(msg, 32) 
#define YELLOW(msg) COLOR(msg, 33)  
#define BLUE(msg)   COLOR(msg, 34) 

#define EXPECT(a, comp, b, flag) { \
    __typeof(a) __a = (a), __b = (b); \
    counter++;\
    if(typeid(a)==typeid(b))\
    {\
        if (!((__a) comp (__b))) { \
            printf(YELLOW("  %s:%d - no.%d instruction failure\n"), __FILE__, __LINE__,counter); \
            printf(YELLOW("    Expected: (%s) %s (%s), actual: %d vs %d\n"), \
            #a, #comp, #b, __a, __b); \
            fail++;\
            if(flag==1)return;\
        } \
        else success++;\
    }\
    else\
    {\
        printf(RED("  %s:%d: STOP\n"), __FILE__, __LINE__); \
        printf(RED("    ERROR: In EXPECT_XXX() function,parameters must have the same type(\"%s\" vs \"%s\" )\n"), \
            #a, #b); \
        error++;\
        return;\
    }\
}
#define EXPECT_STR(a, comp, b, flag) { \
    counter++;\
    if(!(strcmp(a,b)) comp (0))\
    {\
        printf(YELLOW("  %s:%d - no.%d instruction failure\n"), __FILE__, __LINE__,counter); \
        printf(YELLOW("    Expected: (%s) %s (%s), actual: %s vs %s\n"), \
        #a,#comp, #b, a, b); \
        fail++;\
        if(flag==1)return;\
    }\
    else success++;\
}
//EXPECT
//condition
#define EXPECT_TRUE(a)  EXPECT(a, ==, true,0)
#define EXPECT_FALSE(a) EXPECT(a, ==, false,0)
//value
#define EXPECT_EQ(a, b) EXPECT(a, ==, b,0)
#define EXPECT_NE(a, b) EXPECT(a, !=, b,0)
#define EXPECT_LT(a, b) EXPECT(a, <, b,0)
#define EXPECT_LE(a, b) EXPECT(a, <=, b,0)
#define EXPECT_GT(a, b) EXPECT(a, >, b,0)
#define EXPECT_GE(a, b) EXPECT(a, >=, b,0)
//string
#define EXPECT_STREQ(a, b) EXPECT_STR(a, ==, b,0)
#define EXPECT_STRNE(a, b) EXPECT_STR(a, !=, b,0)

//ASSERT
//condition
#define ASSERT_TRUE(a)  EXPECT(a, ==, true,1)
#define ASSERT_FALSE(a) EXPECT(a, ==, false,1)
//value
#define ASSERT_EQ(a, b) EXPECT(a, ==, b,1)
#define ASSERT_NE(a, b) EXPECT(a, !=, b,1)
#define ASSERT_LT(a, b) EXPECT(a, <, b,1)
#define ASSERT_LE(a, b) EXPECT(a, <=, b,1)
#define ASSERT_GT(a, b) EXPECT(a, >, b,1)
#define ASSERT_GE(a, b) EXPECT(a, >=, b,1)
//string
#define ASSERT_STREQ(a, b) EXPECT_STR(a, ==, b,1)
#define ASSERT_STRNE(a, b) EXPECT_STR(a, !=, b,1)

#define FAIL(a) {\
printf("  %s:%d: Failure\n", __FILE__, __LINE__);\
printf("    USER info:%s\n(STOP)\n",a);\
return;\
}
#define ADD_FAILURE(a) {\
printf("  %s:%d: Failure\n", __FILE__, __LINE__);\
printf("    USER info:%s\n",a);\
}


#define TEST(a, b)  \
void like_##a(); \
__attribute__((constructor)) \
void reg_##a() { \
    add_test_func(like_##a, #a,b); \
} \
void like_##a()

struct {
    void (*func)();
    const char *func_name;
    int number;
} func_arr[100];
int func_cnt = 0;

void add_test_func(void (*func)(), const char *str,int number) {
    func_arr[func_cnt].func = func;
    func_arr[func_cnt].func_name = str;
    func_arr[func_cnt].number = number;
    func_cnt++;
    return;
}

int RUN_ALL_TESTS() {
    if(func_cnt>1)
        printf(BLUE("####GET READY TEST####\n") "There are %d samples\n", func_cnt);
    else 
        printf(BLUE("####GET READY TEST####\n") "There is 1 sample\n");
    for (int i = 0; i < func_cnt; i++) {
        printf(BLUE("#### %d/%d ####\n") ,i+1,func_cnt);
        printf(GREEN("[INFO]\n"));
        clock_t start = clock();
        func_arr[i].func();
        clock_t end = clock();
        long t = end - start;
        printf(GREEN("[DONE]\n"));
        printf(GREEN("[STAT]\n"));
        printf("Sample name            : %s \n",func_arr[i].func_name);
        printf("Total    instructions  : %d \n",func_arr[i].number);
        printf("Executed instructions  : %d \n",counter);
        printf("Error    instructions  : %d \n",error);
        printf("Success  instructions  : %d \n",success);
        printf("Failed   instructions  : %d \n",fail);
        printf("Running time           : %ld ms \n",t);
        counter=0;success=0;fail=0;success=0;
    }
    printf(BLUE("####FINISH TEST####\n"));
    return 0;
}

#endif
