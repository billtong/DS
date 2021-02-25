#include "SortContext.h"

SortContext::SortContext(SortStrategy *strategy)
		: _sort_strategy(strategy)
{
}

void SortContext::set_sort_stragetegy(SortStrategy *stragety)
{
	_sort_strategy = stragety;
}

void SortContext::exec(int *arr, int size)
{
	_sort_strategy->exec(arr, size);
}
