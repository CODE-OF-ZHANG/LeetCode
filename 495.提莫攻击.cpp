/*
 * @lc app=leetcode.cn id=495 lang=cpp
 *
 * [495] 提莫攻击
 */

// @lc code=start
#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int findPoisonedDuration(vector<int> &timeSeries, int duration)
    {
        int ret = 0;
        for (int i = 1; i < timeSeries.size(); i++)
        {
            // 计算时间差
            int x = timeSeries[i] - timeSeries[i - 1];
            // 两个中毒时间的差大于或等于中毒状态时间, 直接加上中毒状态时间即可
            if (x >= duration)
                ret += duration;
            // 两个中毒时间的差小于中毒状态时间, 中毒状态时间需要重置, 即加上时间差即可
            else
                ret += x;
        }
        // 要加上最后中毒的时间
        return ret + duration;
    }
};
// @lc code=end
