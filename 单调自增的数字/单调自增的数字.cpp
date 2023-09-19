// 单调自增的数字.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
// leetcode 738

#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <string>

using namespace std;
class Solution {
public:
    int monotoneIncreasingDigits(int n) {
        std::vector<int> digits; // 用于存储每一位的 vector
        // 将整数的每一位存储到 vector 中
        while (n > 0) {
            int digit = n % 10; // 获取最后一位
            digits.push_back(digit); // 将最后一位添加到 vector
            n /= 10; // 去掉最后一位
        }
        std::reverse(digits.begin(), digits.end());

        int flag = digits.size()-1;
        for (int i = digits.size() - 2; i >= 0; i--) 
        {
            if (digits[i] > digits[i + 1]) 
            {
                digits[i] -= 1;
                flag = i + 1;;
            }
        }
        for (int i = flag; i < digits.size(); i++) 
        {
            digits[i] = 9;
        }
        int number = 0;
        int64_t multiplier = 1;
        // 从 vector 的末尾开始遍历，以考虑位权
        for (int i = digits.size() - 1; i >= 0; i--) {
            number += digits[i] * multiplier;
            multiplier *= 10; // 更新位权
        }
        
        return number;
    }
};
int main()
{
    Solution S;
    S.monotoneIncreasingDigits(100);
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
