// KMP算法.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
using namespace std;

class Solution
{
public:
    /*
    输入模式串返回next数组
    */
    void getNext(int* next, const string& s)
    {
        int j = 0;
        next[j] = 0;
        for (size_t i = 1; i < s.size(); i++)
        {
            while (s[i] != s[j] && j > 0) {
                j = next[j - 1];
            }
            if (s[i] == s[j]) {
                j++;
            }
            next[i] = j;
        }
    }
    /*
    打印int数组
    */
    void printIntArray(const int* next, size_t size)
    {
        for (int i = 0; i < size; i++) {
            cout << next[i] << " ";
        }
        cout << endl;
    }
    /*
    暴力在字符串查找模式串O(n*m)
    */
    int forceMatch(const string& findstring,const string& targetstring) 
    {
        bool get = false;
        for (int i = 0; i < findstring.size(); i++) {
            for (int j = 0, k = i; j < targetstring.size(), k < findstring.size(); j++, k++) {
                if (findstring[k] == targetstring[j]) {
                    if (j == targetstring.size() - 1) {//已匹配到
                        get = true;
                    }
                }
                else
                {
                    break;
                }
            }
            if (get) {
                return i;
            }
        }
        return -1;
    };
    /*
    使用KMP算法实现字符串匹配,返回匹配首字符位置,不匹配返回-1
    */
    int repeatedSubstringPattern(string moshichuan,string wenbenchuan) 
    {
        if (wenbenchuan.size() == 0) {
            cout << -1 << endl;            
            return -1;
        }
        if (moshichuan.size() == 0) 
        {
            cout << 0 << endl;            
            return 0;
        }
        int *next = new int[moshichuan.size()];
        getNext(next, moshichuan);
        printIntArray(next, moshichuan.size());
        int i = 0; int j = 0;
        for (j,i; i < wenbenchuan.size(),j<moshichuan.size(); i++,j++) {
            if (wenbenchuan[i] == moshichuan[j]) 
            {
            }
            else
            {
                j = next[j - 1] + 1;
            }
        }
        if (j = moshichuan.size()) //匹配成功
        {
            std::cout << i-j << endl;    
            return i-j;
        }
        cout << -1 << endl;
        return -1;
    }
};

int main()
{
    string wenbenchuan = "asdgasdjasdkfffasdf";
    string moshichuan = "asdf";
    Solution s;
    //int* next = new int[6];
    //s.getNext(next, moshichuan);
    //s.printIntArray(next, 6);
    //s.forceMatch(wenbenchuan, moshichuan);
    s.repeatedSubstringPattern(moshichuan, wenbenchuan);
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
