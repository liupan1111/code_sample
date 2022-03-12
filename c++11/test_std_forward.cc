// study std::forward
#include <string>
#include <iostream>

// 目标函数
void foo(const std::string &str)   // 接收左值
{
    std::cout << "foo receive left value!" << std::endl;
}

void foo(std::string &&str)        // 接收右值
{
    std::cout << "foo receive right value!" << std::endl;
}

template <typename T>
void Wrapper(T &&param)
{
    foo(std::forward<T>(param));  // 完美转发
}

int main()
{
    foo("aaaa");

    // test1: right value directly
    Wrapper("aaaa");        // right value
    
    // test2: left value, compile error
    
    const std::string test;
    Wrapper(test);
    
    return 0;
}
