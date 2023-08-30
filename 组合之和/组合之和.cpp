// 组合之和.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//
//leetcode 216
#include <vector>
#include <stack>
#include <algorithm>
#include <iostream>
using namespace std;


class Solution {
public:
    /*
    k 组合的个数
    n 和的大小
    */
    vector<vector<int>> combinationSum3(int k, int n) {
       backingtracking(k, 0, n, 1);
       return result;
    }
    void backingtracking(int k,int sum,int n,int startindex) 
    {
        //中断递归
        if (sum > n) { return; }//剪枝
        if (path.size() == k) {
            if (sum == n) {
                result.push_back(path);
                return;
            }
        }
        //递归逻辑
        for (int i = startindex; i <= n-(k-path.size())+1; i++) {//剪枝
            sum += i;
            path.push_back(i);
            backingtracking(k, sum, n, ++startindex);
            sum -= i;
            path.pop_back();//回溯
        }
    }
private:
    vector<int> path;
    vector<vector<int>> result;
};
int main()
{
    Solution S;
    vector<vector<int>> result = S.combinationSum3(2, 6);
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
