/*
 * @lc app=leetcode.cn id=392 lang=cpp
 *
 * [392] 判断子序列
 */

// @lc code=start
#include <iostream>
#include <string>
using namespace std;

class Solution
{
public:
    bool isSubsequence(string s, string t)
    {
        int n = s.size(), m = t.size(), i = 0, j = 0;
        while (i < n && j < m)
        {
            if (s[i] == t[j])
                i++;
            j++;
        }
        return i == n;
    }
};
// @lc code=end
