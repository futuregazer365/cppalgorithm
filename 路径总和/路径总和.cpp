// 路径总和.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
// leetcode 112
#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

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
template<typename T>
TreeNode<T>* bulidTreeFromPreorder(const std::vector<T>& preorder, int& index)
{
    if (index >= preorder.size() || preorder[index] == T(0))
    {
        index++;
        return nullptr;
    }
    TreeNode<T>* node = new TreeNode<T>(preorder[index]);
    index++;
    node->left = bulidTreeFromPreorder(preorder, index);
    node->right = bulidTreeFromPreorder(preorder, index);
    return node;
}
/*前序数组构造二叉树*/
template<typename T>
TreeNode<T>* buildTreeFromPreorder(const std::vector<T>& preorder)
{
    int index = 0;
    return bulidTreeFromPreorder(preorder, index);
}
template<typename T>
class Solution {
public:
    bool hasPathSum(TreeNode<T>* root, int targetSum) {
        if (root == NULL) return false;
        return traversal(root, targetSum - (root->val));
    }

    bool traversal(TreeNode<T>* root, int targetSum)
    {
        if (root->left == nullptr && root->right == nullptr && targetSum == 0)
        {
            return true;
        }
        if (root->left == nullptr && root->right == nullptr && targetSum != 0)
        {
            return false;
        }
        bool l = false; bool r = false;
        if (root->left)
        {
            targetSum -= root->left->val;
            l = traversal(root->left, targetSum);
            targetSum += root->left->val;
        }
        if (root->right)
        {
            targetSum -= root->right->val;
            r = traversal(root->right, targetSum);
            targetSum += root->right->val;
        }
        return l || r;
    }
};

int main()
{
    std::vector<int> preorder = { 5,4,11,0,0,0,8,13,0,0,4 };
    TreeNode<int>* root = buildTreeFromPreorder(preorder);
    Solution<int> s;
    bool get = s.hasPathSum(root, 20);
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
