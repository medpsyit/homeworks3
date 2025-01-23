#include <iostream>
#include <vector>
#include <exception> 

class big_integer
{
public:
    big_integer(std::string num) {
        for (const auto& c : num) {
            int n = c - '0';
            _num.push_back(n);
        }
    }

    big_integer operator+(const big_integer& other) {
        big_integer tmp = sum(_num, other._num);
        return tmp;
    }

    big_integer operator*(const int other) {
        big_integer tmp = multi(_num, other);
        return tmp;
    }

    big_integer(const big_integer& other) 
        : big_integer() {
        _num = other._num;
    }

    big_integer(big_integer&& other) noexcept {
        _num = other._num;
    }

    big_integer& operator=(const big_integer& other) {
        return *this = big_integer(other);
    }

    big_integer& operator=(big_integer&& other) noexcept {
        if (this != &other) {
            std::swap(_num, other._num);
        }
        return *this;
    }

    friend std::ostream& operator<<(std::ostream& os, const big_integer& num) {
        for (const auto& n : num._num) {
            os << n;
        }
        return os;
    };

private:
    big_integer() {}
    std::vector<int> _num;

    big_integer sum(std::vector<int> first, std::vector<int> second)
    {
        big_integer tmp;
        int carry{ 0 }, f{ 0 }, s{ 0 }, t_sum{ 0 };
        while (!((first.empty()) && 
                (second.empty()) && 
                (carry == 0))) {
            if (first.empty()) {
                f = 0;
            }
            else {
                f = first.back();
                first.pop_back();
            }
            if (second.empty()) {
                s = 0;
            }
            else {
                s = second.back();
                second.pop_back();
            }
            t_sum = f + s + carry;
            if (t_sum > 9)
            {
                carry = 1;
                t_sum = t_sum % 10;
            }
            else {
                carry = 0;
            }
            tmp._num.push_back(t_sum);
        }
        big_integer tmp2;
        for (auto iter{ tmp._num.crbegin() }; iter != tmp._num.crend(); ++iter)
        {
            tmp2._num.push_back(*iter);
        }
        return tmp2;
    }

    big_integer multi(std::vector<int> first, int second) {
        if (second / 10 > 0)
        {
            throw std::exception("multiplier too big!");
        }
        else {
            big_integer tmp;
            int carry{ 0 }, f{ 0 }, t_multi{ 0 };
            while (!((first.empty()) &&
                (carry == 0))) {
                if (first.empty()) {
                    f = 0;
                }
                else {
                    f = first.back();
                    first.pop_back();
                }
                t_multi = f * second + carry;
                if (t_multi > 9)
                {
                    carry = t_multi / 10;
                    t_multi = t_multi % 10;
                }
                else {
                    carry = 0;
                }
                tmp._num.push_back(t_multi);
            }
            big_integer tmp2;
            for (auto iter{ tmp._num.crbegin() }; iter != tmp._num.crend(); ++iter)
            {
                tmp2._num.push_back(*iter);
            }
            return tmp2;
        }
    }
};


int main()
{
    //auto number1 = big_integer("999999999999999999999");
    auto number1 = big_integer("114575");
    auto number2 = big_integer("78524");
    auto result = number1 + number2;
    try {
        auto result2 = number1 * 5;
        std::cout << result << std::endl; // 193099
        std::cout << result2 << std::endl; // 572875
    }
    catch (std::exception& ex) { std::cout << ex.what() << std::endl; }
    return 0;
}