﻿// 最长递增子序列.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
// leetcode300
#include <vector> 
#include <iostream>
using namespace std;
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        if (nums.size() == 0)return 0;
        if (nums.size() == 1)return 1;
        //dp[i]表示以nums[i]为结尾的最长递增子序列长度
        vector<int> dp(nums.size(), 1);
        //为什么初始化为1呢？
        //因为dp[i]表示以nums[i]为结尾的最长递增子序列长度，至少有nums[i]在里面占一个长度
        int result = 0;
        for (int i = 1; i < nums.size(); i++) 
        {
            for (int j = 0; j < i; j++) 
            {
                if (nums[j] < nums[i]) 
                {
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }
        }
        for (int i = 0; i < nums.size(); i++) //这个循环可以放到23行下面省去遍历一次
        {
            result = max(result, dp[i]);
        }
        return result;
    }
};
int main()
{
    vector<int>nums{ 10,9,2,5,3,7,101,18 };
    Solution S;
    int result = S.lengthOfLIS(nums);
    std::cout << "Hello World!\n";
}

// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门使用技巧: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件
