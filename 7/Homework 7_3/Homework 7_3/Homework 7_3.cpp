#include <iostream>

template<class T>
class SimpleUnique {
public:
    SimpleUnique(T* data) {
        _data = data;
        std::cout << "constructor called" << std::endl;
    }
    T* release() {
        T* ptr = _data;
        _data = nullptr;
        return ptr;
    }
    SimpleUnique(const SimpleUnique& other) = delete;
    SimpleUnique& operator=(const SimpleUnique& other) = delete;
    T& operator*() {
        return *_data;
    }
    ~SimpleUnique() {
        if (_data) {
            delete _data;
        }
        std::cout << "destructor called" << std::endl;
    };
    friend std::ostream& operator<<(std::ostream& os, const SimpleUnique<T>& data) {
        os << data._data;
        return os;
    };
private:
    T* _data{ nullptr };
};

int main()
{
    SimpleUnique<int> test(new int{5});
    int x = *test;
    std::cout << "ADDRESS: " << test << "\nOBJECT: " << x << std::endl;
    return 0;
}
