#include <iostream>
#include <map>
#include <unordered_map>

std::multimap<int, char, std::greater<int>> sort_sym_amount(std::unordered_map<char, int> sym)
{
    std::multimap<int, char, std::greater<int>> temp_sym;
    for (const auto& s : sym)
    {
        int tv = s.second;
        char tc = s.first;
        temp_sym.insert({ tv, tc });
    }
    return temp_sym;
}

int main()
{
    std::string msg{ "Hello world!!" };
    std::cout << "[IN]: " << msg << std::endl;
    std::unordered_map<char, int> sym_in;
    std::multimap<int, char, std::greater<int>> sym_out;
    for (const auto& c : msg)
    {
        if (sym_in[c] >= 1)
        {
            sym_in[c]++;
        } else { sym_in[c] = 1; }
    }
    sym_out = sort_sym_amount(sym_in);
    std::cout << "[OUT]: " << std::endl;
    for (const auto& elem : sym_out)
        std::cout << elem.second << ": " << elem.first << std::endl;
    return 0;
}