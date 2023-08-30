// 组合-回溯法2.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <vector>
#include <stack>
#include <algorithm>
#include <iostream>

using namespace std;
class Solution
{


public:
    vector<vector<int>> combine(const vector<int> &vec,int k) 
    {
        this->k = k;
        this->vec = vec;
        backtracking(0);
        return result;
    }
    void backtracking(int startindex) 
    {
        if (path.size() == k) {
            result.push_back(path);
            return;
        }
        for (int i = startindex; i <= (vec.size()-(k-path.size())); i++) 
        {
            path.push_back(vec[startindex]);
            backtracking(++startindex);
            path.pop_back();
        }
        return;
    }
private:
    int k;
    vector<int> vec;
    vector<int> path;
    vector<vector<int>> result;
};
int main()
{
    vector<int> vec = { 2,3,4,6,7 };
    Solution S;
    vector<vector<int>> result = S.combine(vec,3);
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
