﻿// 买卖股票股票的最佳时机1.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
// LeetCode：121

#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    //这道题可以用贪心算法解决但是对于股票买卖问题而言，动态规划是最一般的方式
    int maxProfit(vector<int>& prices) {
        //dp[i][0] 为第i天持有该股票的最大金额，dp[i][1]为第i天不持有该股票的最大金额
        vector<vector<int>> dp(prices.size(), vector<int>{0, 0});
        dp[0][0] = -prices[0];
        dp[0][1] = 0;
        for (int i = 1; i < prices.size(); i++) 
        {
            dp[i][0] = max(dp[i - 1][0], -prices[i]);
            dp[i][1] = max(dp[i - 1][1], prices[i] + dp[i - 1][0]);
        }
        return dp[prices.size() - 1][1];
    }
};
int main()
{
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
