/*
 * @lc app=leetcode.cn id=120 lang=cpp
 *
 * [120] 三角形最小路径和
 */

// @lc code=start
#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int minimumTotal(vector<vector<int>> &triangle)
    {
        int n = triangle.size();
        // 创建 dp 表
        vector<vector<int>> dp(n, vector<int>(n));
        // 初始化
        dp[0][0] = triangle[0][0];
        // 填表
        for (int i = 1; i < n; i++)
        {
            dp[i][0] = dp[i - 1][0] + triangle[i][0];
            for (int j = 1; j < i; j++)
            {
                dp[i][j] = min(dp[i - 1][j - 1], dp[i - 1][j]) + triangle[i][j];
            }
            dp[i][i] = dp[i - 1][i - 1] + triangle[i][i];
        }
        // 返回结果
        return *min_element(dp[n - 1].begin(), dp[n - 1].end());
    }
};
// @lc code=end
