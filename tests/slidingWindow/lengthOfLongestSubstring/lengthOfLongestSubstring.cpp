#include "test_registry.h"
#include "gtest/gtest.h"
#include <unordered_map>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string src) {
        unordered_map<char, int> hash_map;
        int low = -1, res = 0, length = src.size();
        for (int high = 0; high < length; ++high) {
            // 修正：如果字符已存在，更新 low
            if (hash_map.find(src[high]) != hash_map.end()) {
                low = max(low, hash_map[src[high]]);
            }
            hash_map[src[high]] = high;
            res = max(res, high - low);
        }
        return res;
    }
};

class Solution2 {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> hash_map;
        int res = 0, cur = 0, length = s.size(), low;
        for (int high = 0; high < length; high++) {
            if (hash_map.find(s[high]) == hash_map.end())
                low = -1;
            else
                low = hash_map[s[high]];
            hash_map[s[high]] = high;
            cur = cur < high - low ? cur + 1 : high - low;
            res = max(res, cur);
        }
        return res;
    }
};

TEST(lengthOfLongestSubstring, case_1) {
    Solution solution;
    string src = "abcabcbb";
    int ans = solution.lengthOfLongestSubstring(src);
    int expected = 3;
    EXPECT_EQ(ans, expected);

    Solution2 solution2;
    ans = solution2.lengthOfLongestSubstring(src);
    EXPECT_EQ(ans, expected);
}

TEST(lengthOfLongestSubstring, case_2) {
    Solution solution;
    string src = "bbbbb";
    int ans = solution.lengthOfLongestSubstring(src);
    int expected = 1;
    EXPECT_EQ(ans, expected);

    Solution2 solution2;
    ans = solution2.lengthOfLongestSubstring(src);
    EXPECT_EQ(ans, expected);
}

TEST(lengthOfLongestSubstring, case_3) {
    Solution solution;
    string src = "pwwkew";
    int ans = solution.lengthOfLongestSubstring(src);
    int expected = 3;
    EXPECT_EQ(ans, expected);

    Solution2 solution2;
    ans = solution2.lengthOfLongestSubstring(src);
    EXPECT_EQ(ans, expected);
}

// 添加更多边界测试用例
TEST(lengthOfLongestSubstring, edge_cases) {
    Solution solution;

    // 空字符串
    EXPECT_EQ(solution.lengthOfLongestSubstring(""), 0);

    // 单个字符
    EXPECT_EQ(solution.lengthOfLongestSubstring("a"), 1);

    // 无重复字符
    EXPECT_EQ(solution.lengthOfLongestSubstring("abcdef"), 6);
}

int testLengthOfLongestSubstring(int argc, char* argv[]) {
    ::testing::InitGoogleTest(&argc, argv);

    // 如果没有指定过滤器，默认使用测试套件名称
    if (argc == 1) {
        testing::GTEST_FLAG(filter) = "lengthOfLongestSubstring.*";
    }

    return RUN_ALL_TESTS();
}

// 注册测试
REGISTER_TEST(lengthOfLongestSubstring, testLengthOfLongestSubstring);