/*
 * @lc app=leetcode.cn id=28 lang=cpp
 *
 * [28] 找出字符串中第一个匹配项的下标
 */

// @lc code=start
#include <iostream>
#include <string>
using namespace std;

class Solution
{
public:
    int strStr(string haystack, string needle)
    {
        int n = haystack.size(), m = needle.size();
        for (int i = 0; i + m <= n; i++)
        {
            bool flag = true;
            for (int j = 0; j < m; j++)
            {
                if (haystack[i + j] != needle[j])
                {
                    flag = false;
                    break;
                }
            }
            if (flag)
            {
                return i;
            }
        }
        return -1;
    }
};
// @lc code=end
