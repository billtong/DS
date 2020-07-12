#pragma once
#include "SortStrategy.h"

class BubbleSort :
	public SortStrategy
{
public:
	void exec(int* arr, const int size);
};

