// 排序.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;
void bubble_sort(vector<int>& nums) 
{
    for (int i = 0; i < nums.size(); i++) 
    {
        for (int j = 1; j < nums.size() - i; j++)
        {
            if(nums[j-1]>nums[j]){
                swap(nums[j - 1], nums[j]);
            }
        }
    }
}
void InsertSort(vector<int>& nums) 
{
    if (nums.size() <= 1) 
    {
        return;
    }
    //bool hasinserted = false;
    for (int i = 1; i < nums.size(); i++)
    {
        for (int j = i-1; j >= 0; j--) 
        {
            if (nums[i] < nums[0]) 
            {
                int temp = nums[i];
                nums.erase(nums.begin() + i);
                nums.insert(nums.begin(), temp);
                break;
            }
            if (nums[i] > nums[j]) 
            {
                int temp = nums[i];
                nums.erase(nums.begin()+i);
                nums.insert(nums.begin() + j + 1, temp);
               // hasinserted = true;
                break;
            }
        }

    }
}
void quick_sort_recursive(int start, int end, vector<int>& nums) 
{
    if (start >= end) {
        return;
    }
    int base = nums[start];
    int left = start, right = end;
    while (left < right) {
        //从右向左找，比base大，right--
        while (left < right && nums[right] >= base) {
            right--;
        }
        swap(nums[left], nums[right]);
        //从左向右找，比base小，left++
        while (left < right && nums[left] <= base) {
            left++;
        }
        swap(nums[left], nums[right]);
    }
    quick_sort_recursive(start, left-1, nums);
    quick_sort_recursive(left+1, end, nums);
}
int main()
{
    vector<int> nums{ 3,4,6,1,2,4,7 };
    quick_sort_recursive(0, nums.size() - 1, nums);
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
