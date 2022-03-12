// study std::move

#include <vector>
#include <iostream>

class Annotation
{
public:
    explicit Annotation(const std::vector<int>& vec) : 
    m_vec (std::move(vec)) {}
    
    size_t getVecSize() const 
    {
        return m_vec.size();
    }
    
private:
    std::vector<int> m_vec;
};


int main()
{
    // test move basic usage
    std::vector<int> v1 = {1, 2, 3, 4};
    std::vector<int> v2 = v1;            // 通过运算符重载进行拷贝，v2 是 v1 的副本
    std::vector<int> v3 = std::move(v1); // 通过移动构造函数移动语义，v3 与 v1 交换， v1 为空， v3 = {1, 2, 3, 4}

    std::cout << "sizeof v3: " << v3.size() << std::endl;
    std::cout << "sizeof v2: " << v2.size() << std::endl;
    std::cout << "sizeof v1: " << v1.size() << std::endl;

    // test move wrong usage1
    std::vector<int> v4 = {1, 2, 3, 4};

    Annotation test(v4);
    std::cout << "sizeof test: " << test.getVecSize() << std::endl;  // output: 4
    std::cout << "sizeof v4: " << v4.size() << std::endl;          // output: 4 不是空，移动语义没有实现

}
