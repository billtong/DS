#pragma once
#include "SortStrategy.h"

class SortContext
{
public:
	explicit SortContext(SortStrategy* strategy);
	void set_sort_stragetegy(SortStrategy* stragety);
	void exec(int* arr, int size);
private:
	SortStrategy* _sort_strategy;
};

