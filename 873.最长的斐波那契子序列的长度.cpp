/*
 * @lc app=leetcode.cn id=873 lang=cpp
 *
 * [873] 最长的斐波那契子序列的长度
 */

// @lc code=start
#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution
{
public:
    int lenLongestFibSubseq(vector<int> &arr)
    {
        int n = arr.size();
        // 优化, 将数组中的值与下标进行绑定
        unordered_map<int, int> hash;
        for (int i = 0; i < n; i++)
            hash[arr[i]] = i;
        // 创建 dp 表 + 初始化
        vector<vector<int>> dp(n, vector<int>(n, 2));
        // 填表 + 更新结果
        int ret = 2;
        // 固定最后一个位置
        for (int j = 2; j < n; j++)
        {
            // 固定倒数第二个位置
            for (int i = 1; i < j; i++)
            {
                int a = arr[j] - arr[i];
                if (a < arr[i] && hash.count(a))
                    dp[i][j] = dp[hash[a]][i] + 1;
                ret = max(ret, dp[i][j]);
            }
        }
        // 返回结果
        return ret < 3 ? 0 : ret;
    }
};
// @lc code=end
