// 组合总和2.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
// leetcode40
#include <vector>
#include <stack>
#include <algorithm>
#include <iostream>
#include <set>
using namespace std;
class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        path.clear();
        result.clear();
        sort(candidates.begin(), candidates.end());//注意candidates的排序方法
        vector<bool> used(candidates.size(), false);//注意used的初始化方式
        backtracking(target, 0, 0, candidates, used);
        return result;
    }
    void backtracking(int targetSum, int sum, int startIndex, const vector<int>& candidates, vector<bool>& uesd) {
        //递归中断
        if (sum > targetSum)return;
        if (sum == targetSum) {
            result.push_back(path);
            return;
        }
        for (int i = startIndex; i < candidates.size(); i++) {
            //去重
            if (i > 0 && candidates[i] == candidates[i - 1] && uesd[i - 1] == false) {
                continue;
            }
            path.push_back(candidates[i]);
            sum += candidates[i];
            uesd[i] = true;
            backtracking(targetSum, sum, i + 1, candidates, uesd);
            path.pop_back();
            sum -= candidates[i];
            uesd[i] = false;
        }
    }
private:
    vector<int> path;
    vector<vector<int>> result;
};
int main()
{
    vector<int> vec1 = { 10,1,2,7,6,1,5 };
    vector<int> vec2 = { 1,1,2};
    Solution S;
    vector<vector<int>> result = S.combinationSum2(vec1, 8);
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
