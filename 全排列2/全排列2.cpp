// 全排列2.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
// leetcode 47

#include <iostream>
#include <algorithm>
#include <iostream>
#include <set>
#include <vector>
using namespace std;
class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<bool> used(nums.size(), false);
        sort(nums.begin(), nums.end()); // 排序
        backtracking(nums, used);
        return result;
    }
    void backtracking(vector<int>& nums,vector<bool>&used) {
        if (path.size() == nums.size()) {
            result.push_back(path);
            return;
        }
        for (int i = 0; i < nums.size(); i++) {
            if (i > 0 && nums[i] == nums[i - 1] && !used[i - 1]) {//去重
                continue;
            }
            else {
                if (used[i] == false) {//此元素没用过
                    path.push_back(nums[i]);
                    used[i] = true;
                    backtracking(nums, used);
                    path.pop_back();
                    used[i] = false;
                }
            }
        }
    };
    vector<int> path;
    vector<vector<int>> result;
};
int main()
{
    vector<int> vec = {3,3,0,3 };
    Solution S;
    vector<vector<int>> result = S.permuteUnique(vec);
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
