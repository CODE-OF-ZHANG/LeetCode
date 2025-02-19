/*
 * @lc app=leetcode.cn id=1502 lang=cpp
 *
 * [1502] 判断能否形成等差数列
 */

// @lc code=start
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

class Solution
{
public:
    bool canMakeArithmeticProgression(vector<int> &arr)
    {
        // 排序
        sort(arr.begin(), arr.end());
        // 模拟
        for (int i = 1; i < arr.size() - 1; i++)
        {
            if (arr[i] * 2 != arr[i - 1] + arr[i + 1])
                return false;
        }
        return true;
    }
};
// @lc code=end
