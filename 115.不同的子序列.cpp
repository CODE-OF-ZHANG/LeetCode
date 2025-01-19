/*
 * @lc app=leetcode.cn id=115 lang=cpp
 *
 * [115] 不同的子序列
 */

// @lc code=start
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution
{
public:
    int numDistinct(string s, string t)
    {
        int m = t.size(), n = s.size();
        // 处理特殊情况
        if (m > n)
            return 0;
        // 创建 dp 表
        vector<vector<double>> dp(m + 1, vector<double>(n + 1));
        // 初始化
        for (int j = 0; j <= n; j++)
            dp[0][j] = 1;
        // 填表 + 处理一下映射关系
        for (int i = 1; i <= m; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                dp[i][j] += dp[i][j - 1];
                if (t[i - 1] == s[j - 1])
                {
                    dp[i][j] += dp[i - 1][j - 1];
                }
            }
        }
        // 确定返回值
        return dp[m][n];
    }
};
// @lc code=end
