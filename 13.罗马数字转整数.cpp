/*
 * @lc app=leetcode.cn id=13 lang=cpp
 *
 * [13] 罗马数字转整数
 */

// @lc code=start
#include<iostream>
#include<string>
using namespace std;

class Solution {
public:
    int getHash(char c){
    switch(c){
        case 'I':
            return 1;
        case 'V':
            return 5;
        case 'X':
            return 10;
        case 'L':
            return 50;
        case 'C':
            return 100;
        case 'D':
            return 500;
        case 'M':
            return 1000;
        default:
            return 0;
        }
    }

    int romanToInt(string s) {
        int ret = 0;
        if(!s[0]) return 0;
        if(!s[1]) return getHash(s[0]);
        for (int i = 0; s[i]; i++) {
            ret += getHash(s[i]) < getHash(s[i + 1]) ? -getHash(s[i]) : getHash(s[i]);
        }
        return ret;
    }
};
// @lc code=end

