// 柠檬水找零.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
// leetcode 860

#include <iostream>
#include <vector>
#include <set>
using namespace std;
class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        multiset<int> cash;
        for (int i = 0; i < bills.size(); i++) 
        {
            if (bills[i] == 5) { cash.insert(5); std::cout << "找到了\n"; continue; }
            if (bills[i] == 10) {//找5元
                if (cash.find(5) != cash.end()) {
                    cash.erase(cash.find(5));
                    cash.insert(10);
                    std::cout << "找到了\n";
                    continue;
                }
                else {
                    return false;
                }
            }
            if (bills[i] == 20) {//找15块
                if (cash.find(10) != cash.end()&& cash.find(5) != cash.end()) {
                    cash.erase(cash.find(10)); 
                    cash.erase(cash.find(5));
                    cash.insert(20);
                    std::cout << "找到了\n";
                    continue;
                }
                if (cash.count(5)>=3) {
                    cash.erase(cash.find(5));
                    cash.erase(cash.find(5));
                    cash.erase(cash.find(5));
                    cash.insert(20);
                    std::cout << "找到了\n";
                    continue;
                }
                return false;
            }
        }
        return true;
    }
};
int main()
{
    Solution S;
    vector<int> ratings = { 5,5,10,20,5,5,5,5,5,5,5,5,5,10,5,5,20,5,20,5 };
    int count = S.lemonadeChange(ratings);
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
