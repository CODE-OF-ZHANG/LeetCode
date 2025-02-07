/*
 * @Author: CODE_OF_ZHANG 3363967646@qq.com
 * @Date: 2025-02-07 22:12:24
 * @LastEditors: CODE_OF_ZHANG 3363967646@qq.com
 * @LastEditTime: 2025-02-07 22:12:32
 * @FilePath: \undefinedd:\GitHub_CODE\LeetCode\1281.整数的各位积和之差.cpp
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
/*
 * @lc app=leetcode.cn id=1281 lang=cpp
 *
 * [1281] 整数的各位积和之差
 */

// @lc code=start
#include <iostream>
using namespace std;

class Solution
{
public:
    int Add(int n)
    {
        int sum = 0;
        while (n)
        {
            sum += n % 10;
            n /= 10;
        }
        return sum;
    }

    int Mul(int n)
    {
        int mul = 1;
        while (n)
        {
            mul *= (n % 10);
            n /= 10;
        }
        return mul;
    }

    int subtractProductAndSum(int n)
    {
        return Mul(n) - Add(n);
    }
};
// @lc code=end
