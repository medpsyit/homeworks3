#include <iostream>
#include <set>

int main()
{
    int amount{ 0 }, num{};
    std::set<int, std::greater<int>> mySet;
    std::cout << "[IN]: " << std::endl;
    std::cin >> amount;
    do
    {
        std::cin >> num;
        mySet.insert(num);
        amount--;
    } while (amount != 0);
    std::cout << "[OUT]: " << std::endl;
    for (const auto& elem : mySet)
        std::cout << elem << std::endl;
    return 0;
}