/*
 * @lc app=leetcode.cn id=215 lang=cpp
 *
 * [215] 数组中的第K个最大元素
 */

// @lc code=start
#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;

// class Solution {
// public:
//     int findKthLargest(vector<int>& nums, int k) {
//         sort(nums.begin(), nums.end(), greater<int>());
//         return nums[k - 1];
//     }
// };

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

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        // 小堆
        priority_queue<int, vector<int>, greater<int>> pq(nums.begin(), nums.begin() + k);
        for(int i = k; i < nums.size(); i++) {
            if(nums[i] > pq.top()) {
                pq.pop();
                pq.push(nums[i]);
            }
        }
        return pq.top();
    }
};
// @lc code=end

