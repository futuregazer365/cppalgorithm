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
    /*递归判断二叉树是否为对称二叉树*/
    bool isSymmetric(TreeNode<T>* root) {
        TreeNode<T>* left = root->left;
        TreeNode<T>* right = root->right;
        return compare(right, left);
    }
    bool compare(TreeNode<T>* left, TreeNode<T>* right) 
    {
        if (left == nullptr && right != nullptr)return false;
        else if (left != nullptr && right == nullptr)return false;
        else if (left == nullptr && right == nullptr)return true;
        else if (left->val != right->val)return false;
        bool outside = compare(left->left, right->right);
        bool inside = compare(left->right, right->left);
        return outside && inside;
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
    /*反转二叉树*/
    TreeNode<T>* invertTree(TreeNode<T>* node)
    {
        if (node == nullptr)return node;
        swap(node->left, node->right);
        invertTree(node->left);
        invertTree(node->right);
        return node;
    }
    /*自己又写了一边用于加深印象*/
    bool compare(TreeNode<T>* left, TreeNode<T>right) 
    {
        if (left == nullptr && right != nullptr)return false;
        else if (left != nullptr && right == nullptr)return false;
        else if (left == nullptr && right == nullptr)return true;
        else if (left->val != right->val)return false;
        bool outside = compare(left->left, right->right);
        bool inside = compare(left->right, right->left);
        return outside && inside;
    }
};

int main()
{
    std::vector<char> preorder = { '1', '2','2','\0','\0','\0','2','\0','3','\0','\0','\0' };
    TreeNode<char>* root = bulidTreeFromPreorder(preorder);
    TreeNode<char>* root2 = bulidTreeFromPreorder(preorder);
    Solution<char> S;    
    TreeNode<char>* invertedTree = S.invertTree(root2);
    vector<char> result = S.laterorderTraversal(root);
    vector<char> result2 = S.laterorderTraversal(root2);
    //通过判断反转后的二叉树是否和原二叉树相等判断是否为对称二叉树
    if (result == result2) 
    {
        std::cout << "是对称二叉树"<<endl;
    }
    else 
    {
        std::cout << "不是对称二叉树" << endl;
    }
    //使用递归判断
    bool compare = S.isSymmetric(root);
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
