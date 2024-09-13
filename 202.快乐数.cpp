/*
 * @lc app=leetcode.cn id=202 lang=cpp
 *
 * [202] 快乐数
 */

// @lc code=start
// class Solution
// {
// public:
//     bool isHappy(int n)
//     {
//         unordered_set<int> s;
//         while (n != 1)
//         {
//             int sum = 0;
//             while (n)
//             {
//                 int t = n % 10;
//                 sum += t * t;
//                 n /= 10;
//             }
//             if (s.count(sum))
//             {
//                 return false;
//             }
//             else
//             {
//                 s.insert(sum);
//             }
//             n = sum;
//         }
//         return true;
//     }
// };

class Solution
{
public:
    int bitsum(int n)
    {
        int sum = 0;
        while(n)
        {
            int tmp = n % 10;
            sum += tmp * tmp;
            n /= 10;
        }
        return sum;
    }

    bool isHappy(int n)
    {
        int slow = n, fast = bitsum(n);
        while(slow != fast)
        {
            slow = bitsum(slow);
            fast = bitsum(bitsum(fast));
        }
        return slow == 1;
    }
};
// @lc code=end
