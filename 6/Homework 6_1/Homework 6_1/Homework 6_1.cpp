#include <iostream>
#include <vector>
#include <algorithm>

void del_dup(std::vector<int>& v)
{
    std::sort(v.begin(), v.end());
    auto e = std::unique(v.begin(), v.end());
    v.erase(e, v.end());
}

int main()
{
    std::vector<int> vec{ 1, 1, 2, 5, 6, 1, 2, 4 };
    std::cout << "[IN]: ";
    for (const auto& elem : vec)
        std::cout << elem << ' ';
    std::cout << std::endl;
    del_dup(vec);
    std::cout << "[OUT]: ";
    for (const auto& elem : vec)
        std::cout << elem << ' ';
    return 0;
}
