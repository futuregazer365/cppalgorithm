// 斐波那契数列.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
// leetcode 509

#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <string>
using namespace std;
class Solution {
public:
    int fib(int n) {
        if (n == 1)return 1;
        if (n == 2)return 1;
        vector<int> dp(n + 1);
        int sum;
        dp[0] = 1;
        dp[1] = 1;
        for (size_t i = 2; i <= n; i++)
        {
            dp[i] = dp[i - 1] + dp[i - 2];
        }
        return dp[n];
    }
    int fib2(int n) {
        if (n == 1)return 1;
        if (n == 2)return 1;
        vector<int> dp(2);
        int sum;
        dp[0] = 1;
        dp[1] = 1;
        for (size_t i = 2; i <= n; i++)
        {
            sum = dp[0] + dp[1];
            dp[0] = dp[1];
            dp[1] = sum;
        }
        return sum;
    }
    int fib3(int N) 
    {
        if (N < 2) return 1;
        return fib(N - 1) + fib(N - 2);
    }
private:
    int count = 1;
};
int main()
{
    Solution S;
    int result = S.fib2(6);
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
