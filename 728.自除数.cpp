/*
 * @lc app=leetcode.cn id=728 lang=cpp
 *
 * [728] 自除数
 */

// @lc code=start
#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    bool isSelfDividing(int num)
    {
        int tmp = num;
        while (tmp > 0)
        {
            int digit = tmp % 10;
            if (digit == 0 || num % digit != 0)
                return false;
            tmp /= 10;
        }
        return true;
    }

    vector<int> selfDividingNumbers(int left, int right)
    {
        vector<int> ans;
        for (int i = left; i <= right; i++)
        {
            if (isSelfDividing(i))
                ans.emplace_back(i);
        }
        return ans;
    }
};
// @lc code=end
