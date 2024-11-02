/*
 * @lc app=leetcode.cn id=692 lang=cpp
 *
 * [692] 前K个高频单词
 */

// @lc code=start
#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<map>
using namespace std;

// class Solution {
// public:
//     // 仿函数
//     struct Greater
//     {
//         bool operator()(const pair<string, int>& kv1, const pair<string, int>& kv2)
//         {
//             return kv1.second > kv2.second || (kv1.second == kv2.second && kv1.first < kv2.first);
//         }
//     };

//     vector<string> topKFrequent(vector<string>& words, int k) {
//         // 1. 遍历 + 按字典序进行排序
//         map<string, int> countMap;
//         for(const auto& e : words)
//         {
//             countMap[e]++;
//         }
//         // 按出现频率进行排序
//         vector<pair<string, int>> kvVector(countMap.begin(), countMap.end());
//         sort(kvVector.begin(), kvVector.end(), Greater());
//         vector<string> ret;
//         for (int i = 0; i < k; ++i)
//         {
//             ret.push_back(kvVector[i].first);
//         }
//         return ret;
//     }
// };

// class Solution
// {
// public:
//     // 仿函数
//     struct Greater
//     {
//         bool operator()(const pair<string, int> &kv1, const pair<string, int> &kv2)
//         {
//             return kv1.second > kv2.second;
//         }
//     };

//     vector<string> topKFrequent(vector<string> &words, int k)
//     {
//         // 1. 遍历 + 按字典序进行排序
//         map<string, int> countMap;
//         for (const auto &e : words)
//         {
//             countMap[e]++;
//         }
//         // 按出现频率进行排序
//         vector<pair<string, int>> kvVector(countMap.begin(), countMap.end());
//         // 使用稳定的排序
//         stable_sort(kvVector.begin(), kvVector.end(), Greater());
//         vector<string> ret;
//         for (int i = 0; i < k; ++i)
//         {
//             ret.push_back(kvVector[i].first);
//         }
//         return ret;
//     }
// };

class Solution
{
public:
    vector<string> topKFrequent(vector<string> &words, int k)
    {
        // 1. 遍历 + 按字典序进行排序
        map<string, int> countMap;
        for (const auto &e : words)
        {
            countMap[e]++;
        }
        multimap<int, string, greater<int>> sortMap;
        for(auto& kv:countMap)
        {
            sortMap.insert(make_pair(kv.second, kv.first));
        }
        vector<string> ret;
        auto it = sortMap.begin();
        while (k--)
        {
            ret.push_back(it->second);
            ++it;
        }
        return ret;
    }
};
// @lc code=end

