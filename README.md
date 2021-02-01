# 基于宏定义的测试框架（功能仿照GoogleTest）

### 开发功能简介

模仿GoogleTest测试框架实现了一款简易的C语言测试框架。开发所用的核心技术是宏定义和printf自定义格式输出，详见like_googletest/like_gtest.h。

主要开发内容有：

*条件、数值、字符串的EXPECT_XXX和ASSERT_XXX系列语句。
*显示语句FAIL和FAILURE。
*用于生成测试样例的TEST。
*执行测试样例的RUN_ALL_TESTS。

### 使用说明:

提供了一个测试框架使用样例test.cpp。

*make	//编译test.cpp生成a.out
*./a.out	//执行程序

### 运行效果

![test.cpp运行效果](https://github.com/listener123/like_googletest/blob/main/demo.png)

### 开发测试平台

*   Linux

### 相关项目参考

[开课吧C++直播公开课]

[googletest]https://github.com/google/googletest

[GoogleTest框架 使用总结]https://blog.csdn.net/sunhaobo1996/article/details/79329522
