#include "BubbleSort.h"
#include "Tools.h"

/*
Bubble Sort
begin From the first element, compare it with the next element
make sure the larger one moves toward the back
until we find the largest one and put it at the last position
we loop this procedure n-1 times.
*/
void BubbleSort::exec(int* arr, const int size)
{
	for (int i = size - 1; i > 0; i--)
	{
		for (int j = 0; j < i; j++)
		{
			if (arr[j] > arr[j + 1])
				Tools::swap(arr[j], arr[j + 1]);
		}
	}
}
