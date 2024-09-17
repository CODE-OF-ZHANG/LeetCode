/*
 * @lc app=leetcode.cn id=11 lang=cpp
 *
 * [11] 盛最多水的容器
 */

// @lc code=start
class Solution {
public:
    int maxArea(vector<int>& height) {
        int left = 0, right = height.size() - 1, ret = 0;
        while (left < right)
        {
            int v = min(height[left], height[right]) * (right - left);
            if(height[left] < height[right])
                left++;
            else
                right--;
            ret = max(ret, v);
        }
        return ret;
    }
};
// @lc code=end

