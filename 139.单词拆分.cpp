/*
 * @lc app=leetcode.cn id=139 lang=cpp
 *
 * [139] 单词拆分
 */

// @lc code=start
#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>
#include <algorithm>
using namespace std;

class Solution
{
public:
    bool wordBreak(string s, vector<string> &wordDict)
    {
        // 优化
        unordered_set<string> hash;
        for (const auto &ch : wordDict)
            hash.insert(ch);
        int n = s.size();
        // 创建 dp 表
        vector<bool> dp(n + 1);
        // 初始化 --> 保证后序填表是正确的
        dp[0] = true;
        // 确保后序填表下标要统一 + 1
        s = ' ' + s;
        // 填表
        for (int i = 1; i <= n; i++)
        {
            for (int j = i; j >= 1; j--)
            {
                if (dp[j - 1] && hash.count(s.substr(j, i - j + 1)))
                {
                    dp[i] = true;
                    break;
                }
            }
        }
        return dp[n];
    }
};
// @lc code=end
