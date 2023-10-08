// 背包-01背包.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <vector>
using namespace std;
#include <algorithm>
/*
@params:物品的重量
@params:物品的价值
*/
void print2DdpVector(const vector<vector<int>>& dp) 
{
    for (int i = 0; i < dp.size(); i++) 
    {
        for (int j = 0; j < dp[0].size(); j++) 
        {
            cout << dp[i][j] << '\t';
        }
        cout << '\n';
    }
}
int test_2_wei_bag_problem1(const vector<int> &weight, const vector<int> &value,int bagweight)
{
    vector<vector<int>> dp(weight.size(), vector<int>(bagweight + 1, 0));//[0,i]之间的物品任意取放在容量为j的背包里所能取到的最大价值
    //初始化dp数组
    for (int i = 0; i < weight.size(); i++) 
    {
        dp[i][0] = 0;
    }
    for (int i = 1; i < bagweight + 1; i++) 
    {
        if (weight[0] <= bagweight) 
        {
            dp[0][i] = value[0];
        }
        else
        {
            dp[0][i] = 0;
        }
    }
    //遍历dp数组
    for (int i = 1; i < weight.size(); i++)//遍历物品 
    {

        for (int j = 1; j <= bagweight; j++) //遍历背包
        {
            if (j < weight[i])dp[i][j] = dp[i - 1][j];
            else {
                dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - weight[i]] + value[i]);
            }
        }
    }
    print2DdpVector(dp);
    return dp[weight.size() - 1][bagweight];

}

int test_1_wei_bag_problem1(const vector<int>& weight, const vector<int>& value, int bagweight)
{
    vector<int> dp(bagweight + 1, 0);//容量为j的背包所能装的物品的最大值
    for (int i = 0; i < weight.size(); i++) 
    {
        for (int j = bagweight; j >= weight[i]; j--)
        {
            dp[j] = max(dp[j], dp[j - weight[i]] + value[i]);
        }
    }


}
int main()
{
    vector<int> weight = { 1, 3, 4 };
    vector<int> value = { 15, 20, 30 };
    int bagweight = 4;
    test_2_wei_bag_problem1(weight, value, bagweight);
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
