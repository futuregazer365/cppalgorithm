// ACM输入输出.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//
//#define 一维数组
//#define 不确定数目的一维数组
//#define 二维数组
//#define 字符串
//#define 给定数目的多字符串
//#define 不给定数目多字符串
#include <algorithm>
#define 每一行数据是逗号隔开的整数
#ifdef 一维数组
#include <iostream>
#include <vector>
using namespace std;
int main()
{
    int size;
    cin >> size;
    vector<int> vec(size);
    for (int i = 0; i < size; i++) 
    {
        cin >> vec[i];
    }
    std::cout << "Hello World!\n";
}
#endif // 一维数组

#ifdef 不确定数目的一维数组
#include <iostream>
#include <vector>
using namespace std;
int main() 
{
    vector<int> nums;
    int num;
    while (cin>>num)
    {
        nums.push_back(num);
        if (getchar() == '\n') 
        {
            break;
        }
    }
    std::cout << "Hello World!\n";
}
#endif // 不确定数目的一维数组

#ifdef 二维数组
#include <iostream>
#include <vector>
using namespace std;
int main() 
{
    int n, m = 0;
    cin >> m >> n;
    vector<vector<int>> mat(m, vector<int>(n));
    for (int i = 0; i < m; i++) 
    {
        for (int j = 0; j < n; j++) 
        {
            cin >> mat[i][j];
        }
    }
    std::cout << "Hello World!\n";
}
#endif // 二维数组

#ifdef 字符串
#include <iostream>
#include <vector>
using namespace std;
int main()
{
    string s;
    cin >> s;
}
#endif // 字符串

#ifdef 给定数目的多字符串
#include <iostream>
#include <string>
#include <vector>
#include <stdlib.h>
using namespace std;
int main()
{
    std::string str = "668";
    std::cout << atoi(str.c_str());//字符串转c字符串转int
    int i = stoi(str);//字符串转int
    int n = 0;
    cin >> n;
    vector<string> strings(n);
    for (int i = 0; i < n; i++) {
        cin >> strings[i];
    }
    std::cout << "Hello World!\n";
}
#endif

#ifdef 不给定数目多字符串
#include <iostream>
#include <vector>
#include <stdlib.h>
using namespace std;
int main()
{
    vector<string> strings;
    string str;
    while (cin >> str) 
    {
        strings.push_back(str);
        if (getchar() == '\n') {
            break;
        }
    }
    std::cout << "Hello World!\n";
}
#endif

#ifdef 每一行数据是逗号隔开的整数
#include <iostream>
#include <vector>
#include <stdlib.h>
#include <string>
#include <stdlib.h>
using namespace std;
int main()
{
    string ss = "123456";
    string sss = ss.substr(0, 1);
    int m;
    int n;
    cin >> m >> n;
    int i = getchar();
    vector<vector<int>> matrix(m);
    for (int i = 0; i < m; i++) 
    {
        string s;
        getline(cin, s);
        vector<int> vec;
        int p = 0;
        for (int q = 0; q < s.size(); q++) {//注意此处的双指针法
            p = q;
            while (s[p] != ',' && p < s.size()) 
            {
                p++;
            }
            string temp = s.substr(q, p - q);
            vec.push_back(atoi(temp.c_str()));
            q = p;
        }
        matrix[i] = vec;
        vec.clear();
    }
    std::cout << "Hello World!\n";
}
#endif
// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门使用技巧: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件
