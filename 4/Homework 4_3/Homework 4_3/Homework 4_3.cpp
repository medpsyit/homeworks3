#include <iostream>
#include <vector>

class test_func
{
public:
    test_func(std::vector<int> nums) 
    { 
        vec = nums;
        std::cout << "[IN]: ";
        for (const auto& elem : nums)
            std::cout << elem << ' ';
        std::cout << std::endl;
    }
    void operator()()
    {
        for (auto& n : vec)
            if (n % 3 == 0)
            {
                sum = sum + n;
                count++;
            }
    }
    int get_sum() { return sum; }
    int get_count() { return count; }
private:
    std::vector<int> vec;
    int sum{0}, count{0};
};

int main()
{
    std::vector<int> nums{ 4, 1, 3, 6, 25, 54 };
    test_func test(nums);
    test();
    std::cout << "[OUT]: get_sum() = " << test.get_sum() << std::endl;
    std::cout << "[OUT]: get_count() = " << test.get_count() << std::endl;
    return 0;
}
