//
// Created by YoctoHan on 25-5-22.
//

#include <cctype>
#include <gtest/gtest.h>
#include <iostream>
#include <string>
#include "test_registry.h"

class Solution {
public:
    bool isPalindrome(std::string src) {
        std::string src_good;
        for (auto ch: src) {
            if (std::isalnum(ch)) {
                src_good += std::tolower(ch); // 使用小写以忽略大小写
            }
        }
        std::string src_reverse(src_good.rbegin(), src_good.rend()); // 修正顺序
        return src_reverse == src_good;
    }
};

TEST(isPalindrome, case_1) {
    Solution solution;
    std::string src = "A man, a plan, a canal: Panama";
    bool expected = true;

    bool ans = solution.isPalindrome(src);
    EXPECT_EQ(ans, expected);
}

TEST(isPalindrome, case_2) {
    Solution solution;
    std::string src = "race a car";
    bool expected = false;

    bool ans = solution.isPalindrome(src);
    EXPECT_EQ(ans, expected);
}

TEST(isPalindrome, case_3) {
    Solution solution;
    std::string src = " ";
    bool expected = true;

    bool ans = solution.isPalindrome(src);
    EXPECT_EQ(ans, expected);
}

// 修改函数名以匹配注册名，并添加必要的参数
int testIsPalindrome(int argc, char* argv[]) {
    ::testing::InitGoogleTest(&argc, argv);

    // 如果没有指定过滤器，默认使用测试套件名称
    if (argc == 1) { // 只有程序名，没有其他参数
        testing::GTEST_FLAG(filter) = "isPalindrome.*";
    }

    return RUN_ALL_TESTS();
}

// 注册测试
REGISTER_TEST(isPalindrome, testIsPalindrome);
