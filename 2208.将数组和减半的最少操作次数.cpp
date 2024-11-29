/*
 * @lc app=leetcode.cn id=2208 lang=cpp
 *
 * [2208] 将数组和减半的最少操作次数
 */

// @lc code=start
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution
{
public:
    int halveArray(vector<int> &nums)
    {
        // 大根堆
        priority_queue<double> heap;
        // 遍历数组中的元素
        double sum = 0.0;
        for (const auto &e : nums)
        {
            // 将元素放入大根堆
            heap.push(e);
            // 求和
            sum += e;
        }
        sum /= 2.0;
        // 减半的次数
        int count = 0;
        while (sum > 0)
        {
            // 贪心策略, 将最大的那个元素减半
            double t = heap.top() / 2.0;
            // 减半后要将值去除
            heap.pop();
            // 减半后检查是否大于数组和的一半
            sum -= t;
            count++;
            // 只减半后重新插入大根堆
            heap.push(t);
        }
        return count;
    }
};
// @lc code=end
