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
int testIsPalindrome() {
    // 注意：这里我们不能直接使用 argc 和 argv
    // 在实际应用中，您可能需要修改 test_registry.h 以传递这些参数
    // 临时解决方案：
    int argc = 1;
    char *argv[] = {(char *) "dummy"};

    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

// 注册测试
REGISTER_TEST(isPalindrome, testIsPalindrome);
