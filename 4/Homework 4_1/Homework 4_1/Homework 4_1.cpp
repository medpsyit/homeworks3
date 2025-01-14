#include <iostream>
#include <vector>

template <class T>
T square(T elem)
{
    return elem * elem;
}
template<class T>
std::vector<T> square(std::vector<T>& elems)
{
    for (auto& elem : elems)
        elem = square(elem);
    return elems;
}

int main()
{
    int t = 4;
    std::vector<int> test{ -1, 4, 8 };
    std::cout << "[IN]: " << t << std::endl;
    std::cout << "[OUT]: " << square(t) << std::endl;
    std::cout << "[IN]: ";
    for (const auto& elem : test)
        std::cout << elem << ' ';
    std::cout << std::endl;
    square(test);
    std::cout << "[OUT]: ";
    for (const auto& elem : test)
        std::cout << elem << ' ';
    return 0;
}
