/*
 * @lc app=leetcode.cn id=1768 lang=cpp
 *
 * [1768] 交替合并字符串
 */

// @lc code=start
#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution
{
public:
    string mergeAlternately(string word1, string word2)
    {
        int m = word1.size(), n = word2.size();
        int i = 0, j = 0;

        string ans;
        ans.reserve(m + n);
        while (i < m || j < n)
        {
            if (i < m)
            {
                ans.push_back(word1[i]);
                ++i;
            }
            if (j < n)
            {
                ans.push_back(word2[j]);
                ++j;
            }
        }
        return ans;
    }
};
// @lc code=end
