// 一和零.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        vector<vector<int>>dp(m + 1, vector<int>(n + 1, 0));
        for (int i = 0; i < strs.size(); i++) 
        {
            int x = 0, y = 0;
            for (auto c : strs[i]) 
            {
                if (c == '0')x++;
                if (c == '1')y++;
            }
            for (int j = m; j >= x; j--) 
            {
                for (int k = n; k >= y; k--) 
                {
                    dp[j][k] = max(dp[j][k], dp[j - x][k - y] + 1);
                }
            }
        }
        return dp[m][n];
    }
};
int main()
{
    Solution S;
    vector<string> strs = {"10", "0001", "111001", "1", "0"};
    int result = S.findMaxForm(strs, 5, 3);
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
