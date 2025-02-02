/*
 * @lc app=leetcode.cn id=56 lang=cpp
 *
 * [56] 合并区间
 */

// @lc code=start
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    vector<vector<int>> merge(vector<vector<int>> &intervals)
    {
        int n = intervals.size();
        // 特殊情况
        if (n == 0)
            return {};
        // 排序
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> ret;
        for (int i = 0; i < n; i++)
        {
            int L = intervals[i][0], R = intervals[i][1];
            if (!ret.size() || ret.back()[1] < L)
                ret.push_back({L, R});
            else
                ret.back()[1] = max(ret.back()[1], R);
        }
        return ret;
    }
};
// @lc code=end
