/*
 * @lc app=leetcode.cn id=1576 lang=cpp
 *
 * [1576] 替换所有的问号
 */

// @lc code=start
#include <iostream>
#include <string>
using namespace std;

class Solution
{
public:
    string modifyString(string s)
    {
        int n = s.size();
        // 遍历字符串
        for (int i = 0; i < n; i++)
        {
            if (s[i] == '?')
            {
                for (char ch = 'a'; ch <= 'z'; ch++)
                {
                    if ((i == 0 || ch != s[i - 1]) && (i == n - 1 || ch != s[i + 1]))
                    {
                        s[i] = ch;
                        break;
                    }
                }
            }
        }
        return s;
    }
};
// @lc code=end
