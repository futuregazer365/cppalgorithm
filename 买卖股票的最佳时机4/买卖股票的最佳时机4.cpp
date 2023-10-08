// 买卖股票的最佳时机4.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        if (prices.size() == 0 || prices.size() == 1||k == 0)return 0;
        //定义dp数组
        vector<vector<int>> dp(prices.size(), vector<int>(2 * k + 1, 0));
        //初始化dp数组
        dp[0][0] = 0;
        for (int i = 1; i < 2 * k; i=i+2) 
        {
            dp[0][i] = -prices[0];
            dp[0][i + 1] = 0;
        }
        //递推公式
        for (int i = 1; i < prices.size(); i++) 
        {
            dp[i][0] = dp[i - 1][0];
            for (int j = 0; j < 2 * k; j += 2) 
            {
                dp[i][j + 1] = max(dp[i - 1][j + 1], dp[i - 1][j] - prices[i]);
                dp[i][j + 2] = max(dp[i - 1][j + 2], dp[i - 1][j + 1] + prices[i]);
            }
        }
        return dp[prices.size() - 1][2 * k];
    }
};
int main()
{
    vector<int>price{ 3,3,5,0,0,3,1,4 };
    Solution S;
    int result = S.maxProfit(2,price);
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
