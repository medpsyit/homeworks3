#include "include/parser.h"
#include <windows.h>

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    try {
        ini_parser parser("../../../test.ini"); // The project in the "out" folder, but "test.ini" in the common folder with "main.cpp".
        auto value_i = parser.get_value<int>("2.var1");
        auto value_d = parser.get_value<double>("1.var1");
        auto value_s = parser.get_value<std::string>("2.var2");
        std::cout << "VAL1: " << value_i << "\nVAL2: " << value_d 
                  << "\nVAL3: " << value_s << std::endl;
    }
    catch (std::exception& ex) { std::cout << ex.what() << std::endl; }
    return 0;
}