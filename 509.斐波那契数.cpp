/*
 * @lc app=leetcode.cn id=509 lang=cpp
 *
 * [509] 斐波那契数
 */

// @lc code=start
#include <iostream>
using namespace std;

class Solution
{
public:
    int fib(int n)
    {
        // 防止数据溢出
        int MOD = 1000000007;
        // 判断 n 小于 2 的情况
        if (n < 2)
            return n;
        // 滚动数组
        int a = 0, b = 0, c = 1;
        for (int i = 2; i <= n; i++)
        {
            a = b;
            b = c;
            c = (a + b) % MOD;
        }
        // 返回结果
        return c;
    }
};
// @lc code=end
