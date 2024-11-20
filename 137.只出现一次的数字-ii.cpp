/*
 * @lc app=leetcode.cn id=137 lang=cpp
 *
 * [137] 只出现一次的数字 II
 */

// @lc code=start
#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int singleNumber(vector<int> &nums)
    {
        int ret = 0;
        // 依次去修改ret中的每一位
        for (int i = 0; i < 32; i++)
        {
            int sum = 0;
            // 计算nums中所有的数的第i位的和
            for (const auto &x : nums)
            {
                if (((x >> i) & 1) == 1)
                    sum++;
            }
            sum %= 3;
            if (sum == 1)
                ret |= 1 << i;
        }
        return ret;
    }
};
// @lc code=end
