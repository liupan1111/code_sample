#include <iostream>
#include <cstring>
#include <vector>
using namespace std;

class A {
public:
    A(int i){
        cout << "A()" << endl;
        str = to_string(i);
    }
    ~A(){}
    A(const A& other): str(other.str){
        cout << "A&" << endl;
    }

    A(A&& other): str(other.str) {
        cout << "A&&" << endl;
    }

public:
    string str;
};

int main()
{
    vector<A> vec;
    vec.reserve(10);
    for(int i=0;i<10;i++){
        //vec.push_back(i);   //调用了10次拷贝构造函数
        vec.emplace_back(i);  //一次拷贝构造函数都没有调用过
    }
}
