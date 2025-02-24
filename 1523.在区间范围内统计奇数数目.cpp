/*
 * @Author: CODE_OF_ZHANG 3363967646@qq.com
 * @Date: 2025-02-24 20:55:52
 * @LastEditors: CODE_OF_ZHANG 3363967646@qq.com
 * @LastEditTime: 2025-02-24 20:56:09
 * @FilePath: \undefinedd:\GitHub_CODE\LeetCode\1523.在区间范围内统计奇数数目.cpp
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
/*
 * @lc app=leetcode.cn id=1523 lang=cpp
 *
 * [1523] 在区间范围内统计奇数数目
 */

// @lc code=start
class Solution
{
public:
    int pre(int x)
    {
        return (x + 1) >> 1;
    }

    int countOdds(int low, int high)
    {
        return pre(high) - pre(low - 1);
    }
};
// @lc code=end

