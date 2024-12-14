#include <iostream>
//using namespace std; - лучше использовать std::, но используя пространство имен, надо было бы убрать std у cout и endl

struct point {
	double m_x;
	double m_y;
	point(double x, double y) {
		m_x = x;
		m_y = y; // "у" вместо "m_y"
	}
}; // пропуск точки с запятой

void print_point(const point& point_object); // функция имела реализацию дважды

int main() //Main было с большой буквы, что выдавало ошибку - ссылка на неразрешенный внешний символ (не нашел main-функцию)
{
	int i{}; //инициализация
	for (i = 0; i < 5; i++)
	{
		point my_point(i, 2 * i);
		print_point(my_point);
	}
	return 0;
}

void print_point(const point& point_object) {
	std::cout << "x:" << point_object.m_x << ", y: "
		<< point_object.m_y << std::endl;
}