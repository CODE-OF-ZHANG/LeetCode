/*
 * @lc app=leetcode.cn id=520 lang=cpp
 *
 * [520] 检测大写字母
 */

// @lc code=start
#include <iostream>
#include <string>
using namespace std;

// class Solution
// {
// public:
//     bool detectCapitalUse(string word)
//     {
//         int high = 0, low = 0, n = word.size();
//         for (const char ch : word)
//         {
//             if (ch >= 'A' && ch <= 'Z')
//                 high++;
//             if (ch >= 'a' && ch <= 'z')
//                 low++;
//         }
//         if (high == 1 && word[0] <= 'Z')
//             return true;
//         if (high == n)
//             return true;
//         if (low == n)
//             return true;
//         return false;
//     }
// };

class Solution
{
public:
    bool detectCapitalUse(string word)
    {
        // 若第 1 个字母为小写，则需额外判断第 2 个字母是否为小写
        if (word.size() >= 2 && islower(word[0]) && isupper(word[1]))
            return false;
        // 无论第 1 个字母是否大写，其他字母必须与第 2 个字母的大小写相同
        for (int i = 2; i < word.size(); i++)
        {
            if (islower(word[i]) ^ islower(word[1]))
                return false;
        }
        return true;
    }
};
// @lc code=end
