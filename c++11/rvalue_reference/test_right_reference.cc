void process(int& i){
    cout << "process(int&):" << i << endl;
}
void process(int&& i){
    cout << "process(int&&):" << i << endl;
}

void myforward(int&& i){
    cout << "myforward(int&&):" << i << endl;
    process(i);
}

void myforward1(int&& i){
    cout << "myforward(int&&):" << i << endl;
    process(std::forward<int>(i));
}

int main()
{
    // int& a = 1;     // error, a is a left value reference
    const& c = 1;   // right, 常量左值引用，万能引用

    int&& b = 1;    // right
    int&& c = b;    // error, a is a rvalue reference, but it is a lvalue

    int a = 0;
    process(a); //a被视为左值 process(int&):0
    process(1); //1被视为右值 process(int&&):1
    process(move(a)); //强制将a由左值改为右值 process(int&&):0
    myforward(2);  //右值经过forward函数转交给process函数，却称为了一个左值，
    //原因是该右值有了名字  所以是 process(int&):2
    myforward(move(a));  // 同上，在转发的时候右值变成了左值  process(int&):0
    // myforward(a) // 错误用法，右值引用不接受左值
    
    myforward1(2); // process(int&&):2
    
    return 0;
}
