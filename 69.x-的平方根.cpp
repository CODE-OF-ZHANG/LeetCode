/*
 * @lc app=leetcode.cn id=69 lang=cpp
 *
 * [69] x 的平方根 
 */

// @lc code=start
class Solution {
public:
    int mySqrt(int x) {
        if(x < 1)  return 0;  // 处理边界情况
        int left = 1, right = x;  
        while(left < right)
        {
            long long mid = left + (right - left + 1) / 2;  // 防溢出
            if((mid * mid) <= x)  left = mid;
            else right = mid - 1;
        }
        return left;
    }
};

// @lc code=end

