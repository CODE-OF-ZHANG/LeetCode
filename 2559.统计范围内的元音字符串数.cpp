/*
 * @lc app=leetcode.cn id=2559 lang=cpp
 *
 * [2559] 统计范围内的元音字符串数
 */

// @lc code=start
#include <iostream>
#include <vector>
#include <string>
#include <cstring>
using namespace std;

class Solution
{
public:
    vector<int> vowelStrings(vector<string> &words, vector<vector<int>> &queries)
    {
        int n = words.size();
        int prefixSums[n + 1];
        memset(prefixSums, 0, sizeof(prefixSums));
        for (int i = 0; i < n; i++)
        {
            int value = isVowelString(words[i]) ? 1 : 0;
            prefixSums[i + 1] = prefixSums[i] + value;
        }
        vector<int> ans(queries.size());
        for (int i = 0; i < queries.size(); i++)
        {
            int start = queries[i][0], end = queries[i][1];
            ans[i] = prefixSums[end + 1] - prefixSums[start];
        }
        return ans;
    }

    bool isVowelString(const string &word)
    {
        return isVowelLetter(word[0]) && isVowelLetter(word.back());
    }

    bool isVowelLetter(char c)
    {
        return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
    }
};
// @lc code=end
