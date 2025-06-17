//
// Created by Yocto on 25-6-17.
//

#include "test_registry.h"
#include "gtest/gtest.h"
#include <unordered_map>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int sLen = s.size(), pLen = p.size();
        if (sLen < pLen) {
            return vector<int>();
        }

        vector<int>sCount(26, 0);
        vector<int>pCount(26, 0);

        for (int index = 0; index < pLen; index++) {
            sCount[s[index] - 'a']++;
            pCount[p[index] - 'a']++;
        }

        vector<int> ans;

        if (sCount == pCount) {
            ans.emplace_back(0);
        }

        for (int index = 0; index < sLen - pLen; index++) {
            sCount[s[index] - 'a']--;
            sCount[s[index + pLen] - 'a']++;

            if (sCount == pCount) {
                ans.emplace_back(index + 1);
            }
        }

        return ans;
    }
};

TEST(findAnagrams, case_1) {
    Solution solution;
    string s = "cbaebabacd";
    string p = "abc";
    vector<int> ans = solution.findAnagrams(s, p);
    vector<int> expected = {0, 6};
    EXPECT_EQ(ans, expected);
}

TEST(findAnagrams, case_2) {
    Solution solution;
    string s = "abab";
    string p = "ab";
    vector<int> ans = solution.findAnagrams(s, p);
    vector<int> expected = {0, 1, 2};
    EXPECT_EQ(ans, expected);
}

int testFindAnagrams(int argc, char* argv[]) {
    ::testing::InitGoogleTest(&argc, argv);

    // 如果没有指定过滤器，默认使用测试套件名称
    if (argc == 1) {
        testing::GTEST_FLAG(filter) = "findAnagrams.*";
    }

    return RUN_ALL_TESTS();
}

// 注册测试
REGISTER_TEST(findAnagrams, testFindAnagrams);