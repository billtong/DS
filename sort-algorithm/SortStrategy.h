#pragma once

class SortStrategy
{
public:
	virtual ~SortStrategy() {}
	virtual void exec(int *arr, const int size) = 0;
};
