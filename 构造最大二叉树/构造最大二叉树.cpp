// 构造最大二叉树.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
// leetcode 654
#include <vector>
#include <stack>
#include <algorithm>
#include <iostream>
using namespace std;
/*二叉树的定义*/
template<typename T>
class TreeNode
{
public:
    T val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() :left(nullptr), right(nullptr) {};
    TreeNode(T _val) :val(_val), left(nullptr), right(nullptr) {};
    TreeNode(T _val, TreeNode* _left, TreeNode* _right) :val(_val), left(_left), right(_right) {};

};
class Solution
{
public:
    TreeNode<int>* traversal(vector<int> &nums, int left, int right) //left 和right是数组左右边界，保持左闭右开原则
    {
        if (left >= right) {
            return nullptr;
        }
        //找到数组最大值
        int maxValueIndex = 0;
        int maxValue = 0;
        for (int i = left; i < right; i++)
        {
            if (nums[i] >= maxValue) {
                maxValueIndex = i;
                maxValue = nums[i];
            }
        }
        TreeNode<int>* root = new TreeNode<int>(maxValue);
        root->left = traversal(nums, left, maxValueIndex);
        root->right = traversal(nums, maxValueIndex + 1, right);
        return root;
    }
    TreeNode<int>* constructMaximumBinaryTree(vector<int>& nums) {
        return traversal(nums, 0, nums.size());
    }
};
class Solution2 {
private:
    // 在左闭右开区间[left, right)，构造二叉树
    TreeNode<int>* traversal(vector<int>& nums, int left, int right) {
        if (left >= right) return nullptr;

        // 分割点下标：maxValueIndex
        int maxValueIndex = left;
        for (int i = left + 1; i < right; ++i) {
            if (nums[i] > nums[maxValueIndex]) maxValueIndex = i;
        }

        TreeNode<int>* root = new TreeNode<int>(nums[maxValueIndex]);

        // 左闭右开：[left, maxValueIndex)
        root->left = traversal(nums, left, maxValueIndex);

        // 左闭右开：[maxValueIndex + 1, right)
        root->right = traversal(nums, maxValueIndex + 1, right);

        return root;
    }
public:
    TreeNode<int>* constructMaximumBinaryTree(vector<int>& nums) {
        return traversal(nums, 0, nums.size());
    }
};
int main()
{
    vector<int> consvec = { 3,2,1,6,0,5 };
    Solution S;
    Solution2 SS;
    TreeNode<int> * root = S.constructMaximumBinaryTree(consvec);
    TreeNode<int>* root2 =  SS.constructMaximumBinaryTree(consvec);
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
