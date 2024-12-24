/*
 * @lc app=leetcode.cn id=467 lang=cpp
 *
 * [467] 环绕字符串中唯一的子字符串
 */

// @lc code=start
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int findSubstringInWraproundString(string s)
    {
        int n = s.size();
        // 创建 dp 表 + 初始化
        vector<int> dp(n, 1);
        // 填表
        for (int i = 1; i < n; i++)
        {
            if (s[i - 1] + 1 == s[i] || (s[i - 1] == 'z' && s[i] == 'a'))
            {
                dp[i] += dp[i - 1];
            }
        }
        // 更新返回值 --> 去重
        int hash[26] = {0};
        for (int i = 0; i < n; i++)
        {
            hash[s[i] - 'a'] = max(hash[s[i] - 'a'], dp[i]);
        }
        // 返回结果
        int sum = 0;
        for (const auto &x : hash)
            sum += x;
        return sum;
    }
};
// @lc code=end
