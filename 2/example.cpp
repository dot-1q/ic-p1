#include <cstddef>
#include <fstream>
#include <iostream>
#include <iterator>
#include <ostream>
#include <vector>
#include <algorithm>

void f(double x)
{
    std::cout << sizeof(x) << "  " << x << std::endl;
}

template<class T>
void func(T x)
{
    std::cout << "**" << sizeof(x) << "  " << x << std::endl;
}

int main()
{
    std::cout << "Hello World!" << std::endl;
    std::cout << "Hello World2!" << std::endl;
    f(100);
    func(20);
    func("STRING");

    std::ifstream ifs("nums.txt");
    std::ofstream ofs("out.txt");

    int x;

    while(ifs >> x)
    {
        std::cout << x << std::endl;
        ofs << x << std::endl;
    }
    
    std::vector<int> v1;
    std::sort(v1.begin(),v1.end());

    return 0;
}
