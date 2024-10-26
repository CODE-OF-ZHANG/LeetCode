/*
 * @lc app=leetcode.cn id=746 lang=cpp
 *
 * [746] 使用最小花费爬楼梯
 */

// @lc code=start
#include<iostream>
#include<vector>
using namespace std;

// 解法一
// class Solution {
// public:
//     int minCostClimbingStairs(vector<int>& cost) {
//         int n = cost.size();
//         // 创建 dp 表
//         vector<int> dp(n + 1);  // 默认初始化为0
//         // 填表顺序
//         for(int i = 2; i <= n; i++)
//         {
//             dp[i] = min(dp[i - 1] + cost[i - 1], dp[i - 2] + cost[i - 2]);
//         }
//         // 确认返回值
//         return dp[n];
//     }
// };

// 解法二
class Solution
{
public:
    int minCostClimbingStairs(vector<int> &cost)
    {
        int n = cost.size();
        // 创建 dp 表
        vector<int> dp(n); 
        // 初始化
        dp[n - 1] = cost[n - 1], dp[n - 2] = cost[n - 2];
        // 填表顺序
        for (int i = n - 3; i >= 0; i--)
        {
            dp[i] = cost[i] + min(dp[i + 1], dp[i + 2]);
        }
        // 确认返回值
        return min(dp[0], dp[1]);
    }
};
// @lc code=end

