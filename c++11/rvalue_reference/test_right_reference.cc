
int main()
{
    int& a = 1;     // error, a is a left value reference
    const& c = 1;   // right, 常量左值引用，万能引用

    int&& b = 1;    // right
    int&& c = b;    // error, a is a rvalue reference, but it is a lvalue

    return 0;
}
