/*
 * @lc app=leetcode.cn id=931 lang=cpp
 *
 * [931] 下降路径最小和
 */

// @lc code=start
#include<iostream>
#include<vector>
using namespace std;


class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        // 1. 创建 dp 表
        int n = matrix.size();
        vector<vector<int>> dp(n + 1, vector<int>(n + 2, INT_MAX));
        // 2. 初始化第一行
        for (int j = 0; j < n + 2; j++)
            dp[0][j] = 0;
        // 3. 填表
        for(int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                dp[i][j] = min(dp[i - 1][j - 1], 
                min(dp[i - 1][j], dp[i - 1][j + 1])) + matrix[i - 1][j - 1];
            }
        }
        // 确认最小值
        int ret = INT_MAX;
        for (int j = 1; j <= n; j++)
        {
            ret = min(ret, dp[n][j]);
        }
        // 4. 返回值
        return ret;
    }
};
// @lc code=end

