/*
 * @lc app=leetcode.cn id=44 lang=cpp
 *
 * [44] 通配符匹配
 */

// @lc code=start
#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution
{
public:
    bool isMatch(string s, string p)
    {
        int m = s.size(), n = p.size();
        // 创建 dp 表
        vector<vector<bool>> dp(m + 1, vector<bool>(n + 1));
        // 下标映射
        p = " " + p, s = " " + s;
        // 初始化
        dp[0][0] = true;
        for (int j = 1; j <= n; j++)
            if (p[j] == '*')
                dp[0][j] = true;
            else
                break;
        // 填表
        for (int i = 1; i <= m; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                if (p[j] == '*')
                    dp[i][j] = dp[i - 1][j] || dp[i][j - 1];
                else
                    dp[i][j] = (p[j] == '?' || s[i] == p[j]) && dp[i - 1][j - 1];
            }
        }
        // 返回结果
        return dp[m][n];
    }
};
// @lc code=end
