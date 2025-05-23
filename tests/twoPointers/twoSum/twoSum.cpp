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
    vector<int> twoSum(vector<int>& numbers, int target) {
        int size = numbers.size();
        int left = 0, right = size - 1;
        while (left < right) {
            int sum = numbers[left] + numbers[right];
            if (sum == target) {
                return {left + 1, right + 1};
            } else if (sum > target) {
                right -= 1;
            } else {
                left += 1;
            }
        }
        return {};
    }
};

TEST(twoSum, case_1) {
    Solution solution;
    vector<int> numbers = {2, 7, 11, 15};
    int target = 9;
    vector<int> ans = solution.twoSum(numbers, target);
    vector<int> expected = {1, 2};
    EXPECT_EQ(ans, expected);
}


TEST(twoSum, case_2) {
    Solution solution;
    vector<int> numbers = {2, 3, 4};
    int target = 6;
    vector<int> ans = solution.twoSum(numbers, target);
    vector<int> expected = {1, 3};
    EXPECT_EQ(ans, expected);
}


TEST(twoSum, case_3) {
    Solution solution;
    vector<int> numbers = {-1, 0};
    int target = -1;
    vector<int> ans = solution.twoSum(numbers, target);
    vector<int> expected = {1, 2};
    EXPECT_EQ(ans, expected);
}


int testTwoSum(int argc, char* argv[]) {
    ::testing::InitGoogleTest(&argc, argv);

    // 如果没有指定过滤器，默认使用测试套件名称
    if (argc == 1) { // 只有程序名，没有其他参数
        testing::GTEST_FLAG(filter) = "twoSum.*";
    }

    return RUN_ALL_TESTS();
}

REGISTER_TEST(twoSum, testTwoSum);
