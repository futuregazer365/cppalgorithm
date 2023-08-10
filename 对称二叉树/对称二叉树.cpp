// 对称二叉树.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
// 
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
    bool isSymmetric(TreeNode<T>* root) {

    }
    /*后序遍历二叉树*/
    void laterorderTraversal(TreeNode<T>* cur ,vector<T> &vec)
    {
        if (cur == nullptr)return;
        laterorderTraversal(cur->left, vec);
        laterorderTraversal(cur->right, vec);
        vec.push_back(cur->val);
    }
    /*后序遍历二叉树*/
    vector<T> laterorderTraversal(TreeNode<T>* cur) 
    {
        vector<T> result;
        laterorderTraversal(cur, result);
        return result;
    }
};

int main()
{
    std::vector<char> preorder = { '6', '4','1','\0','\0','3','\0','\0','7','5','\0','\0','8' };
    TreeNode<char>* root = bulidTreeFromPreorder(preorder);
    Solution<char> S;
    vector<char> result = S.laterorderTraversal(root);
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
