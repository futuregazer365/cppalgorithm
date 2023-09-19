// 整数拆分.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <vector>
#include <stack>
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int integerBreak(int n) {
        vector<int> dp(n + 1);
        dp[2] = 1;
        for (int i = 3; i <= n; i++) {
            for (int j = 1; j <= i / 2; j++) {
                dp[i] = max(dp[i], max((i - j) * j, dp[i - j] * j));
            }
        }
        return dp[n];
    }
    int integerBreak(int n) 
    {
        intergerBreakBytraversal(0, n, 1, 1);
        sort(products.begin(), products.end());
        return products[products.size() - 1];
    }
    void intergerBreakBytraversal(int sum,int target,int ji,int start) 
    {
        if (sum > target) 
        {
            return;
        }
        if (sum == target) 
        {
            products.push_back(ji);
            paths.push_back(path);
        }
        for (int i = start; i < target; i++) 
        {
            path.push_back(i);
            intergerBreakBytraversal(sum + i, target, ji * i, i);
            path.pop_back();
        }
    }
    vector<int> path;
    vector<int> products;
    vector<vector<int>> paths;
};
int main()
{
    Solution S;
    int result = S.integerBreak(6);
    S.
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
