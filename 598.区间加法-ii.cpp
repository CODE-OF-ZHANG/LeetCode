/*
 * @Author: CODE_OF_ZHANG 3363967646@qq.com
 * @Date: 2025-02-02 23:04:59
 * @LastEditors: CODE_OF_ZHANG 3363967646@qq.com
 * @LastEditTime: 2025-02-02 23:05:27
 * @FilePath: \undefinedd:\GitHub_CODE\LeetCode\598.区间加法-ii.cpp
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
/*
 * @lc app=leetcode.cn id=598 lang=cpp
 *
 * [598] 区间加法 II
 */

// @lc code=start
#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int maxCount(int m, int n, vector<vector<int>> &ops)
    {
        for (const auto &op : ops)
        {
            m = min(m, op[0]);
            n = min(n, op[1]);
        }
        return m * n;
    }
};
// @lc code=end
