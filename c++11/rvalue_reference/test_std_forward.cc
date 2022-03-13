// study std::forward
// 引用折叠规则：所有的右值引用叠加到右值引用上仍然是一个右值引用，其他引用折叠都为左值引用。
// 当T&&为模板参数时，输入左值，它将变成左值引用，输入右值则变成具名的右值应用。

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
    foo(param);
}

int main()
{
    // test1
    // T = const char(&)[], left, left
    std::cout << "test1" << std::endl;
    Wrapper("aaaaa");

    // test2
    // T = std::string &&
    std::cout << "test2" << std::endl;
    Wrapper(std::string("aaaaa"));        // right value, left value
    
    // test3
    // T = std::string
    std::cout << "test3" << std::endl;
    std::string&& test = "bbbb";          // left value, left value
    Wrapper(test);
    
    return 0;
}
