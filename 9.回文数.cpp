/*
 * @lc app=leetcode.cn id=9 lang=cpp
 *
 * [9] 回文数
 */

// @lc code=start
class Solution {
public:
    bool isPalindrome(int x) {
    if(x < 0) return false;
    long n = x, sum = 0;
    while(n){
        sum = sum * 10 + n % 10;
        n /= 10;
    }
    return x == sum;
    }
};
// @lc code=end

