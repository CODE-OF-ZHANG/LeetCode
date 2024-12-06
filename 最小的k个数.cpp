#include <iostream>
#include <vector>
#include <algorithm>
#include <ctime>
using namespace std;

class Solution
{
public:
    vector<int> inventoryManagement(vector<int> &nums, int k)
    {
        // 随机数种子
        srand(time(NULL));
        qsort(nums, 0, nums.size() - 1, k);
        return {nums.begin(), nums.begin() + k};
    }

    void qsort(vector<int> &nums, int l, int r, int k)
    {
        // 处理特殊情况 --> 数组中没有元素或则只有一个元素
        if (l >= r)
            return;
        // 数组分三块
        int key = getrandom(nums, l, r);
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
        int a = left - l + 1, b = right - left - 1;
        if (a > k)
            qsort(nums, l, left, k);
        else if (a + b >= k)
            return;
        else
            qsort(nums, right, r, k - a - b);
    }

    int getrandom(vector<int> &nums, int l, int r)
    {
        return nums[rand() % (r - l + 1) + l];
    }
};
