/*
 * @lc app=leetcode.cn id=63 lang=cpp
 *
 * [63] 不同路径 II
 */

// @lc code=start
#include<iostream>
#include<vector>
using namespace std;


class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& ob) {
        int m = ob.size(), n = ob[0].size();
        // 1. 创建 dp 表
        vector<vector<int>> dp(m + 1, vector<int>(n + 1));
        // 2. 初始化
        dp[0][1] = 1;
        // 3. 填表
        for (int i = 1; i <= m; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                if(ob[i - 1][j - 1] == 0)
                    dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
            }
        }
        // 返回值
        return dp[m][n];
    }
};
// @lc code=end

