/*
 * @lc app=leetcode.cn id=70 lang=cpp
 *
 * [70] 爬楼梯
 */

// @lc code=start
#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int climbStairs(int n)
    {
        // 处理特殊情况
        if (n == 1)
            return 1;
        // 创建 dp 表
        vector<int> dp(n + 1);
        // 初始化
        dp[1] = 1, dp[2] = 2;
        for (int i = 3; i <= n; i++)
        {
            dp[i] = dp[i - 1] + dp[i - 2];
        }
        // 返回结果
        return dp[n];
    }
};
// @lc code=end
