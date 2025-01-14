﻿#include <iostream>
#include <vector>
#include <set>
#include <list>

template<class T>
void print_container(T a)
{
    auto It = a.begin();
    while (It != a.end())
    {
        std::cout << *It << " ";
        It++;
    }
    std::cout << std::endl;
}

int main()
{
    std::set<std::string> test_set = { "one", "two", "three", "four" };
    print_container(test_set);

    std::list<std::string> test_list = { "one", "two", "three", "four" };
    print_container(test_list);

    std::vector<std::string> test_vector = { "one", "two", "three", "four" };
    print_container(test_vector);
    return 0;
}
