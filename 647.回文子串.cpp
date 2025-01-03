/*
 * @lc app=leetcode.cn id=647 lang=cpp
 *
 * [647] 回文子串
 */

// @lc code=start
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution
{
public:
    int countSubstrings(string s)
    {
        int n = s.size();
        // 创建 dp 表
        vector<vector<bool>> dp(n, vector<bool>(n));
        // 填表 --> 从下往上进行填写 + 更新结果
        int ret = 0;
        for (int i = n - 1; i >= 0; i--)
        {
            for (int j = i; j < n; j++)
            {
                if (s[i] == s[j])
                    dp[i][j] = i + 1 < j ? dp[i + 1][j - 1] : true;
                if (dp[i][j])
                    ret++;
            }
        }
        // 返回结果
        return ret;
    }
};
// @lc code=end
