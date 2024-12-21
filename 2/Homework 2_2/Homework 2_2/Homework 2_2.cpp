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
			throw std::out_of_range("запись за пределами массива!");
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
			throw std::out_of_range("индекс за пределами массива!");
		}
	}

	smart_array& operator=(const smart_array& array)
	{
		if (&array != this)
		{
			*arr = *array.arr;
			_size = array._size;
			count = array.count;
			if (count > 1)
			{
				for (int i = 1; i < count; i++)
				{
					arr[i] = array.arr[i];
				}
			}
		}
		return *this;
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

		smart_array new_array(2);
		new_array.add_element(44);
		new_array.add_element(34);

		arr = new_array;

		std::cout << arr.get_element(1) << std::endl;
		std::cout << new_array.get_element(1) << std::endl;
	}
	catch (const std::exception& ex) {
		std::cout << ex.what() << std::endl;
	}
	return 0;
}