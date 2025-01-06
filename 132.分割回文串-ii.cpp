/*
 * @lc app=leetcode.cn id=132 lang=cpp
 *
 * [132] 分割回文串 II
 */

// @lc code=start
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution
{
public:
    int minCut(string s)
    {
        int n = s.size();
        // 预处理, 将所有子串是否是回文的信息存储在dp表中
        vector<vector<bool>> isPal(n, vector<bool>(n));
        for (int i = n - 1; i >= 0; i--)
        {
            for (int j = i; j < n; j++)
            {
                if (s[i] == s[j])
                {
                    isPal[i][j] = i + 1 < j ? isPal[i + 1][j - 1] : true;
                }
            }
        }
        // 动态规划 --> 分割的最少次数
        vector<int> dp(n, INT_MAX);
        // 填表
        for (int i = 0; i < n; i++)
        {
            if (isPal[0][i])
            {
                dp[i] = 0;
            }
            else
            {
                for (int j = 1; j <= i; j++)
                {
                    if (isPal[j][i])
                        dp[i] = min(dp[i], dp[j - 1] + 1);
                }
            }
        }
        // 返回结果
        return dp[n - 1];
    }
};
// @lc code=end
