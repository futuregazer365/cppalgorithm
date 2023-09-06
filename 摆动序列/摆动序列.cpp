// 摆动序列.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        if (nums.size() == 1)return 1;
        if (nums.size() == 2 && nums[0] != nums[1])return 2; 
        if (nums.size() == 2 && nums[0] == nums[1])return 1;
        int prediff = 0, curdiff = 0, result = 0;
        int step = 0;
        for (int i = 1; i <= nums.size() - 2; i++)
        {
            prediff = nums[i - step] - nums[i - 1 - step];
            curdiff = nums[i + 1] - nums[i];
            step = 0;
            if (prediff > 0 && curdiff < 0)
            {
                result++;
            }
            else if (prediff < 0 && curdiff>0)
            {
                result++;
            }
            else if (curdiff == 0)
            {
                while (i <= nums.size() - 2 && nums[i + 1] - nums[i] == 0)
                {
                    i++;
                    step++;
                }
                i--;
            }
        }
        if (nums[0] == nums[1])return ++result;
        if (nums[0] != nums[1])return result + 2;
    }
};
int main()
{
    vector<int> vec = { 1, 17, 5, 10, 13, 15, 10, 5, 16, 8 };
    vector<int> vec1 = { 1, 17, 17,17,18,18,10 };
    vector<int> vec2 = { 3,3,3,2,5 };
    Solution S;
    int result = S.wiggleMaxLength(vec2);
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
