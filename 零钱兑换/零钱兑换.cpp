// 零钱兑换.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
// leetcode 518
#include <vector>
#include <iostream>
using namespace std;
class Solution {
public:
    int change(int amount, vector<int>& coins) {
        //dp[j]是容量为j的背包有dp[j]种方法存满,coins每一个都可以无限拿
        vector<int> dp(amount + 1, 0);
        dp[0] = 1;
        for (int i = 0; i < coins.size(); i++) 
        {
            for (int j = coins[i]; j <= amount; j++)
            {
                dp[j] += dp[j - coins[i]];
            }
        }
        return dp[amount];
    }
    int change(int amount, int left, int right) 
    {
        //dp[j]是容量为j的背包有dp[j]种方法存满
        vector<int> dp(amount + 1, 0);
        dp[0] = 1;
        for (int i = left; i <= right; i++) 
        {
            for (int j = i; j <= amount; j++) 
            {
                dp[j] += dp[j - i];
            }
        }
        return dp[amount];
    }

};
int main()
{
    vector<int> coins{ 1, 2, 5 };
    Solution S;
    int result = S.change(5, coins);
    int result2 = S.change(3, 1, 2);
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
