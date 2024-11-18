#include <iostream>
#include <map>
#include <string>
using namespace std;

// // 暴力解法
// class Solution
// {
// public:
//     bool isUnique(string astr)
//     {
//         unordered_map<char, int> hash;
//         for (const auto &ch : astr)
//         {
//             hash[ch]++;
//             if (hash[ch] > 1)
//                 return false;
//         }
//         return true;
//     }
// };

// 优化
class Solution
{
public:
    bool isUnique(string astr)
    {
        // 鸽巢原理优化
        if (astr.size() > 26)
            return false;

        // 利用位图
        int hsMap = 0;
        for (const auto &ch : astr)
        {
            // 先判断字符存不存在
            int i = ch - 'a';
            if (((hsMap >> i) & 1) == 1)
                return false;
            // 把当前字符加入位图中
            hsMap |= (1 << i);
        }
        return true;
    }
};


int main()
{
    string str1 = "leetcode";
    Solution s;
    cout << s.isUnique(str1) << endl;
    return 0;
}
