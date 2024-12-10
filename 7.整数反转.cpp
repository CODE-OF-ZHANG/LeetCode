/*
 * @lc app=leetcode.cn id=7 lang=cpp
 *
 * [7] 整数反转
 */

// @lc code=start
#include <iostream>
using namespace std;

class Solution
{
public:
    int reverse(int x)
    {
        int ret = 0;
        while (x != 0)
        {
            // 防溢出
            if (ret < INT_MIN / 10 || ret > INT_MAX / 10)
            {
                return 0;
            }
            // 取出最后一位
            int dig = x % 10;
            // 去除最后一位
            x /= 10;
            // 整数反转
            ret = ret * 10 + dig;
        }
        return ret;
    }
};
// @lc code=end
