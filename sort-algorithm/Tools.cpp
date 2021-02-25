#include "Tools.h"
#include <iostream>

void Tools::swap(int &a, int &b)
{
	int temp = a;
	a = b;
	b = temp;
}

void Tools::print_array(int *arr, int size)
{
	for (int i = 0; i < size; i++)
	{
		std::cout << arr[i] << " ";
	}
	std::cout << std::endl;
}
