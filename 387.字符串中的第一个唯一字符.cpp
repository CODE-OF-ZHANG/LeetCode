/*
 * @lc app=leetcode.cn id=387 lang=cpp
 *
 * [387] 字符串中的第一个唯一字符
 */

// @lc code=start
#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

class Solution
{
public:
    int firstUniqChar(string s)
    {
        unordered_map<int, int> firq;
        for (const char ch : s)
        {
            ++firq[ch];
        }

        for (int i = 0; i < s.size(); i++)
        {
            if (firq[s[i]] == 1)
                return i;
        }
        return -1;
    }
};
// @lc code=end
