//
// Created by YoctoHan on 25-5-23.
//
#include <cctype>
#include <gtest/gtest.h>
#include <iostream>
#include <string>
#include <vector>
#include "test_registry.h"

using namespace std;

class Solution {
public:
    int maxArea(vector<int> &height) {
        if (height.size() == 0) {
            return 0;
        }
        int left = 0, right = height.size() - 1;
        int max_area = 0;
        while (left < right) {
            max_area = max(max_area, min(height[left], height[right]) * (right - left));
            if (height[left] < height[right]) {
                ++left;
            } else {
                --right;
            }
        }
        return max_area;
    }
};

TEST(maxArea, case_1) {
    Solution solution;
    vector<int> height{1, 8, 6, 2, 5, 4, 8, 3, 7};
    int ans = solution.maxArea(height);
    int expected = 49;

    EXPECT_EQ(ans, expected);
}

TEST(maxArea, case_2) {
    Solution solution;
    vector<int> height{1, 1};
    int ans = solution.maxArea(height);
    int expected = 1;

    EXPECT_EQ(ans, expected);
}

int testMaxArea(int argc, char *argv[]) {
    ::testing::InitGoogleTest(&argc, argv);

    // 如果没有指定过滤器，默认使用测试套件名称
    if (argc == 1) { // 只有程序名，没有其他参数
        testing::GTEST_FLAG(filter) = "maxArea.*";
    }

    return RUN_ALL_TESTS();
}

// 注册测试
REGISTER_TEST(maxArea, testMaxArea);
