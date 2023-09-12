// 分发糖果.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int candy(vector<int>& ratings) {
        vector<int> candy1(ratings.size());
        vector<int> candy2(ratings.size());
        candy1[0] = 1;
        candy2[ratings.size() - 1] = 1;
        int sum = 0;
        for (int i = 1; i < ratings.size(); i++) 
        {
            if (ratings[i] > ratings[i - 1]) {
                candy1[i] = candy1[i - 1] + 1;
            }
            else {
                candy1[i] = 1;
            }
        }
        for (int i = ratings.size() - 2; i >= 0; i--) 
        {
            if (ratings[i] > ratings[i + 1]) {
                candy2[i] = candy2[i + 1] + 1;
            }
            else {
                candy2[i] = 1;
            }
        }
        for (int i = 0; i < ratings.size(); i++) 
        {
            if (candy1[i] > candy2[i]) {
                sum += candy1[i];
            }
            else {
                sum += candy2[i];
            }
        }
        return sum;
    }
};
int main()
{
    Solution S;
    vector<int> ratings = { 1,2,2,5,4,3,2 };
    int count = S.candy(ratings);
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
