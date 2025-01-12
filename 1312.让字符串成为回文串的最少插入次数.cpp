/*
 * @lc app=leetcode.cn id=1312 lang=cpp
 *
 * [1312] 让字符串成为回文串的最少插入次数
 */

// @lc code=start
#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution
{
public:
    int minInsertions(string s)
    {
        int n = s.size();
        // 创建 dp 表
        vector<vector<int>> dp(n, vector<int>(n));
        // 填表 --> 从下往上填每一行, 每一行从左往右填写
        for (int i = n - 1; i >= 0; i--)
        {
            for (int j = i + 1; j < n; j++)
            {
                // s[i] == s[j] 的情况
                if (s[i] == s[j])
                {
                    dp[i][j] = dp[i + 1][j - 1];
                }
                // s[i] != s[j] 的情况
                else
                {
                    dp[i][j] = min(dp[i + 1][j], dp[i][j - 1]) + 1;
                }
            }
        }
        // 返回结果
        return dp[0][n - 1];
    }
};
// @lc code=end
