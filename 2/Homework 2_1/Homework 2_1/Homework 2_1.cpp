#include <iostream>

class smart_array 
{
public:
	smart_array(int size) 
	{
		_size = size;
		arr = new int[size];
	}
	void add_element(int element)
	{
		if (count < _size)
		{
			arr[count] = element;
			count++;
		}
		else
		{
			throw std::out_of_range("Запись за пределами массива!");
		}
	}
	int get_element(int index)
	{
		if (index < _size)
		{
			return arr[index];
		}
		else
		{
			throw std::out_of_range("Индекс за пределами массива!");
		}
	}
	~smart_array()
	{
		if (arr != nullptr)
		{
			delete[] arr;
		}
	}
private:
	int* arr{ nullptr };
	int _size{};
	int count{ 0 };
};

int main()
{
	setlocale(LC_CTYPE, "rus");
	try {
		smart_array arr(5);
		arr.add_element(1);
		arr.add_element(4);
		arr.add_element(155);
		arr.add_element(14);
		arr.add_element(15);
		std::cout << arr.get_element(2) << std::endl;
	}
	catch (const std::exception& ex) {
		std::cout << ex.what() << std::endl;
	}
    return 0;
}
