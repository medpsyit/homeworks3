#include <iostream>
#include <exception> 

template <class T>
class TestVector {
public:
	TestVector()
	{
		data = nullptr;
		_size = 0;
		_capacity = 0;
	}
	TestVector(size_t count)
	{
		data = new T[count];
		_size = count;
		_capacity = 0;
		for (int i = 0; i < count; i++)
		{
			data[i] = T{};
		}
	}
	~TestVector() {
		if (data)
		{
			delete[] data;
		};
	}
	T& at(size_t index) { 
		if (index < _size) {
			return data[index];
		}
		else throw std::out_of_range("incorrect index!");
	}
	void push_back(const T& elem) 
	{
		if (!data) 
		{
			data = new T[1];
			_capacity = 1;
		}
		if (_size == _capacity)
		{
			T* temp = new T[_capacity * 2];
			for (int i = 0; i < _size; i++)
			{
				temp[i] = data[i];
			}
			if (data) { delete[] data; }
			data = temp;
			_capacity *= 2;
		}
		data[_size] = elem;
		_size++;
	}
	size_t size() const { return _size; }
	size_t capacity() const { return _capacity; }
private:
	T* data;
	size_t _size;
	size_t _capacity;
};

int main() {
	TestVector<int> vec;
	std::cout << "CREATE VECTOR" << std::endl;
	std::cout << "SIZE: " << vec.size() << "\nCAPACITY: " << vec.capacity() << std::endl;
	std::cout << "ADD 8 ELEMENTS" << std::endl;
	for (int i = 0; i < 8; i++)
	{
		vec.push_back(i * i);
	}
	std::cout << "SIZE: " << vec.size() << "\nCAPACITY: " << vec.capacity() << std::endl;
	std::cout << "ADD 9th ELEMENT = 100" << std::endl;
	vec.push_back(100);
	std::cout << "SIZE: " << vec.size() << "\nCAPACITY: " << vec.capacity() << std::endl;
	std::cout << "ALL ELEMENTS: " << std::endl;
	try
	{
		for (int i = 0; i < vec.size(); i++)
		{
			std::cout << "INDEX " << i << ": " << vec.at(i) << std::endl;
		}
		std::cout << "INDEX " << 10 << ": " << vec.at(10) << std::endl;
	}
	catch (std::out_of_range& ex) { std::cout << ex.what() << std::endl; }
	return 0;
}
