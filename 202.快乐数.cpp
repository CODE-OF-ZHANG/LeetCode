/*
 * @lc app=leetcode.cn id=202 lang=cpp
 *
 * [202] 快乐数
 */

// @lc code=start
class Solution
{
public:
    bool isHappy(int n)
    {
        unordered_set<int> s;
        while (n != 1)
        {
            int sum = 0;
            while (n)
            {
                int t = n % 10;
                sum += t * t;
                n /= 10;
            }
            if (s.count(sum))
            {
                return false;
            }
            else
            {
                s.insert(sum);
            }
            n = sum;
        }
        return true;
    }
};
// @lc code=end
