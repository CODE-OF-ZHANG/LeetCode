/*
 * @lc app=leetcode.cn id=205 lang=cpp
 *
 * [205] 同构字符串
 */

// @lc code=start
#include <iostream>
#include <string>
using namespace std;

class Solution
{
public:
    bool checkOneWay(string s, string t)
    {
        char map[256] = {};
        for (int i = 0; s[i] != 0; i++)
        {
            if (map[s[i]] != 0 && map[s[i]] != t[i])
                return false;
            map[s[i]] = t[i];
        }
        return true;
    }

    bool isIsomorphic(string s, string t)
    {
        return checkOneWay(s, t) && checkOneWay(t, s);
    }
};
// @lc code=end
