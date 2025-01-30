/*
 * @lc app=leetcode.cn id=2140 lang=cpp
 *
 * [2140] 解决智力问题
 */

// @lc code=start
#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    long long mostPoints(vector<vector<int>> &questions)
    {
        int n = questions.size();
        // 创建 dp 表 + 初始化
        vector<long long> dp(n + 1);
        // 填表
        for (int i = n - 1; i >= 0; i--)
        {
            dp[i] = max(dp[i + 1], questions[i][0] + dp[min(n, i + questions[i][1] + 1)]);
        }
        // 返回结果
        return dp[0];
    }
};
// @lc code=end
