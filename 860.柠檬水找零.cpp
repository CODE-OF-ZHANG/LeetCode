/*
 * @lc app=leetcode.cn id=860 lang=cpp
 *
 * [860] 柠檬水找零
 */

// @lc code=start
#include<iostream>
#include<vector>
using namespace std;

class Solution
{
public:
    bool lemonadeChange(vector<int> &bills)
    {
        // 统计5元与10元的数量, 20元不用找回，所以不需要统计
        int five = 0, ten = 0;
        for (const auto &e : bills)
        {
            // 5元, 不用找零, 直接收
            if (e == 5)
                five++;
            else if (e == 10)
            {
                // 10元, 如果没有5元找, 直接返回false
                if (five == 0)
                    return false;
                // 有5元, 找零5元, 10元加一
                else
                    five--, ten++;
            }
            // 20元, 贪心策略
            else
            {
                // 有10元优先使用10元, 其实使用5元
                if (ten && five)
                    ten--, five--;
                else if (five >= 3)
                    five -= 3;
                else
                    return false;
            }
        }
        return true;
    }
};

// @lc code=end

