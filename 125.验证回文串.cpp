/*
 * @lc app=leetcode.cn id=125 lang=cpp
 *
 * [125] 验证回文串
 */

// @lc code=start
#include<iostream>
#include<string>
using namespace std;

class Solution
{
public:
    bool isPalindrome(string s)
    {
        string sgood;
        for (char ch : s)
        {
            if (isalnum(ch))
                sgood += tolower(ch);
        }
        string sgood_rev(sgood.rbegin(), sgood.rend());
        return sgood == sgood_rev;
    }
};
// @lc code=end

