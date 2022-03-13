// array首先向右结合，所以这个相当于(int&)array[], array是个数组，其中的元素是引用。
// 应该叫：引用的数组
// int &array[]
//
// array首先和&结合，所以array是引用，引用的对象是数组
// 应该叫做数组的引用

#include<iostream>
using namespace std;

template<typename T,int N>
void PrintValues(T (&ia)[N])
{
    for (int i = 0; i < N; i++)
    {
        cout << ia[i] << endl;
    }
}

int main()
{
    int j[2] = { 0, 1 };
    PrintValues(j);
    return 0;
}
