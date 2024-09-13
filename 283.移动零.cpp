/*
 * @lc app=leetcode.cn id=283 lang=cpp
 *
 * [283] 移动零
 */

// @lc code=start
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int src = 0, dest = 0;
        while(src < nums.size())
        {
            if (nums[src] != 0)
            {
                int tmp = nums[src];
                nums[src] = nums[dest];
                nums[dest] = tmp;
                src++, dest++;
            }
            else
            {
                src++;
            }
        }
    }
};
// @lc code=end

