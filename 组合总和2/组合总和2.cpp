// 组合总和2.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//
#include <vector>
#include <stack>
#include <algorithm>
#include <iostream>
#include <set>
using namespace std;
class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end()); // 排序候选集
        vector<int> current; // 当前正在形成的组合
        backtrack(candidates, target, 0, current);

        // 对结果进行去重操作
        set<vector<int>> uniqueResults(result.begin(), result.end());
        result.assign(uniqueResults.begin(), uniqueResults.end());

        return result;
    }

private:
    vector<vector<int>> result;

    void backtrack(vector<int>& candidates, int target, int startIndex, vector<int>& current) {
        if (target == 0) {
            result.push_back(current); // 找到一个符合条件的组合
            return;
        }

        for (int i = startIndex; i < candidates.size(); i++) {
            if (i > startIndex && candidates[i] == candidates[i - 1]) {
                continue; // 避免重复的组合
            }

            if (target - candidates[i] < 0) {
                break; // 剪枝
            }

            current.push_back(candidates[i]); // 尝试将当前数字加入组合
            backtrack(candidates, target - candidates[i], i + 1, current); // 递归调用
            current.pop_back(); // 回溯，撤销选择
        }
    }
};
int main()
{
    set<vector<int>> temp;
    vector<int> vec1 = { 1,7 };
    vector<int> vec3 = { 1,7 };
    vector<int> vec2 = { 7,1 };
    temp.insert(vec1);
    temp.insert(vec2);
    temp.insert(vec3);
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
