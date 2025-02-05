/*
 * @lc app=leetcode.cn id=771 lang=cpp
 *
 * [771] 宝石与石头
 */

// @lc code=start
#include<iostream>
#include<string>
using namespace std;

class Solution
{
public:
    int numJewelsInStones(string jewels, string stones)
    {
        int jewelsCount = 0;
        int jewelsLength = jewels.size(), stonesLength = stones.size();
        for (int i = 0; i < stonesLength; i++)
        {
            char stone = stones[i];
            for (int j = 0; j < jewelsLength; j++)
            {
                char jewel = jewels[j];
                if (stone == jewel)
                {
                    jewelsCount++;
                    break;
                }
            }
        }
        return jewelsCount;
    }
};
// @lc code=end

