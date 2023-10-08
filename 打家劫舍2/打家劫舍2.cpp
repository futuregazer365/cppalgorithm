// 打家劫舍2.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
// leetcode 213

#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int robb(vector<int>& nums) {
        //dp[i]是指 考 虑nums第i个房间是，最大的抢劫数目
        vector<int>dp(nums.size(), 0);
        dp[0] = nums[0];
        dp[1] = max(nums[0], nums[1]);
        for (int i = 2; i < nums.size(); i++)
        {
            dp[i] = max(dp[i - 1], dp[i - 2] + nums[i]);
        }
        return dp[nums.size() - 1];
    }
    int rob(vector<int>& nums) {
        if (nums.size() == 0|| nums.size() == 1)return 0;
        //情况1 首位两端都不不考虑 情况2 考虑首端
        vector<int> nums1(nums.begin(), nums.end()-1);
        int result1 = robb(nums1);
        //情况3 考虑尾端
        vector<int> nums2(nums.begin() + 1, nums.end());
        int result2 = robb(nums2);
        return max(result1, result2);
    }
};
int main()
{
    vector<int> nums{ 2,3,2};
    Solution S;
    int result = S.rob(nums);
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
