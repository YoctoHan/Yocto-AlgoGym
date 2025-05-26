//
// Created by YoctoHan on 25-5-26.
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
    int minSubArrayLen(int target, vector<int>& nums) {
        int low = 0, high = 0, sum = 0, min_len = INT_MAX;
        while (high < nums.size()) {
            sum += nums[high++];
            while (sum >= target) {
                min_len = min(min_len, high - low);
                sum -= nums[low++];
            }
        }
        return min_len == INT_MAX ? 0 : min_len;
    }

    int minSubArrayLen2(int s, std::vector<int>& nums) {
        int length = nums.size();
        int min = INT_MAX;
        std::vector<int> sums(length + 1, 0);

        // 构建前缀和数组
        for (int i = 1; i <= length; i++) {
            sums[i] = sums[i - 1] + nums[i - 1];
        }

        // 寻找最小子数组长度
        for (int i = 0; i <= length; i++) {
            int target = s + sums[i];

            // 使用 lower_bound 替代 Java 的 binarySearch
            auto it = std::lower_bound(sums.begin(), sums.end(), target);
            int index = it - sums.begin();

            if (index <= length) {
                min = std::min(min, index - i);
            }
        }

        return min == INT_MAX ? 0 : min;
    }
};

TEST(minSubArrayLen, case_1) {
    Solution solution;
    vector<int> nums = {2, 3, 1, 2, 4, 3};
    const int target = 7;

    const int ans = solution.minSubArrayLen(target, nums);
    int expected = 2;
    EXPECT_EQ(ans, expected);
}

TEST(minSubArrayLen, case_2) {
    Solution solution;
    vector<int> nums = {1, 4, 4};
    const int target = 4;

    const int ans = solution.minSubArrayLen(target, nums);
    int expected = 1;
    EXPECT_EQ(ans, expected);
}

TEST(minSubArrayLen, case_3) {
    Solution solution;
    vector<int> nums = {1, 1, 1, 1, 1, 1, 1, 1};
    const int target = 11;

    const int ans = solution.minSubArrayLen(target, nums);
    int expected = 0;
    EXPECT_EQ(ans, expected);
}

// 修改函数名以匹配注册名，并添加必要的参数
int testMinSubArrayLen(int argc, char* argv[]) {
    ::testing::InitGoogleTest(&argc, argv);

    // 如果没有指定过滤器，默认使用测试套件名称
    if (argc == 1) { // 只有程序名，没有其他参数
        testing::GTEST_FLAG(filter) = "minSubArrayLen.*";
    }

    return RUN_ALL_TESTS();
}

TEST(minSubArrayLen2, case_1) {
    Solution solution;
    vector<int> nums = {2, 3, 1, 2, 4, 3};
    const int target = 7;

    const int ans = solution.minSubArrayLen2(target, nums);
    int expected = 2;
    EXPECT_EQ(ans, expected);
}

TEST(minSubArrayLen2, case_2) {
    Solution solution;
    vector<int> nums = {1, 4, 4};
    const int target = 4;

    const int ans = solution.minSubArrayLen2(target, nums);
    int expected = 1;
    EXPECT_EQ(ans, expected);
}

TEST(minSubArrayLen2, case_3) {
    Solution solution;
    vector<int> nums = {1, 1, 1, 1, 1, 1, 1, 1};
    const int target = 11;

    const int ans = solution.minSubArrayLen2(target, nums);
    int expected = 0;
    EXPECT_EQ(ans, expected);
}

// 修改函数名以匹配注册名，并添加必要的参数
int testMinSubArrayLen2(int argc, char* argv[]) {
    ::testing::InitGoogleTest(&argc, argv);

    // 如果没有指定过滤器，默认使用测试套件名称
    if (argc == 1) { // 只有程序名，没有其他参数
        testing::GTEST_FLAG(filter) = "minSubArrayLen2.*";
    }

    return RUN_ALL_TESTS();
}

// 注册测试
REGISTER_TEST(minSubArrayLen, testMinSubArrayLen);
REGISTER_TEST(minSubArrayLen2, testMinSubArrayLen2);
