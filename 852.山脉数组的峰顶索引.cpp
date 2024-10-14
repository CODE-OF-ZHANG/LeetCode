/*
 * @lc app=leetcode.cn id=852 lang=cpp
 *
 * [852] 山脉数组的峰顶索引
 */

// @lc code=start
#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int left = 1, right = arr.size() - 2;
        while(left < right)
        {
            int mid = left + (right - left + 1) / 2;
            if(arr[mid] > arr[mid - 1])  left = mid;
            else right = mid - 1;
        }
        return left;
    }
};
// @lc code=end

