#include <iostream>
#include <vector>

template<class T>
void move_vectors(std::vector<T>& one, std::vector<T>& two)
{
    two = std::move(one);
}

int main()
{
    std::vector <std::string> one = { "test_string1", "test_string2" };
    std::vector <std::string> two;

    move_vectors(one, two);

    for (const auto& s : two)
        std::cout << s << ' ';
    return 0;
}
