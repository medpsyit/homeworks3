#include <iostream>
#include <vector>
#include <string>

class big_integer
{
public:
    big_integer(std::string num) {
        _num = new long long[num.size()];
        *_num = stoll(num);
        std::cout << "constructor called" << std::endl;
    }

    big_integer& operator+(const big_integer& other) {
        big_integer tmp;
        *tmp._num = *_num + *other._num;
        return tmp;
    }

    template<class T>
    big_integer& operator*(const T& other) {
        big_integer tmp;
        *tmp._num = *_num * other;
        return tmp;
    }

    template<>
    big_integer& operator*(const big_integer& other) {
        big_integer tmp;
        *tmp._num = *_num * *other._num;
        return tmp;
    }

    big_integer(const big_integer& other) 
        : big_integer() {
        _num = other._num;
    }

    big_integer(big_integer&& other) noexcept 
        : _num(std::exchange(other._num, nullptr)) {}

    big_integer& operator=(const big_integer& other) {
        return *this = big_integer(other);
    }

    big_integer& operator=(big_integer&& other) noexcept {
        std::swap(_num, other._num);
        return *this;
    }

    friend std::ostream& operator<<(std::ostream& os, const big_integer& num) {
        os << *num._num;
        return os;
    };

    /*~big_integer() {
        if (_num)
        {
            delete[] _num;
            std::cout << "destructor called" << std::endl;
        }
    }*/
private:
    big_integer() { 
        _num = new long long[1];
    }
    long long* _num{nullptr};
};




int main()
{
    auto number1 = big_integer("114575");
    auto number2 = big_integer("78524");
    auto result = number1 + number2;
    auto result2 = number1 * 2;
    auto result3 = number1 * number2;
    std::cout << result << std::endl; // 193099
    std::cout << result2 << std::endl; // 229150
    std::cout << result3 << std::endl; // 8996887300
    return 0;
}