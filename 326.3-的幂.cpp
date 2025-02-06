/*
 * @lc app=leetcode.cn id=326 lang=cpp
 *
 * [326] 3 的幂
 */

// @lc code=start
#include <iostream>
using namespace std;

class Solution
{
public:
    bool isPowerOfThree(int n)
    {
        while (n && n % 3 == 0)
        {
            n /= 3;
        }
        return n == 1;
    }
};
// @lc code=end
