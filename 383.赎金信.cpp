/*
 * @lc app=leetcode.cn id=383 lang=cpp
 *
 * [383] 赎金信
 */

// @lc code=start
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution
{
public:
    bool canConstruct(string ransomNote, string magazine)
    {
        // 如果 ransomNote 的长度大于 magazine, ransomNote 不能由 magazine 里面的字符构成
        if (ransomNote.size() > magazine.size())
            return false;
        // 统计字母的类型和出现次数
        vector<int> cnt(26);
        for (const auto &ch : magazine)
        {
            cnt[ch - 'a']++;
        }
        for (const auto &ch : ransomNote)
        {
            cnt[ch - 'a']--;
            if (cnt[ch - 'a'] < 0)
                return false;
        }
        return true;
    }
};
// @lc code=end
