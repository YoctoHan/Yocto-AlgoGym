//
// Created by YoctoHan on 25-5-22.
//
#include <cctype>
#include <gtest/gtest.h>
#include <iostream>
#include <string>
#include "test_registry.h"

using namespace std;

class Solution {
public:
    bool isSubsequence(string s, string t) {
        if (s.size() == 0) return true;
        for (int slow = 0, fast = 0; fast < t.size(); fast++) {
            if (s[slow] == t[fast]) {
                if (++slow == s.size()) {
                    return true;
                }
            }
        }
        return false;
    }
};

TEST(isSubsequence, case_1) {
    Solution solution;
    std::string src = "abc";
    std::string target = "ahbgdc";
    bool expected = true;

    bool ans = solution.isSubsequence(src, target);
    EXPECT_EQ(ans, expected);
}

TEST(isSubsequence, case_2) {
    Solution solution;
    std::string src = "axc";
    std::string target = "ahbgdc";
    bool expected = false;

    bool ans = solution.isSubsequence(src, target);
    EXPECT_EQ(ans, expected);
}

int testIsSubsequence(int argc, char* argv[]) {
    ::testing::InitGoogleTest(&argc, argv);

    // 如果没有指定过滤器，默认使用测试套件名称
    if (argc == 1) { // 只有程序名，没有其他参数
        testing::GTEST_FLAG(filter) = "isSubsequence.*";
    }

    return RUN_ALL_TESTS();
}

// 注册测试
REGISTER_TEST(isSubsequence, testIsSubsequence);
