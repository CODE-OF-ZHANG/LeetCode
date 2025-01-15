/*
 * @lc app=leetcode.cn id=1143 lang=cpp
 *
 * [1143] 最长公共子序列
 */

// @lc code=start
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution
{
public:
    int longestCommonSubsequence(string s1, string s2)
    {
        int m = s1.size(), n = s2.size();
        // 创建 dp 表
        vector<vector<int>> dp(m + 1, vector<int>(n + 1));
        s1 = " " + s1, s2 = " " + s2;
        // 填表
        for (int i = 1; i <= m; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                if (s1[i] == s2[j])
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                else
                    dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);
            }
        }
        // 返回结果
        return dp[m][n];
    }
};
// @lc code=end
