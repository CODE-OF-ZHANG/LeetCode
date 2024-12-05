/*
 * @lc app=leetcode.cn id=215 lang=cpp
 *
 * [215] 数组中的第K个最大元素
 */

// @lc code=start
#include <iostream>
#include <vector>
#include <queue>
#include <ctime>
#include <algorithm>
using namespace std;

// 直接用sort排序找出第k个
// class Solution {
// public:
//     int findKthLargest(vector<int>& nums, int k) {
//         sort(nums.begin(), nums.end(), greater<int>());
//         return nums[k - 1];
//     }
// };

// 用大堆排序 --> 堆排序
// class Solution {
// public:
//     int findKthLargest(vector<int>& nums, int k) {
//         // 大堆
//         priority_queue<int> pq(nums.begin(), nums.end());
//         while(--k) {
//             pq.pop();
//         }
//         return pq.top();
//     }
// };

// 用小堆排序 --> 堆排序
// class Solution {
// public:
//     int findKthLargest(vector<int>& nums, int k) {
//         // 小堆
//         priority_queue<int, vector<int>, greater<int>> pq(nums.begin(), nums.begin() + k);
//         for(int i = k; i < nums.size(); i++) {
//             if(nums[i] > pq.top()) {
//                 pq.pop();
//                 pq.push(nums[i]);
//             }
//         }
//         return pq.top();
//     }
// };

// 快速选择排序
class Solution
{
public:
    int findKthLargest(vector<int> &nums, int k)
    {
        srand(time(NULL));
        return qsort(nums, 0, nums.size() - 1, k);
    }

    int qsort(vector<int> &nums, int l, int r, int k)
    {
        // 数组中只有一个元素
        if (l == r)
            return nums[l];
        // 随机选取基准元素
        int key = getrandom(nums, l, r);
        // 根据基准值将数组分为三块
        int left = l - 1, right = r + 1;
        for (int i = l; i < right;)
        {
            if (nums[i] < key)
                swap(nums[++left], nums[i++]);
            else if (nums[i] == key)
                i++;
            else
                swap(nums[--right], nums[i]);
        }
        // 分情况讨论
        int c = r - right + 1, b = right - left - 1;
        if (c >= k)
            return qsort(nums, right, r, k);
        else if (b + c >= k)
            return key;
        else
            return qsort(nums, l, left, k - b - c);
    }

    int getrandom(vector<int> &nums, int left, int right)
    {
        return nums[rand() % (right - left + 1) + left];
    }
};
// @lc code=end
