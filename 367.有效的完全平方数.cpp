/*
 * @lc app=leetcode.cn id=367 lang=cpp
 *
 * [367] 有效的完全平方数
 */

// @lc code=start
#include <iostream>
using namespace std;

class Solution
{
public:
    bool isPerfectSquare(int num)
    {
        int left = 0, right = num;
        while (left <= right)
        {
            int mid = left + (right - left) / 2;
            long square = (long)mid * mid;
            if (square < num)
                left = mid + 1;
            else if (square > num)
                right = mid - 1;
            else
                return true;
        }
        return false;
    }
};
// @lc code=end
