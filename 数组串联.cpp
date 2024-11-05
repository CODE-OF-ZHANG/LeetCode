#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    vector<int> getConcatenation(vector<int> &nums)
    {
        int n = nums.size();
        for (int i = 0; i < n; i++)
        {
            nums.push_back(nums[i]);
        }
        return nums;
    }
};

int main()
{
    vector<int> nums;
    nums.push_back(1);
    nums.push_back(2);
    nums.push_back(1);
    Solution s;
    vector<int> ret = s.getConcatenation(nums);
    for (const auto &e : ret)
    {
        cout << e << " ";
    }
    cout << endl;
    return 0;
}
