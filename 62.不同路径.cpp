/*
 * @lc app=leetcode.cn id=62 lang=cpp
 *
 * [62] 不同路径
 */

// @lc code=start
#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int uniquePaths(int m, int n) {
        // 1. 创建 dp 表
        vector<vector<int>> dp(m + 1, vector<int>(n + 1));
        // 2. 初始化
        dp[0][1] = 1;
        // 3. 填表
        for (int i = 1; i <= m; i++)  // 从上往下填表
        {
            for (int j = 1; j <= n; j++)  // 从左往右填表
            {
                dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
            }
        }
        // 4. 返回值
        return dp[m][n];
    }
};
// @lc code=end

