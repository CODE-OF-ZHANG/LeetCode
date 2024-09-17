/*
 * @lc app=leetcode.cn id=1089 lang=cpp
 *
 * [1089] 复写零
 */

// @lc code=start
class Solution
{
public:
    void duplicateZeros(vector<int> &arr)
    {
        int cur = 0, dest = -1, n = arr.size();
        // 找到最后一个复写的数
        while (cur < n)
        {
            if (arr[cur])
                dest++;
            else
                dest += 2;
            if (dest < n - 1)
                cur++;
            else
                break;
        }
        // 处理边界情况
        if (dest == n)
        {
            arr[n - 1] = 0;
            cur--, dest -= 2;
        }
        // 从后向前进行复写
        while (cur >= 0)
        {
            if (arr[cur] != 0)
            {
                arr[dest] = arr[cur];
                cur--, dest--;
            }
            else
            {
                arr[dest] = 0;
                arr[--dest] = 0;
                cur--, dest--;
            }
        }
    }
};
// @lc code=end

