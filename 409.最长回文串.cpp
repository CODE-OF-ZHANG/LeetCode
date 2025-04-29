/*
 * @lc app=leetcode.cn id=409 lang=cpp
 *
 * [409] 最长回文串
 */

// @lc code=start
#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;

class Solution
{
public:
    int longestPalindrome(string s)
    {
        unordered_map<char, int> count;
        int ans = 0;
        for (const char c : s)
        {
            ++count[c];
        }
        for (const auto p : count)
        {
            int v = p.second;
            ans += v / 2 * 2;
            if (v % 2 == 1 and ans % 2 == 0)
                ++ans;
        }
        return ans;
    }
};
// @lc code=end
