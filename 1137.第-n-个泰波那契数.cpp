/*
 * @lc app=leetcode.cn id=1137 lang=cpp
 *
 * [1137] 第 N 个泰波那契数
 */

// @lc code=start
#include <iostream>
#include <vector>
using namespace std;

// class Solution {
// public:
//     int tribonacci(int n) {
//         // 处理细节问题 --> 越界处理
//         if(n == 0)
//             return 0;

//         if(n == 1 || n == 2)
//             return 1;
//         // 创建 dp 表
//         vector<int> dp(n + 1);
//         // 初始化
//         dp[0] = 0, dp[1] = dp[2] = 1;
//         // 填表
//         for (int i = 3; i <= n; i++)
//         {
//             dp[i] = dp[i - 1] + dp[i - 2] + dp[i - 3];
//         }
//         // 返回值
//         return dp[n];
//     }
// };

// 空间优化 --> 滚动数组
class Solution
{
public:
    int tribonacci(int n)
    {
        // 处理细节问题 --> 越界处理
        if (n == 0)
            return 0;

        if (n == 1 || n == 2)
            return 1;
        // 创建滚动数组
        int a = 0, b = 1, c = 1, d = 0;
        // 填表
        for (int i = 3; i <= n; i++)
        {
            d = a + b + c;
            a = b;
            b = c;
            c = d;
        }
        // 返回值
        return d;
    }
};
// @lc code=end
