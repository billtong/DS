#pragma once

#define PRINT_2D_ARRAY(ptr, m, n)          \
    std::cout << "2d array:" << std::endl; \
    for (int i = 0; i < m; i++)            \
    {                                      \
        for (int j = 0; j < n; j++)        \
        {                                  \
            std::cout << ptr[i][j] << " "; \
        }                                  \
        std::cout << std::endl;            \
    }                                      \
    std::cout << "2d array ends" << std::endl;

#define PRINT_1D_ARRAY(ptr, n)      \
    for (int i = 0; i < n; i++)     \
    {                               \
        std::cout << ptr[i] << " "; \
    }                               \
    std::cout << std::endl;

namespace my_util
{
	inline int find_max(int num1, int num2)
	{
		return num1 > num2 ? num1 : num2;
	}

	inline int find_min(int num1, int num2)
	{
		return num1 < num2 ? num1 : num2;
	}

	void swap(int& a, int& b);
}
