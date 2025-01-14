#include <iostream>

template<class T>
class Table 
{
private:
    int rows, colomns;
    T** tab;
public:
    Table(int r, int c)
    {
        rows = r;
        colomns = c;
        tab = new T* [r];
        for (int i = 0; i < r; i++)
        {
            tab[i] = new T[c];
        }
    }
    ~Table()
    {
        for (int i = 0; i < rows; i++)
        {
            delete tab[i];
        }
        delete[] tab;
    }
    int size() const { return rows * colomns; }
    const T*& operator[](int index) const { return tab[index]; }
    T*& operator[](int index) { return tab[index]; }
};

int main()
{
    auto test = Table<int>(2, 3);
    auto test2 = Table<float>(5, 3);
    auto test3 = Table<char>(7, 4);
    test[0][0] = 4;
    test2[4][1] = 16.23;
    test3[5][2] = 'a';
    std::cout << "int: " << test[0][0] << ".\t\t RAZMER: " << test.size() << std::endl;
    std::cout << "float: " << test2[4][1] << ".\t RAZMER: " << test2.size() << std::endl;
    std::cout << "char: " << test3[5][2] << ".\t RAZMER: " << test3.size() << std::endl;
    return 0;
}
