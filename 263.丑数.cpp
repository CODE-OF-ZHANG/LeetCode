/*
 * @lc app=leetcode.cn id=263 lang=cpp
 *
 * [263] 丑数
 */

// @lc code=start
#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    bool isUgly(int n)
    {
        if (n <= 0)
            return false;
        vector<int> factors = {2, 3, 5};
        for (int factor : factors)
        {
            while (n % factor == 0)
                n /= factor;
        }
        return n == 1;
    }
};
// @lc code=end

