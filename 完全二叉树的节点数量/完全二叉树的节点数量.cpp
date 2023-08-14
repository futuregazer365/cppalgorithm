// 完全二叉树的节点数量.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
// leetcode222

#include <iostream>
#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
#include <queue>
using namespace std;
/*二叉树的定义*/
template<typename T>
class TreeNode
{
public:
    T val;
    TreeNode<T>* left;
    TreeNode<T>* right;
    TreeNode() :val(), left(), right() {};
    TreeNode(T _val) :val(_val), left(), right() {};
    TreeNode(T _val, TreeNode<T>* _left, TreeNode<T>* _right) :val(_val), left(_left), right(_right) {};
};

/*前序数组构造二叉树 中——左——右*/
template<typename T>
TreeNode<T>* bulidTreeFromPreorder(const std::vector<T>& preorder, int& index)
{
    if (index >= preorder.size() || preorder[index] == T('\0'))
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
/*前序数组构造二叉树 中——左——右*/
template<typename T>
TreeNode<T>* bulidTreeFromPreorder(const std::vector<T>& preorder)
{
    int index = 0;
    return bulidTreeFromPreorder(preorder, index);
}
template<typename T>
class Solution {
public:
    int countNodes(TreeNode<T>* root) {
        int result = 0;
        middletraversal(root, result);
        return result;
    }
    /*中序遍历二叉树*/
    void middletraversal(TreeNode<T>* node,int &count)
    {
        if (node == nullptr)return ;
        middletraversal(node->left, count);
        count++;
        middletraversal(node->right, count);
    }
    /*后序遍历二叉树*/
    int getNum(TreeNode<T>* node) 
    {
        if (node == nullptr) return 0;
        int left = getNum(node->left);
        int right = getNum(node->right);
        return left + right + 1;
    }
    /*利用满二叉树性质*/
    int countNodesV2(TreeNode<T>* root) {
        if (root == nullptr) return 0;
        TreeNode<T>* left = root->left;
        TreeNode<T>* right = root->right;
        int leftDepth = 0, rightDepth = 0; // 这里初始为0是有目的的，为了下面求指数方便
        while (left) {  // 求左子树深度
            left = left->left;
            leftDepth++;
        }
        while (right) { // 求右子树深度
            right = right->right;
            rightDepth++;
        }
        if (leftDepth == rightDepth) {
            return (2 << leftDepth) - 1; // 注意(2<<1) 相当于2^2，所以leftDepth初始为0
        }
        return countNodes(root->left) + countNodes(root->right) + 1;
    }
};
int main()
{
    std::vector<char> preorder = { '1', '2','3','4','5'};
    TreeNode<char>* root = bulidTreeFromPreorder(preorder);
    Solution<char> S;
    int count = S.countNodes(root);
    int count2 = S.getNum(root);
    int count3 = S.countNodesV2(root);
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
