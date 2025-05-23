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
    vector<vector<int>> threeSum(vector<int>& nums) {
        size_t n = nums.size();

        sort(nums.begin(), nums.end());
        vector<vector<int>> res;

        for (size_t i = 0; i < n - 2; i++) {
            if (nums[i] > 0) {
                break;
            }
            if (i != 0 && nums[i] == nums[i - 1]) continue;
            size_t left = i + 1, right = n - 1;
            while (left < right) {
                int sum = nums[i] + nums[left] + nums[right];
                if (sum == 0) {
                    res.push_back({nums[i], nums[left++], nums[right--]});
                    while (left < right && nums[right] == nums[right + 1]) right--;
                    while (left < right && nums[left] == nums[left - 1]) left++;
                } else if (sum > 0) {
                    right--;
                    while (left < right && nums[right] == nums[right + 1]) right--;
                } else {
                    left++;
                    while (left < right && nums[left] == nums[left - 1]) left++;
                }
            }
        }
        return res;
    }
};

TEST(threeSum, case_1) {
    Solution solution;
    vector<int> nums{-1,0,1,2,-1,-4};
    vector<vector<int>> expected{{-1,-1,2},{-1,0,1}};
    vector<vector<int>> ans = solution.threeSum(nums);

    EXPECT_EQ(ans.size(), expected.size());

    auto ans_copy = ans;
    auto expected_copy = expected;

    for (auto& vec : ans_copy) sort(vec.begin(), vec.end());
    for (auto& vec : expected_copy) sort(vec.begin(), vec.end());

    sort(ans_copy.begin(), ans_copy.end());
    sort(expected_copy.begin(), expected_copy.end());

    EXPECT_EQ(ans_copy, expected_copy);
}

TEST(threeSum, case_2) {
    Solution solution;
    vector<int> nums{0,1,1};
    vector<vector<int>> expected{};
    vector<vector<int>> ans = solution.threeSum(nums);

    EXPECT_EQ(ans.size(), expected.size());

    auto ans_copy = ans;
    auto expected_copy = expected;

    for (auto& vec : ans_copy) sort(vec.begin(), vec.end());
    for (auto& vec : expected_copy) sort(vec.begin(), vec.end());

    sort(ans_copy.begin(), ans_copy.end());
    sort(expected_copy.begin(), expected_copy.end());

    EXPECT_EQ(ans_copy, expected_copy);
}

TEST(threeSum, case_3) {
    Solution solution;
    vector<int> nums{0,0,0};
    vector<vector<int>> expected{{0,0,0}};
    vector<vector<int>> ans = solution.threeSum(nums);

    EXPECT_EQ(ans.size(), expected.size());

    auto ans_copy = ans;
    auto expected_copy = expected;

    for (auto& vec : ans_copy) sort(vec.begin(), vec.end());
    for (auto& vec : expected_copy) sort(vec.begin(), vec.end());

    sort(ans_copy.begin(), ans_copy.end());
    sort(expected_copy.begin(), expected_copy.end());

    EXPECT_EQ(ans_copy, expected_copy);
}

int testThreeSum(int argc, char *argv[]) {
    ::testing::InitGoogleTest(&argc, argv);

    // 如果没有指定过滤器，默认使用测试套件名称
    if (argc == 1) { // 只有程序名，没有其他参数
        testing::GTEST_FLAG(filter) = "threeSum.*";
    }

    return RUN_ALL_TESTS();
}

// 注册测试
REGISTER_TEST(threeSum, testThreeSum);
