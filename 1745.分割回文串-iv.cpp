/*
 * @lc app=leetcode.cn id=1745 lang=cpp
 *
 * [1745] 分割回文串 IV
 */

// @lc code=start
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution
{
public:
    bool checkPartitioning(string s)
    {
        // 用 dp 表把所有子串是否是回文给预处理一下
        int n = s.size();
        // 创建 dp 表
        vector<vector<bool>> dp(n, vector<bool>(n));
        // 填表
        for (int i = n - 1; i >= 0; i--)
        {
            for (int j = i; j < n; j++)
            {
                if (s[i] == s[j])
                {
                    dp[i][j] = i + 1 < j ? dp[i + 1][j - 1] : true;
                }
            }
        }
        // 判断三个子串是否都回文
        for (int i = 1; i < n - 1; i++)
        {
            for (int j = i; j < n - 1; j++)
            {
                if (dp[0][i - 1] && dp[i][j] && dp[j + 1][n - 1])
                    return true;
            }
        }
        return false;
    }
};
// @lc code=end
