/*
 * @lc app=leetcode.cn id=91 lang=cpp
 *
 * [91] 解码方法
 */

// @lc code=start
#include<iostream>
#include<vector>
using namespace std;

// class Solution {
// public:
//     int numDecodings(string s) {
//         // 创建 dp 表
//         int n = s.size();
//         vector<int> dp(n);
//         // 初始化
//         dp[0] = s[0] != '0';  // 单独解码
//         if(n == 1)
//             return dp[0];
//         if(s[0] != '0' && s[1] != '0')
//             dp[1] += 1; // dp[i] 与 dp[i - 1] 结合进行解码
//         int t = (s[0] - '0') * 10 + (s[1] - '0');
//         if(t >= 10 && t <= 26)
//             dp[1] += 1; // dp[i] 与 dp[i - 1] 结合进行解码
//         // 填表
//         for (int i = 2; i < n; i++)
//         {
//             if(s[i] != '0')
//                 dp[i] += dp[i - 1]; // 单独解码
//             int t = (s[i - 1] - '0') * 10 + (s[i] - '0');
//             if (t >= 10 && t <= 26)
//                 dp[i] += dp[i - 2]; // dp[i] 与 dp[i - 1] 结合进行解码
//         }
//         return dp[n - 1];
//     }
// };


// 优化后
class Solution
{
public:
    int numDecodings(string s)
    {
        // 创建 dp 表
        int n = s.size();
        vector<int> dp(n + 1);
        // 初始化
        dp[0] = 1;
        dp[1] = s[1 - 1] != '0';
        
        // 填表
        for (int i = 2; i <= n; i++)
        {
            if (s[i - 1] != '0')
                dp[i] += dp[i - 1]; // 单独解码
            int t = (s[i - 2] - '0') * 10 + (s[i - 1] - '0');
            if (t >= 10 && t <= 26)
                dp[i] += dp[i - 2]; // dp[i] 与 dp[i - 1] 结合进行解码
        }
        return dp[n];
    }
};
// @lc code=end

