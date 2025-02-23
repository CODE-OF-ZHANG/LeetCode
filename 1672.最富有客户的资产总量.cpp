/*
 * @lc app=leetcode.cn id=1672 lang=cpp
 *
 * [1672] 最富有客户的资产总量
 */

// @lc code=start
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

class Solution
{
public:
    int maximumWealth(vector<vector<int>> &accounts)
    {
        int maxWealth = INT_MIN;
        for (const auto &account : accounts)
        {
            maxWealth = max(maxWealth, accumulate(account.begin(), account.end(), 0));
        }
        return maxWealth;
    }
};
// @lc code=end

