/*
 * @lc app=leetcode.cn id=557 lang=cpp
 *
 * [557] 反转字符串中的单词 III
 */

// @lc code=start
#include <iostream>
#include <string>
using namespace std;

class Solution
{
public:
    string reverseWords(string s)
    {
        string ret;
        int n = s.size(), i = 0;
        while (i < n)
        {
            int start = i;
            while (i < n && s[i] != ' ')
                i++;
            for (int p = start; p < i; p++)
            {
                ret.push_back(s[start + i - p - 1]);
            }
            while (i < n && s[i] == ' ')
            {
                i++;
                ret.push_back(' ');
            }
        }
        return ret;
    }
};
// @lc code=end
