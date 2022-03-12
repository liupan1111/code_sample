// use g++ -fno-elide-constructors to compile
// 为了验证，const左值引用的意义：
// const int& a = 1;
// 为什么要做左值引用一个右值的设计。主要是为了传递临时变量右值

#include <iostream>
using namespace std;

class Copyable {
public:
    Copyable(){}
    Copyable(const Copyable &o) {
        cout << "Copied" << endl;
    }
};
Copyable ReturnRvalue() {
    return Copyable(); //返回一个临时对象
}
void AcceptVal(Copyable a) {

}
void AcceptRef(const Copyable& a) {

}

int main() {
    // const int&a = 1; // right
    // int& a = 1;      // error
    cout << "pass by value: " << endl;
    AcceptVal(ReturnRvalue()); // 应该调用两次拷贝构造函数
    cout << "pass by reference: " << endl;
    AcceptRef(ReturnRvalue()); //应该只调用一次拷贝构造函数
}
