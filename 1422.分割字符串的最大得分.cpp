/*
 * @lc app=leetcode.cn id=1422 lang=cpp
 *
 * [1422] 分割字符串的最大得分
 */

// @lc code=start
#include <iostream>
using namespace std;

class Solution
{
public:
    int maxScore(string s)
    {
        int ans = 0;
        int n = s.size();
        for (int i = 1; i < n; i++)
        {
            int score = 0;
            for (int j = 0; j < i; j++)
            {
                if (s[j] == '0')
                {
                    score++;
                }
            }
            for (int j = i; j < n; j++)
            {
                if (s[j] == '1')
                {
                    score++;
                }
            }
            ans = max(ans, score);
        }
        return ans;
    }
};
// @lc code=end
