#include <iostream>
#include <vector>
using namespace std;

// class Solution {
// public:
//     int waysToStep(int n) {
//         // 细节处理 --> 越界问题
//         if(n == 1 || n == 2)  return n;
//         if(n == 3)  return 4;
//         // 数据溢出问题
//         const int MOD = 1e9 + 7;
//         // 创建 dp 表
//         vector<int> dp(n + 1);
//         // 初始化
//         dp[1] = 1, dp[2] = 2, dp[3] = 4;
//         // 填表
//         for(int i = 4; i <= n; i++)
//         {
//             dp[i] = ((dp[i - 1] + dp[i - 2]) % MOD + dp[i - 3]) % MOD;
//         }
//         // 返回值
//         return dp[n];
//     }
// };

// 空间优化
class Solution
{
public:
    int waysToStep(int n)
    {
        // 细节处理 --> 越界问题
        if (n == 1 || n == 2)
            return n;
        if (n == 3)
            return 4;
        // 数据溢出问题
        const int MOD = 1e9 + 7;
        int a = 1, b = 2, c = 4, d = 0;
        for (int i = 4; i <= n; i++)
        {
            d = ((a + b) % MOD + c) % MOD;
            a = b, b = c, c = d;
        }
        return d;
    }
};
