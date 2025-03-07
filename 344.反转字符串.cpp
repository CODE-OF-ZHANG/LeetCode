/*
 * @lc app=leetcode.cn id=344 lang=cpp
 *
 * [344] 反转字符串
 */

// @lc code=start
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    void reverseString(vector<char> &s)
    {
        int n = s.size();
        for (int left = 0, right = n - 1; left < right; left++, right--)
        {
            swap(s[left], s[right]);
        }
    }
};
// @lc code=end
